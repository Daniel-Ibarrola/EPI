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
    if (number.empty() || multiplier.empty())
        return {};

    bool isNegative {number.front() < 0 || multiplier.front() < 0};

    std::size_t maxDigits {number.size() + multiplier.size()};
    std::vector<int> currentSum {0};

    int residue {0};
    std::size_t offset {0};
    for (auto m_it {multiplier.rbegin()}; m_it != multiplier.rend(); ++m_it){

        std::vector<int> currentProd(maxDigits);
        auto r_it {currentProd.rbegin()};
        std::advance(r_it, offset);

        for (auto n_it {number.rbegin()}; n_it != number.rend(); ++n_it){
            int product {std::abs(*m_it * *n_it)};
            product += residue;
            residue = product / 10;
            int newDigit {product % 10};

            *r_it = newDigit;
            ++r_it;
        }

        if (residue){
            *r_it = residue;
            residue = 0;
        }

        currentSum = addIntegers(currentProd, currentSum);

        ++offset;
    }

    if (isNegative){
        currentSum.front() *= -1;
    }

    if (currentSum.front() == 0){
        currentSum.erase(currentSum.begin());
    }

    return currentSum;
}


int epi::maxProfit(const std::vector<int> &array) {
    //    {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    //
    //  Buy 260, Sell 290
    int currentMax {0};
    for (auto ii {0}; ii < array.size(); ++ii){
        for (auto jj {ii + 1}; jj < array.size(); ++jj){
            int diff {array[jj] - array[ii]};
            if (diff > currentMax){
                currentMax = diff;
            }
        }
    }
    return currentMax;
}
