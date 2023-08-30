//
// Created by daniel on 30/08/23.
//

#ifndef INTERVIEWPREP_SEARCH_H
#define INTERVIEWPREP_SEARCH_H

#include <vector>

template <typename data_type>
int binarySearch(const std::vector<data_type>& array, data_type element){
    if (array.empty())
        return -1;

    std::size_t left {0};
    std::size_t right {array.size() - 1};

    while (left <= right) {
        std::size_t mid {left + (right - left) / 2};
        data_type midElement {array[mid]};
        if (midElement == element)
            return static_cast<int>(mid);
        else if (midElement < element)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

#endif //INTERVIEWPREP_SEARCH_H
