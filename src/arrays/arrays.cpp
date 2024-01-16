//
// Created by DanielIbarrola on 1/15/2024.
//

#include "arrays.h"


std::vector<int> epi::incrementInteger(std::vector<int> number) {
    if (number.empty())
        return number;

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

    return number;
}

std::vector<int> epi::multiplyIntegers(const std::vector<int> &number, const std::vector<int> &multiplier) {
    //    1 4 2
    //  x 2 3 5
    //    -----
    //    7 1 0
    //  4 2 6
    //2 8 4
    //----------
    //3 3 3 7 0

    if (number.empty() || multiplier.empty())
        return {};

    std::size_t maxDigits {number.size() + multiplier.size()};
    std::vector<std::vector<int>> multiplications(
            multiplier.size(), std::vector<int>(maxDigits, 0));

    // Multiply each digit of the multiplier by the number and store the results
    int residue {0};
    std::size_t offset {0};
    std::size_t row {0};
    for (auto m_it {multiplier.rbegin()}; m_it != multiplier.rend(); ++m_it){
        auto r_it {multiplications[row].rbegin()};
        std::advance(r_it, offset);
        for (auto n_it {number.rbegin()}; n_it != number.rend(); ++n_it){
            int product {*m_it * *n_it};
            product += residue;
            residue = product / 10;
            int newDigit {product % 10};

            *r_it = newDigit;
            ++r_it;
        }
        ++offset;
        ++row;
    }

    if (residue > 0){
        multiplications.back().front() = residue;
    }

    // Sum the multiplications of each digit to get the result
    std::vector<int> result (maxDigits, 0);
    auto r_it {result.rbegin()};
    residue = 0;

    if (!multiplications.empty()) {
        for (int col {static_cast<int>(multiplications[0].size() - 1)}; col >= 0; --col){
            int columnSum {residue};
            for (auto rowInd {0}; row < multiplications.size(); ++rowInd){
                columnSum += multiplications[rowInd][static_cast<std::size_t>(col)];
            }
            residue = columnSum / 10;
            int newDigit {columnSum % 10};

            *r_it = newDigit;
            ++r_it;
        }
    }

    return result;
}


//    1 4 2
//  x   9 2
//    -----
//    2 8 4
//1 2 7 8
//----------
//1 3 0 6 4


// X X 2 8 4
// 1 2 6 8 X
