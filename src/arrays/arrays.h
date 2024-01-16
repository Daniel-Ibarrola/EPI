//
// Created by DanielIbarrola on 1/15/2024.
//

#ifndef INTERVIEWPREP_ARRAYS_H
#define INTERVIEWPREP_ARRAYS_H

#include <iterator>
#include <vector>

namespace epi {

    template <typename data_type>
    void dutchFlagPartition(std::vector<data_type>& array, std::size_t pivot){

        data_type pivotValue {array[pivot]};

        std::size_t smaller {0};
        for (auto ii {0}; ii < array.size(); ++ii){
            if (array[ii] < pivotValue){
                std::swap(array[ii], array[smaller]);
                ++smaller;
            }
        }

        std::size_t larger {array.size() - 1};
        for (auto ii {array.size() - 1}; ii >= 0; --ii){
            if (array[ii] > pivotValue){
                std::swap(array[ii], array[larger]);
                --larger;
            }
            if (ii == 0) break;
        }
    }

    std::vector<int> incrementInteger(std::vector<int> number);

    std::vector<int> multiplyIntegers(const std::vector<int>& number, const std::vector<int>& multiplier);
}

#endif //INTERVIEWPREP_ARRAYS_H
