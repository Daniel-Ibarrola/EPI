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
    epi::incrementInteger(num);

    std::vector<int> expected {1, 3, 0};
    ASSERT_EQ(num, expected);
}


TEST(IncrementInteger, NumberIncreasesDigitSize)
{
    std::vector<int> num {9, 9, 9, 9};
    epi::incrementInteger(num);

    std::vector<int> expected {1, 0, 0, 0, 0};
    ASSERT_EQ(num, expected);
}


TEST(IncrementInteger, EmptyArray)
{
    std::vector<int> num {};
    epi::incrementInteger(num);

    ASSERT_TRUE(num.empty());
}