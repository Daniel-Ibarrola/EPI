//
// Created by DanielIbarrola on 1/15/2024.
//
#include "arrays.h"
#include "gtest/gtest.h"


TEST(DutchFlagPartition, Test1)
{
    std::vector<int> array {0, 1, 2, 0, 2, 1, 1};
    std::size_t pivot {3};

    epi::dutchFlagPartition(array, pivot);

    std::vector<int> expected {0, 0, 1, 2, 2, 1, 1};
    ASSERT_EQ(array, expected);
}


TEST(DutchFlagPartition, Test2)
{
    std::vector<int> array {0, 1, 2, 0, 2, 1, 1};
    std::size_t pivot {2};

    epi::dutchFlagPartition(array, pivot);

    std::vector<int> expected {0, 1, 0, 1, 1, 2, 2};
    ASSERT_EQ(array, expected);
}


TEST(IncrementInteger, Sums1)
{
    std::vector<int> num {1, 2, 9};
    std::vector<int> plusOne {epi::incrementInteger(num)};

    std::vector<int> expected {1, 3, 0};
    ASSERT_EQ(plusOne, expected);
}


TEST(IncrementInteger, NumberIncreasesDigitSize)
{
    std::vector<int> num {9, 9, 9, 9};
    std::vector<int> plusOne {epi::incrementInteger(num)};

    std::vector<int> expected {1, 0, 0, 0, 0};
    ASSERT_EQ(plusOne, expected);
}


TEST(IncrementInteger, EmptyArray)
{
    std::vector<int> num {};
    std::vector<int> plusOne {epi::incrementInteger(num)};

    ASSERT_TRUE(plusOne.empty());
}


TEST(MultiplyIntegers, PositiveNumbers)
{
    std::vector<int> num {1, 4, 2};
    std::vector<int> multiplier {9, 2};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    std::vector<int> expected {1, 3, 0, 6, 4};
    ASSERT_EQ(result, expected);
}


TEST(MultiplyIntegers, PositiveAndNegative)
{
    std::vector<int> num {1, 9, 3};
    std::vector<int> multiplier {-7, 6, 1};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    std::vector<int> expected {-1, 4, 6, 8, 7, 3};
    ASSERT_EQ(result, expected);
}


TEST(MultiplyIntegers, NegativeNumbers)
{
    std::vector<int> num {-1, 4, 2};
    std::vector<int> multiplier {-2, 3, 5};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    std::vector<int> expected {3, 3, 3, 7, 0};
    ASSERT_EQ(result, expected);
}


TEST(MultiplyIntegers, LargeNumbers)
{
    std::vector<int> num {1, 9, 3, 7, 0, 7, 7, 2, 1};
    std::vector<int> multiplier {-7, 6, 1, 8, 3, 8, 2, 5, 7, 2, 8, 7};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    std::vector<int> expected {-1, 1, 4, 7, 5, 7, 3, 9, 5, 2, 5, 8, 9, 6, 7, 6, 4, 1, 2, 9, 2, 7};
    ASSERT_EQ(result, expected);
}


TEST(MultiplyIntegers, FactorOrderDoesntAffectProduct)
{
    std::vector<int> num {3, 4, 5};
    std::vector<int> multiplier {4, 2};

    std::vector<int> result1 {epi::multiplyIntegers(num, multiplier)};
    std::vector<int> result2 {epi::multiplyIntegers(multiplier, num)};

    std::vector<int> expected {1, 4, 4, 9, 0};
    ASSERT_EQ(result1, result2);
    ASSERT_EQ(result1, expected);
}


TEST(MultiplyIntegers, ANumberIsEmptyReturnsEmpty)
{
    std::vector<int> num {1, 9, 3};
    std::vector<int> multiplier {};
    std::vector<int> result {epi::multiplyIntegers(num, multiplier)};

    ASSERT_TRUE(result.empty());

    result = epi::multiplyIntegers(multiplier, num);
    ASSERT_TRUE(result.empty());
}