//
// Created by daniel on 1/09/23.
//

#include "hashtable.h"

bool itp::canFormPalindrome(const std::string& str){
    /// Checks if the given string can be permuted into a palindrome
    std::unordered_map<char, unsigned int> charCount;
    for (auto ch : str){
        if (charCount.count(ch) == 0)
            charCount[ch] = 1;
        else
            ++charCount[ch];
    }

    int unevenCount {0};
    for (const auto& [ch, count] : charCount){
        if (count % 2 != 0)
            ++unevenCount;
    }
    return unevenCount <= 1;
}
