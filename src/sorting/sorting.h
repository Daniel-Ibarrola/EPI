//
// Created by daniel on 4/09/23.
//

#ifndef INTERVIEWPREP_SORTING_H
#define INTERVIEWPREP_SORTING_H

#include <vector>

namespace epi {

    template<typename data_type>
    void merge(std::vector<data_type>& array,
               std::size_t left,
               std::size_t mid,
               std::size_t right
               ){
        std::vector<data_type> leftArr(mid - left + 1);
        std::vector<data_type> rightArr(right - mid);

        for (auto ii {0}; ii < leftArr.size();  ++ii){
            leftArr[ii] = array[left + ii];
        }
        for (auto ii {0}; ii < rightArr.size();  ++ii){
            rightArr[ii] = array[mid + ii + 1];
        }

        std::size_t lf {0};
        std::size_t rg {0};
        std::size_t ii {left}; // Pointer to the original array

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
                         std::size_t left,
                         std::size_t right
                         ){
        if (left < right){
            std::size_t mid {left + (right - left) / 2};
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
    int partition(std::vector<data_type>& array, int left, int pivot){
        std::size_t ii {static_cast<std::size_t>(left)};
        for (auto jj {left}; jj < pivot; ++jj){
            if (array[jj] < array[pivot]){
                std::swap(array[ii], array[jj]);
                ++ii;
            }
        }
        std::swap(array[ii], array[pivot]);
        return static_cast<int>(ii);
    }

    template<typename data_type>
    void quickSortHelper(std::vector<data_type>& array,
                         int left,
                         int right
                         ){
        if (left < right){
            int pivot {partition(array, left, right)};
            quickSortHelper(array, left, pivot - 1);
            quickSortHelper(array, pivot + 1, right);
        }
    }

    template<typename data_type>
    void quickSort(std::vector<data_type>& array){
        if (array.empty())
            return;
        quickSortHelper(array, 0,  array.size() - 1);
    }

}

#endif //INTERVIEWPREP_SORTING_H
