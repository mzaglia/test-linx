#pragma once

#include <unordered_map>
#include <vector>
#include <string>

class InvertedIndex
{
public:
    InvertedIndex() = default;
    ~InvertedIndex() = default;
    void add(const std::string &str, const int productIdx);
    std::vector<int> *get(const std::string &str);

private:
    std::unordered_map<std::string, std::vector<int>> index;
};
