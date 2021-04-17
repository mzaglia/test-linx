#pragma once

#include "Product.hpp"

/**
 * @brief Struct for mapping query results products and its score.
 *
 */
struct QueryResult
{
    QueryResult() = default;
    /**
     * @brief Construct a new Query Result object
     *
     * @param prod Product object.
     * @param score Score of the product.
     */
    QueryResult(const Product* prod, double score): prod(prod), score(score){}
    ~QueryResult() = default;

    const Product *prod;
    double score;
};
