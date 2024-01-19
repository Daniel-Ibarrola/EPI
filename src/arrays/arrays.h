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

    template <typename data_type>
    std::vector<data_type> removeDuplicates(const std::vector<data_type>& array){
        std::vector<data_type> result;

        if (!array.empty()){
            result.push_back(array[0]);
        }

        for (auto ii {1}; ii < array.size(); ++ii){
            if (array[ii - 1] != array[ii])
                result.push_back(array[ii]);
        }
        return result;
    }

    template <typename data_type>
    int numDuplicates(std::vector<data_type>& array){
       if (array.empty())
           return 0;

       std::size_t writeIndex {1};
       for (auto ii {1}; ii < array.size(); ++ii){
           if (array[writeIndex - 1] != array[ii]){
               array[writeIndex] = array[ii];
               ++writeIndex;
           }
       }
       return static_cast<int>(array.size() - writeIndex);
    }

    std::vector<int> padWithZeros(const std::vector<int>& vec, std::size_t finalSize);

    std::vector<int> addIntegers(const std::vector<int>& num1, const std::vector<int>& num2);

    std::vector<int> incrementInteger(const std::vector<int>& number);

    std::vector<int> multiplyIntegers(const std::vector<int>& number, const std::vector<int>& multiplier);

    int maxProfit(const std::vector<int>& array);
}

#endif //INTERVIEWPREP_ARRAYS_H
