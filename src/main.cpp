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
    ProductList prodList;

    try
    {
        // open data file.
        std::ifstream file("data/catalogo_produtos.json");

        // if the file fails to open show error message and exits.
        if (file.fail())
        {
            std::cerr << "Erro ao abrir 'data/catalogo_produtos.json'" << std::endl;
            return 1;
        }

        // iterate through the data file and parse the date to a Product.
        std::string line;
        while (std::getline(file, line))
        {
            auto data = json::parse(line);
            auto p = Product(data["id"], data["name"]);
            prodList.add(p);
        }
        file.close();
    }
    catch(json::parse_error &e)
    {
        // if an error while parsing the json document occurs show error message and exits.
        std::cerr << "Erro ao realizar o parse do arquivo JSON." << std::endl;
        return 1;
    }
    catch (...)
    {
        // if any exception occurs show error message and exits.
        std::cerr << "Erro ao carregar o arquivo!" << std::endl;
        return 1;
    }

    // start queries
    std::cout << "Bem vindo ao processador de consultas! (Para sair digite /sair)" << std::endl;

    const char *input;
    while ((input = readline("> Digite aqui sua consulta: ")) != nullptr)
    {
        if (*input)
            add_history(input);

        std::string query(input);

        if (query == "/sair")
            break;

        // process query and calculate time spent
        auto start = std::chrono::system_clock::now();
        auto queryResult = prodList.query(query);
        auto end = std::chrono::system_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        int i = 1;

        // display results
        for (auto const &r : queryResult)
        {
            std::cout << "#" << i << " - \"" << r.prod->id << "\" - \"" << r.prod->name << "\"" << std::endl;
            i++;
        }

        std::cout << "Consulta concluída em: " << duration << "ms\n"
                  << std::endl;

        free((void *)input);
    }

    return 0;
}
