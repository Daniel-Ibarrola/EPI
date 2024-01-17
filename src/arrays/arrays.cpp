//
// Created by DanielIbarrola on 1/15/2024.
//

#include "arrays.h"

std::vector<int> epi::padWithZeros(const std::vector<int> &vec, std::size_t finalSize) {
    // Pad a vector with zeros to the left
    if (vec.size() >= finalSize)
        return vec;

    std::vector<int> result(finalSize, 0);
    std::size_t start {finalSize - vec.size()};
    std::copy(vec.begin(), vec.end(), result.begin() + static_cast<int>(start));
    return result;
}


std::vector<int> epi::addIntegers(const std::vector<int> &num1, const std::vector<int> &num2) {

    if (num1.empty() || num2.empty())
        return {};

    std::vector<int>smallerNum;
    const std::vector<int>* largerNum;
    std::size_t digits;

    if (num1.size() < num2.size()){
        largerNum = &num2;
        digits = num2.size();
        smallerNum = padWithZeros(num1, digits);
    } else {
        largerNum = &num1;
        digits = num1.size();
        smallerNum = padWithZeros(num2, digits);
    }

    std::vector<int> result(digits, 0);

    int residue {0};
    auto lg_it {largerNum->rbegin()};
    auto r_it {result.rbegin()};
    for (auto sm_it {smallerNum.rbegin()}; sm_it != smallerNum.rend(); ++sm_it){
        int sum {*sm_it + *lg_it + residue};
        int newDigit {sum % 10};
        residue = sum / 10;

        *r_it = newDigit;

        ++r_it;
        ++lg_it;
    }

    if (residue != 0){
        result.insert(result.begin(), residue);
    }

    return result;
}


std::vector<int> epi::incrementInteger(const std::vector<int>& number) {
    return addIntegers(number, {1});
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
