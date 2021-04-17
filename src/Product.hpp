#pragma once
#include <string>

/**
 * @brief Product mapping.
 *
 */
struct Product
{

    std::string id;
    std::string name;

    /**
     * @brief Product index in a ProductList
     *
     */
    int idx;

    /**
     * @brief Construct a new Product object
     *
     * @param id Product identifier.
     * @param name Product Name.
     */
    Product(const std::string &id, const std::string &name) : id(id), name(name) {}
    ~Product() = default;
};
