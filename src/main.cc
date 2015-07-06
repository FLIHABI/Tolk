#include <iostream>
#include <stdexcept>

#include "cpu/base_cpu.hh"
#include "loader.hh"
#include "environment.hh"
#include "ressource/ressource.hh"
#include "service.hh"
#include "slave.hh"
#include "args_parser.hh"
#include "timer.hh"
#include "printer.hh"

void print_usage(char* bin_name)
{
    std::cerr << "Usage: " << bin_name << " <tolk file>"
        << " ([-s|--server] | [-c|--client])"
        << std::endl;
}

int main(int argc, char* argv[])
{
    args_datas args;

    try
    {
        args = parse_args(argc, argv);

        if (args.mode == network::SERVER && args.filename.empty())
            throw std::invalid_argument("Filename is required in server mode");
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        print_usage(argv[0]);
        return 1;
    }

    interpreter::OpcodeManager opm;
    network::Service net_svc(args.mode);
    ressource::RessourceManager rm(net_svc);
    for (auto& lib : args.libs)
        rm.dyngot_get().add_library(lib.c_str());

    Loader::get_instance().init_handlers_manager(opm);

    if (!rm.load_file(args.filename))
    {
        std::cerr << "Cannot open file '" << args.filename << "'" << std::endl;
        return 1;
    }

    if (args.mode != network::SERVER)
        print_red();
    net_svc.start();
    //TODO: read gen_reg from file
    if (args.mode == network::SERVER)
    {

        cpu::BaseCPU cpu(4096, rm.get_bytecode(), rm.get_entry_point(), opm);
        Environment env(cpu, rm);

        double s = 0;
        {
            scoped_timer timer(s);
            env.run();
        }
        std::cout << "Execution time: " << s << " (seconds)" << std::endl;
    }
    else
    {
        while (1)
        {
            print_blue();
            std::string bytecode = net_svc.get_task();
            print_green();
            if (bytecode.size() == 0)
            {
                net_svc.stop();
                return 0;
            }
            std::vector<uint64_t> result(bytecode.size() / 8);
            std::copy((uint64_t*)&bytecode[0], ((uint64_t*)&bytecode[0]) + bytecode.size() / 8, &result[0]);
            auto p = rm.deserialize_call(result);
            cpu::BaseCPU cpu(4096,
                    rm.get_bytecode(),
                    rm.get_tolk_file()->get_functable().get(p.first).offset,
                    opm);
            Environment env(cpu, rm);
            for (unsigned i = 0; i < p.second.size(); i++)
            {
                env.stack_push(p.second[i]);
            }
            double s = 0;
            {
                scoped_timer timer(s);
                env.run();
            }
            std::cout << "Execution time: " << s << " (seconds)" << std::endl;
            uint64_t ret = env.cpu.regs.greg[0];
            result = rm.serialize_return(p.first, ret);
            bytecode = std::string((char*)&result[0], result.size() * 8);
            print_yellow();
            net_svc.submit_task_result(bytecode);
        }
    }
    net_svc.stop();
    return 0;
}
