//
// Created by DanielIbarrola on 1/15/2024.
//

#include "arrays.h"


void epi::incrementInteger(std::vector<int> &number) {

    for (auto ii {number.size() -1}; ii >= 0; --ii){
        int digit = number[ii] + 1;
        if (digit > 9){
            number[ii] = 0;
            if (ii > 0){
                --number[ii - 1];
            } else {
                number.insert(number.begin(), 1);
            }

        } else {
            number[ii] = digit;
        }

        if (ii == 0) break;
    }

}