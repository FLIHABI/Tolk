#include "ressource/ressource.hh"

void ressource::RessourceManager::load_file(const std::string& filename)
{
  tolk_file_ = tolk::TolkFile::load(filename);
}
