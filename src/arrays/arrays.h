//
// Created by DanielIbarrola on 1/15/2024.
//

#ifndef INTERVIEWPREP_ARRAYS_H
#define INTERVIEWPREP_ARRAYS_H

#include <vector>

namespace epi {

    template <typename data_type>
    void dutchFlagPartition(std::vector<data_type>& array, std::size_t pivot){

        data_type pivotValue {array[pivot]};
        std::vector<data_type> less {};
        std::vector<data_type> equal {};
        std::vector<data_type> greater {};

        for (auto num : array){
            if (num < pivotValue){
                less.push_back(num);
            } else if (num == pivotValue) {
                equal.push_back(num);
            } else {
                greater.push_back(num);
            }
        }

        std::size_t current {0};
        for (auto ii {0}; ii < less.size(); ++ii){
            array[current] = less[ii];
            ++current;
        }

        for (auto ii {0}; ii < equal.size(); ++ii){
            array[current] = equal[ii];
            ++current;
        }

        for (auto ii {0}; ii < greater.size(); ++ii){
            array[current] = greater[ii];
            ++current;
        }

    }

}

#endif //INTERVIEWPREP_ARRAYS_H
