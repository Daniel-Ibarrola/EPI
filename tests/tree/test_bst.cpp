//
// Created by daniel on 26/08/23.
//

#include "gtest/gtest.h"
#include "bst.h"


TEST(TestGetSortedKeys, SmallTree)
{
    // Create the tree
    //      4
    //     /  \
    //    3    5
    itp::BST<int> tree{4, 3, 5};
    std::vector<int> keys {tree.sortedKeys()};
    std::vector<int> expected {3, 4, 5};
    ASSERT_EQ(keys, expected);
}

TEST(TestGetSortedKeys, MediumTree)
{
    // Create the tree
    //       40
    //     /    \
    //    30     50
    //     \     /
    //      35  45
    itp::BST<int> tree{40, 30, 50, 35, 45};
    std::vector<int> keys {tree.sortedKeys()};
    std::vector<int> expected {30, 35, 40, 45, 50};
    ASSERT_EQ(keys, expected);
}


TEST(TestGetSortedKeys, LargerTree)
{
    // Create the tree:
    //      43
    //     /   \
    //    23    47
    //      \    \
    //       37   53
    //      /  \
    //     29   41
    //       \
    //        31
    itp::BST<int> tree{43, 23, 47, 37, 53, 29, 41, 31};
    std::vector<int> keys {tree.sortedKeys()};
    std::vector<int> expected {23, 29, 31, 37, 41, 43, 47, 53};
    ASSERT_EQ(keys, expected);
}


TEST(TestGetSortedKeys, EmptyTree)
{
    itp::BST<int> tree;
    std::vector<int> keys {tree.sortedKeys()};
    ASSERT_TRUE(keys.empty());
}
