//
// Created by daniel on 4/09/23.
//
#include "gtest/gtest.h"
#include "sorting.h"


TEST(MergeSort, CanSortArray)
{
    std::vector<int> array {6, 5, 12, 10 ,9, 1};
    std::vector<int> expected {1, 5, 6, 9, 10, 12};
    epi::mergeSort(array);
    ASSERT_EQ(array , expected);
}


TEST(MergeSort, AllAreEqual)
{
    std::vector<int> array {2, 2, 2, 2};
    std::vector<int> expected {2, 2, 2, 2};
    epi::mergeSort(array);
    ASSERT_EQ(array , expected);
}


TEST(MergeSort, AlreadySorted)
{
    std::vector<int> array {1, 2, 3, 4};
    std::vector<int> expected {1, 2, 3, 4};
    epi::mergeSort(array);
    ASSERT_EQ(array , expected);
}


TEST(MergeSort, EmptyArray)
{
    std::vector<int> array;
    std::vector<int> expected;
    epi::mergeSort(array);
    ASSERT_TRUE(array.empty());
}


TEST(QuickSort, CanSortArray)
{
    std::vector<int> array {6, 5, 12, 10 ,9, 1};
    std::vector<int> expected {1, 5, 6, 9, 10, 12};
    epi::quickSort(array);
    ASSERT_EQ(array , expected);
}


TEST(QuickSort, AllAreEqual)
{
    std::vector<int> array {2, 2, 2, 2};
    std::vector<int> expected {2, 2, 2, 2};
    epi::quickSort(array);
    ASSERT_EQ(array , expected);
}


TEST(QuickSort, AlreadySorted)
{
    std::vector<int> array {1, 2, 3, 4};
    std::vector<int> expected {1, 2, 3, 4};
    epi::quickSort(array);
    ASSERT_EQ(array , expected);
}


TEST(QuickSort, EmptyArray)
{
    std::vector<int> array;
    std::vector<int> expected;
    epi::quickSort(array);
    ASSERT_TRUE(array.empty());
}
