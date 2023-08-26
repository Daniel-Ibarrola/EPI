//
// Created by daniel on 25/08/23.
//
#include "gtest/gtest.h"
#include "linkedlist.h"


TEST(TestListToVector, PutsAllElmentsInVector)
{
    itp::LinkedList<double> list {2, 5, 3, 1};
    std::vector<double> vector {list.toVector()};
    std::vector<double> expected {2, 5, 3, 1};
    ASSERT_EQ(vector, expected);
}


TEST(TestMergeSortedLists, MergedListRemainSorted)
{
    itp::LinkedList<int> list1 {2, 5, 7};
    itp::LinkedList<int> list2 {3, 6, 11};

    itp::mergeSortedLists(list1, list2);
    ASSERT_EQ(list1.getLength(), 6);
    ASSERT_EQ(list2.getLength(), 6);

    std::vector<int> elements {list1.toVector()};
    std::vector<int> expected {2, 3, 5, 6, 7, 11};
    ASSERT_EQ(elements, expected);
}


TEST(TestMergeSortedLists, MergedListRemainSorted2)
{
    itp::LinkedList<int> list1 {1, 2, 3, 6, 7, 8};
    itp::LinkedList<int> list2 {4, 5, 6};

    itp::mergeSortedLists(list1, list2);
    ASSERT_EQ(list1.getLength(), 9);
    ASSERT_EQ(list2.getLength(), 9);

    std::vector<int> elements {list1.toVector()};
    std::vector<int> expected {1, 2, 3, 4, 5, 6, 6, 7, 8};
    ASSERT_EQ(elements, expected);
}


TEST(TestMergeSortedLists, AllElementsAreSmallerInOneList)
{
    itp::LinkedList<int> list1 {2, 3, 4};
    itp::LinkedList<int> list2 {5, 6, 7};

    itp::mergeSortedLists(list1, list2);
    ASSERT_EQ(list1.getLength(), 6);
    ASSERT_EQ(list2.getLength(), 6);

    std::vector<int> elements {list1.toVector()};
    std::vector<int> expected {2, 3, 4, 5, 6, 7};
    ASSERT_EQ(elements, expected);
}


TEST(TestMergeSortedLists, AllElementsAreSmallerInOneList2)
{
    itp::LinkedList<int> list1 {5, 6, 7};
    itp::LinkedList<int> list2 {2, 3, 4};

    itp::mergeSortedLists(list1, list2);
    ASSERT_EQ(list1.getLength(), 6);
    ASSERT_EQ(list2.getLength(), 6);

    std::vector<int> elements {list1.toVector()};
    std::vector<int> expected {2, 3, 4, 5, 6, 7};
    ASSERT_EQ(elements, expected);
}


TEST(TestMergeSortedLists, SameElementlLists)
{
    itp::LinkedList<int> list1 {2, 2, 2};
    itp::LinkedList<int> list2 {2, 2};

    itp::mergeSortedLists(list1, list2);
    ASSERT_EQ(list1.getLength(), 5);
    ASSERT_EQ(list2.getLength(), 5);

    std::vector<int> elements {list1.toVector()};
    std::vector<int> expected {2, 2, 2, 2, 2};
    ASSERT_EQ(elements, expected);
}
