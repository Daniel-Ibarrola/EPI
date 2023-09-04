//
// Created by daniel on 4/09/23.
//

#ifndef INTERVIEWPREP_SORTING_H
#define INTERVIEWPREP_SORTING_H

#include <vector>

namespace epi {

    template<typename data_type>
    void merge(std::vector<data_type>& array,
               int left,
               int mid,
               int right
               ){
        std::vector<data_type> leftArr;
        std::vector<data_type> rightArr;

        for (auto ii {left}; ii < mid + 1;  ++ii){
            leftArr.push_back(array[ii]);
        }
        for (auto ii {mid + 1}; ii < right + 1;  ++ii){
            rightArr.push_back(array[ii]);
        }

        int lf {0};
        int rg {0};
        int ii {left}; // Pointer to the original array

        while (lf < leftArr.size() && rg < rightArr.size()){
            if (leftArr[lf] <= rightArr[rg]){
                array[ii] = leftArr[lf];
                ++lf;
            } else {
                array[ii] = rightArr[rg];
                ++rg;
            }
            ++ii;
        }

        // Copy remaining elements
        while (lf < leftArr.size()){
            array[ii] = leftArr[lf];
            ++lf;
            ++ii;
        }

        while (rg < rightArr.size()){
            array[ii] = rightArr[rg];
            ++rg;
            ++ii;
        }
    }

    template<typename data_type>
    void mergeSortHelper(std::vector<data_type>& array,
                         int left,
                         int right
                         ){
        if (left < right){
            int mid {left + (right - left) / 2};
            mergeSortHelper(array, left, mid);
            mergeSortHelper(array, mid + 1, right);
            merge(array, left, mid, right);
        }
    }

    template<typename data_type>
    void mergeSort(std::vector<data_type>& array){
        if (array.empty())
            return;
        mergeSortHelper(array, 0, array.size() - 1);
    }

    template<typename data_type>
    void quickSort(std::vector<data_type> array){

    }

}

#endif //INTERVIEWPREP_SORTING_H
