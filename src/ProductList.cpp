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
        auto score = sorensenDice(str, p->name) * numCommonTokens(tokens, prodTokens);

        results.push_back(QueryResult(p, score));
    }
    std::sort(results.begin(), results.end(), std::greater<>());
    results.resize(results.size() > 20 ? 20 : results.size());

    return results;
}
