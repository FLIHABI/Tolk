#include "ressource/ressource.hh"

ressource::RessourceManager::~RessourceManager()
{
  for (auto& entry : objects_)
    delete entry.second;
}

void ressource::RessourceManager::load_file(const std::string& filename)
{
  tolk_file_ = tolk::TolkFile::load(filename);
}
