#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <nlohmann/json.hpp>
#include <readline/readline.h>
#include <readline/history.h>

#include "InvertedIndex.hpp"
#include "Product.hpp"
#include "ProductList.hpp"

using json = nlohmann::json;

int main()
{

    std::cout << "Loading data..." << std::endl;
    ProductList prodList;
    auto start = std::chrono::system_clock::now();
    try
    {

        std::ifstream file("../data/catalogo_produtos.json");

        if (file.fail())
        {
            std::cerr << "Error opening file" << std::endl;
            return 1;
        }
        std::string line;
        while (std::getline(file, line))
        {
            auto data = json::parse(line);
            auto p = Product(data["id"], data["name"]);
            prodList.add(p);
        }
        file.close();
    }
    catch (...)
    {
        std::cerr << "Error loading data..." << std::endl;
        return 1;
    }
    auto end = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Finished data loading in: " << duration << "ms" << std::endl;

    // do query
    const char* input;
    while ((input = readline("> Digite aqui sua consulta: ")) != nullptr) {
        if (*input) add_history(input);

        std::string query(input);

        start = std::chrono::system_clock::now();
        auto queryResult = prodList.query(query);
        end = std::chrono::system_clock::now();

        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        int i=1;
        for(auto const& r: queryResult){
            std::cout << "#" << i << " - \"" << r.prod->id << "\" - \"" << r.prod->name << "\"" << std::endl;
            i++;
        }
        std::cout << "Query done in: " << duration << "ms\n" << std::endl;
        free((void *) input);
    }
    return 0;
}

