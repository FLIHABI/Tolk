#include "ressource/ressource.hh"

ressource::RessourceManager::~RessourceManager()
{
  for (auto& entry : objects_)
    delete entry.second;
}

bool ressource::RessourceManager::load_file(const std::string& filename)
{
  return ((tolk_file_ = tolk::TolkFile::load(filename)) != nullptr);
}
