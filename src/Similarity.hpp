#pragma once

#include <string>
#include <unordered_set>
#include <boost/algorithm/string.hpp>


/**
 * @brief Similarity based in Sørensen–Dice index.
 *
 * @param _str1 First string.
 * @param _str2 Second string.
 * @return double Similarity score between _str1 and _str2.
 */
double sorensenDice(const std::string& _str1, const std::string& _str2) {
    // Base case: if some string is empty.
    if (_str1.empty() || _str2.empty()) {
        return 1.0;
    }

    auto str1 = boost::to_lower_copy(_str1);
    auto str2 = boost::to_lower_copy(_str2);

    // Base case: if the strings are equals.
    if (str1 == str2) {
        return 0.0;
    }

    // Base case: if some string does not have bigrams.
    if (str1.size() < 2 || str2.size() < 2) {
        return 0.0;
    }

    // Extract bigrams from str1
    auto num_pairs1 = str1.size() - 1;
    std::unordered_set<std::string> str1_bigrams;
    str1_bigrams.reserve(num_pairs1);
    for (unsigned i = 0; i < num_pairs1; ++i) {
        str1_bigrams.insert(str1.substr(i, 2));
    }

    // Extract bigrams from str2
    auto num_pairs2 = str2.size() - 1;
    std::unordered_set<std::string> str2_bigrams;
    str2_bigrams.reserve(num_pairs2);
    for (unsigned int i = 0; i < num_pairs2; ++i) {
        str2_bigrams.insert(str2.substr(i, 2));
    }

    // Find the intersection between the two sets.
    int intersection = 0;
    if (str1_bigrams.size() < str2_bigrams.size()) {
        const auto it_e = str2_bigrams.end();
        for (const auto& bigram : str1_bigrams) {
            intersection += str2_bigrams.find(bigram) != it_e;
        }
    } else {
        const auto it_e = str1_bigrams.end();
        for (const auto& bigram : str2_bigrams) {
            intersection += str1_bigrams.find(bigram) != it_e;
        }
    }

    // Returns similarity coefficient.
    return (2.0 * intersection) / (num_pairs1 + num_pairs2);
}
