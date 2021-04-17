#include "InvertedIndex.hpp"

void InvertedIndex::add(const std::string &str, const int productIdx)
{
    // inserts in which product word occurs
    this->index[str].push_back(productIdx);
}

std::vector<int> *InvertedIndex::get(const std::string &str)
{
    if(this->index.find(str) != this->index.end())
        return &this->index[str];

    return nullptr;
}
