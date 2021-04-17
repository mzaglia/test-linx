#pragma once

#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>

#include <string>
#include <vector>

/**
 * @brief Tokenize a string by removing all punctuation, transforming to lower case
 *  and splitting by spaces.
 *
 * @param str String to be tokenized
 * @return std::vector<std::string> Vector of tokenized strings.
 */
std::vector<std::string> static tokenize(const std::string &str)
{
    std::vector<std::string> tokens;

    boost::tokenizer<> tok(str);
    for (auto beg : tok)
    {
        tokens.push_back(boost::algorithm::to_lower_copy(beg));
    }

    return tokens;
};

/**
 * @brief Count the number of common tokens beetween two strings.
 *
 * @param tokens1 First string.
 * @param tokens2 Second string.
 * @return int Number of common tokens.
 */
int numCommonTokens(std::vector<std::string> &tokens1, std::vector<std::string> &tokens2)
{
    std::sort(tokens1.begin(), tokens1.end());
    std::sort(tokens2.begin(), tokens2.end());
    int matches = 0;
    for (int i = 0, j = 0; i < tokens1.size() && j < tokens2.size();)
    {
        if (tokens1[i] == tokens2[j])
        {
            matches++;
            i++;
            j++;
        }
        else if (tokens1[i] < tokens2[j])
        {
            i++;
        }
        else
            j++;
    }
    return matches;
}
