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


bool itp::canWriteLetter(
        const std::string& magazine,
        const std::string& letter
){
    /// Checks if the letter string can be built from the magazine string
    std::unordered_map<char, unsigned int> magazineCount;
    for (auto ch : magazine){
        unsigned char character{static_cast<unsigned char>(ch)};

        if (std::isalpha(character)){
            char lower {static_cast<char>(std::tolower(character))};

            if (magazineCount.count(lower) == 0)
                magazineCount[lower] = 1;
            else
                ++magazineCount[lower];
        }
    }

    for (auto ch: letter){
        unsigned char character{static_cast<unsigned char>(ch)};

        if (std::isalpha(character)){
            char lower {static_cast<char>(std::tolower(character))};

            if (magazineCount.count(lower) == 0 ||
                magazineCount[lower] == 0
            )
                return false;

            --magazineCount[lower];
        }
    }
    return true;
}