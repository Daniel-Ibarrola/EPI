//
// Created by daniel on 5/09/23.
//
#include "gtest/gtest.h"
#include "sorting.h"


TEST(IntersectionOfArrays, ComputesIntersection)
{
    std::vector<int> arr1 {2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
    std::vector<int> arr2 {5, 5, 6, 8, 8, 9, 10, 10};
    std::vector<int> intersection {epi::intersection(arr1, arr2)};
    std::vector<int> expected {5, 6, 8};
    ASSERT_EQ(intersection, expected);
}


TEST(IntersectionOfArrays, ComputesIntersection2)
{
    std::vector<int> arr1 {3, 4, 5};
    std::vector<int> arr2 {3, 4, 5, 6};
    std::vector<int> intersection {epi::intersection(arr1, arr2)};
    std::vector<int> expected {3, 4, 5};
    ASSERT_EQ(intersection, expected);
}


TEST(IntersectionOfArrays, NoIntersectingElements)
{
    std::vector<int> arr1 {1, 2, 3, 4};
    std::vector<int> arr2 {5, 6, 7, 8};
    std::vector<int> intersection {epi::intersection(arr1, arr2)};
    ASSERT_TRUE(intersection.empty());
}


TEST(IntersectionOfArrays, EmptyArray1)
{
    std::vector<int> arr1;
    std::vector<int> arr2 {5, 6, 7, 8};
    std::vector<int> intersection {epi::intersection(arr1, arr2)};
    ASSERT_TRUE(intersection.empty());
}


TEST(IntersectionOfArrays, EmptyArray2)
{
    std::vector<int> arr1 {1, 2, 3};
    std::vector<int> arr2;
    std::vector<int> intersection {epi::intersection(arr1, arr2)};
    ASSERT_TRUE(intersection.empty());
}
