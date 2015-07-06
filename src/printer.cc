#include <iostream>
#include "printer.hh"

void print_red()
{
    std::cout << "\e[1;41m\n";
    for (int i = 0; i < 50; ++i)
        std::cout << "\n";
    std::cout << std::endl;
}

void print_blue()
{
    std::cout << "\e[1;44m\n";
    for (int i = 0; i < 50; ++i)
        std::cout << "\n";
    std::cout << std::endl;
}

void print_green()
{
    std::cout << "\e[1;42m\n";
    for (int i = 0; i < 50; ++i)
        std::cout << "\n";
    std::cout << std::endl;
}

void print_yellow()
{
    std::cout << "\e[1;43m\n";
    for (int i = 0; i < 50; ++i)
        std::cout << "\n";
    std::cout << std::endl;
}
