#pragma once

#include "Product.hpp"

struct QueryResult
{
    QueryResult() = default;
    QueryResult(const Product* prod, double score): prod(prod), score(score){}
    ~QueryResult() = default;

    const Product *prod;
    double score;

    bool operator > (const QueryResult& rhs) const
    {
        return score > rhs.score;
    }
};
