#pragma once
#include <string>

struct Product
{
    std::string id;
    std::string name;
    int idx;
    Product(const std::string &id, const std::string &name) : id(id), name(name) {}
    ~Product() = default;
};
