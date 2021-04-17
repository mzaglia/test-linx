#pragma once

#include <unordered_map>
#include <vector>
#include <string>

/**
 * @brief Simple Inverted Index implementation.
 *
 */
class InvertedIndex
{
public:
    InvertedIndex() = default;
    ~InvertedIndex() = default;

    /**
     * @brief Add a word occurrence mapped to a product index.
     *
     * @param str Word to be mapped.
     * @param productIdx Product index.
     */
    void add(const std::string &str, const int productIdx);

    /**
     * @brief Get a pointer to the vector of product indexes where the given word occurs.
     * If there is no matching word a nullptr is returned.
     *
     * @param str Word to be searched.
     * @return std::vector<int>* vector of int containing product indexes or nullptr.
     */
    std::vector<int> *get(const std::string &str);

private:
    std::unordered_map<std::string, std::vector<int>> index;
};
