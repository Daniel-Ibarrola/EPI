//
// Created by daniel on 30/08/23.
//
#include "gtest/gtest.h"
#include "search.h"


TEST(TestBinarySearch, EmptyVector)
{
    std::vector<int> arr;
    ASSERT_EQ(binarySearch(arr, 5), -1);
}


TEST(TestBinarySearch, FindsElementIfPresent)
{
    std::vector<int> arr {1, 2, 6, 8, 9};
    ASSERT_EQ(binarySearch(arr, 8), 3);
}


TEST(TestBinarySearch, ElementNotPresent)
{
    std::vector<int> arr {1, 2, 6, 8, 9};
    ASSERT_EQ(binarySearch(arr, 3), -1);
}


TEST(TestBinarySearch, RepeatedElement)
{
    std::vector<int> arr {1, 2, 2, 6, 8, 9};
    ASSERT_EQ(binarySearch(arr, 2), 2);
}
