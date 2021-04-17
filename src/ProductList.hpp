#pragma once

#include <string>
#include <set>
#include <vector>

#include "Product.hpp"
#include "QueryResult.hpp"

class InvertedIndex;

class ProductList
{
public:

    ProductList();
    ~ProductList() = default;

    /**
     * @brief Add a product to the list
     *
     * @param prod Product to be added.
     */
    void add(Product &prod);

    /**
     * @brief Search for products best matched with the given query by using Sorensen-Dice score.
     *
     * @param str Query to be searched.
     * @return std::vector<QueryResult> Vector of highest scoring products ordered by Id.
     */
    std::vector<QueryResult> query(const std::string &str);



private:
    InvertedIndex invertedIndex;
    std::vector<Product> productList;
    std::set<std::string> stopWords;
};
