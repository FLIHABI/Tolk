#include "ressource/ressource.hh"

bool ressource::RessourceManager::load_file(const std::string& filename)
{
  return ((tolk_file_ = tolk::TolkFile::load(filename)) != nullptr);
}
