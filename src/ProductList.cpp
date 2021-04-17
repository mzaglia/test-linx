#include "InvertedIndex.hpp"
#include "ProductList.hpp"
#include "QueryResult.hpp"
#include "Similarity.hpp"
#include "Utils.hpp"
#include <set>

void ProductList::add(Product &prod)
{
    prod.idx = this->productList.size();
    this->productList.push_back(prod);
    auto tokens = tokenize(prod.name);

    for (auto token : tokens)
    {
        this->invertedIndex.add(token, prod.idx);
    }
};

std::vector<QueryResult> ProductList::query(const std::string &str)
{
    std::set<const Product *> result;
    auto tokens = tokenize(str);

    // search for the products that have the same tokens as the query.
    for (auto token : tokens)
    {
        auto idx = this->invertedIndex.get(token);

        if (!idx)
            continue;

        for (auto i : *idx)
        {
            result.insert(&this->productList[i]);
        }
    }

    std::vector<QueryResult> results;
    for (auto p : result)
    {
        auto prodTokens = tokenize(p->name);

        // perform Sørensen–Dice to compare query and product name.
        // add weight to score according to the number of common tokens between query and product name.
        auto score = sorensenDice(str, p->name) * numCommonTokens(tokens, prodTokens);

        results.push_back(QueryResult(p, score));
    }
    // sort by the best score
    std::sort(results.begin(), results.end(), [](const QueryResult &a, const QueryResult &b) {
        return a.score > b.score;
    });

    // resize results if there are more then 20
    if (result.size() > 20)
        results.resize(20);

    //sort again by id
    std::sort(results.begin(), results.end(), [](const QueryResult &a, const QueryResult &b) {
        return a.prod->id < b.prod->id;
    });
    return results;
}
