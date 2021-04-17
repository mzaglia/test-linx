#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include "Product.hpp"
#include "QueryResult.hpp"

class InvertedIndex;

class ProductList
{
public:

    ProductList() = default;
    ~ProductList() = default;

    void add(Product &prod);
    std::vector<QueryResult>  query(const std::string &str);

private:
    std::vector<std::string> checkSpelling(const std::vector<std::string>& vec);

private:
    InvertedIndex invertedIndex;
    std::vector<Product> productList;
};
