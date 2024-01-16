//
// Created by DanielIbarrola on 1/15/2024.
//

#include "arrays.h"


void epi::incrementInteger(std::vector<int> &number) {
    if (number.empty())
        return;

    ++number.back();
    for (auto ii {number.size() -1}; number[ii] > 9; --ii){
        number[ii] = 0;
        ++number[ii - 1];
        if (ii == 0)
            break;
    }
    if (number.front() == 0){
        number.emplace_back(0);
        number.front() = 1;
    }
}