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
