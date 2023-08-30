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


TEST(TestBinarySearch, FindsElementIfPresent1)
{
    std::vector<int> arr {1, 2, 6, 8, 9};
    ASSERT_EQ(binarySearch(arr, 8), 3);
}


TEST(TestBinarySearch, FindsElementIfPresent2)
{
    std::vector<int> arr {1, 2, 6, 8, 9};
    ASSERT_EQ(binarySearch(arr, 1), 0);
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


TEST(TestBinarySearchWithDuplicates, ElementNotFound)
{
    std::vector<int> arr {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    ASSERT_EQ(binarySearchDup(arr, 250), -1);
}


TEST(TestBinarySearchWithDuplicates, ReturnsFirstOccurrence1)
{
    std::vector<int> arr {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    ASSERT_EQ(binarySearchDup(arr, 108), 3);
}


TEST(TestBinarySearchWithDuplicates, ReturnsFirstOccurrence2)
{
    std::vector<int> arr {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    ASSERT_EQ(binarySearchDup(arr, 285), 6);
}


TEST(TestBinarySearchWithDuplicates, AllTheSame)
{
    std::vector<int> arr {2, 2, 2, 2, 2};
    ASSERT_EQ(binarySearchDup(arr, 2), 0);
}


TEST(TestFirstLarger, NoLargerElement1)
{
    std::vector<int> arr {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    ASSERT_EQ(firstLarger(arr, 500), -1);
}


TEST(TestFirstLarger, NoLargerElement2)
{
    std::vector<int> arr {-14, -10, 2, 108, 108, 243, 285, 285, 401, 401};
    ASSERT_EQ(firstLarger(arr, 401), -1);
}


TEST(TestFirstLarger, FindsLargerElment1)
{
    std::vector<int> arr {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    ASSERT_EQ(firstLarger(arr, 101), 3);  // arr[3] = 108
}


TEST(TestFirstLarger, FindsLargerElment2)
{
    std::vector<int> arr {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    ASSERT_EQ(firstLarger(arr, 250), 6);  // arr[6] = 285
}
