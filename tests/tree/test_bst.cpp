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
    epi::BST<int> tree{4, 3, 5};
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
    epi::BST<int> tree{40, 30, 50, 35, 45};
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
    epi::BST<int> tree{43, 23, 47, 37, 53, 29, 41, 31};
    std::vector<int> keys {tree.sortedKeys()};
    std::vector<int> expected {23, 29, 31, 37, 41, 43, 47, 53};
    ASSERT_EQ(keys, expected);
}


TEST(TestGetSortedKeys, EmptyTree)
{
    epi::BST<int> tree;
    std::vector<int> keys {tree.sortedKeys()};
    ASSERT_TRUE(keys.empty());
}


TEST(TestBinarySearchTree, InsertingKeys)
{
    epi::BST<float> tree;
    tree.push(20.);
    tree.push(25.5);
    tree.push(12.75);

    ASSERT_EQ(tree.length(), 3);
    ASSERT_TRUE(tree.search(20.));
    ASSERT_TRUE(tree.search(25.5));
    ASSERT_TRUE(tree.search(12.75));
}


TEST(TestBinarySearchTree, SearchForKeyNotPresent)
{
    epi::BST<int> tree {5, 7, 2};
    ASSERT_FALSE(tree.search(8));
}


TEST(TestLevelOrderTraversal, SmallTree)
{
    epi::BST<float> tree;
    tree.push(20.);
    tree.push(25.5);
    tree.push(12.75);

    std::vector<float> keys {tree.levelOrder()};
    std::vector<float> expected {20., 12.75, 25.5};
    ASSERT_EQ(keys, expected);
}


TEST(TestLevelOrderTraversal, LargerTree)
{
    epi::BST<int> tree{43, 23, 47, 37, 53, 29, 41, 31};
    std::vector<int> keys {tree.levelOrder()};
    std::vector<int> expected {43, 23, 47, 37, 53, 29, 41, 31};
    ASSERT_EQ(keys, expected);
}


TEST(TestInOrderTraversal, SmallTree)
{
    epi::BST<int> tree {10, 5, 15};
    std::vector<int> keys {tree.inOrder()};
    std::vector<int> expected {5, 10, 15};
    ASSERT_EQ(keys, expected);
}


TEST(TestInOrderTraversal, LargerTree)
{
    epi::BST<int> tree {50, 25, 75, 10, 30, 60, 90};
    std::vector<int> keys {tree.inOrder()};
    std::vector<int> expected {10, 25, 30, 50, 60, 75, 90};
    ASSERT_EQ(keys, expected);
}


TEST(TestPreorderTraversal, SmallTree)
{
    epi::BST<int> tree {10, 5, 15};
    std::vector<int> keys {tree.preOrder()};
    std::vector<int> expected {10, 5, 15};
    ASSERT_EQ(keys, expected);
}


TEST(TestPreorderTraversal, LargerTree)
{
    epi::BST<int> tree {50, 25, 75, 10, 30, 60, 90};
    std::vector<int> keys {tree.preOrder()};
    std::vector<int> expected {50, 25, 10, 30, 75, 60, 90};
    ASSERT_EQ(keys, expected);
}


TEST(TestPostOrderTraversal, SmallTree)
{
    epi::BST<int> tree {10, 5, 15};
    std::vector<int> keys {tree.postOrder()};
    std::vector<int> expected {5, 15, 10};
    ASSERT_EQ(keys, expected);
}


TEST(TestPostOrderTraversal, LargerTree)
{
    epi::BST<int> tree {50, 25, 75, 10, 30, 60, 90};
    std::vector<int> keys {tree.postOrder()};
    std::vector<int> expected {10, 30, 25, 60, 90, 75, 50};
    ASSERT_EQ(keys, expected);
}


TEST(TestTreeHeight, SmallTree)
{
    epi::BST<int> tree{4, 3, 5};
    ASSERT_EQ(tree.height(), 1);
}


TEST(TestTreeHeight, LargerTree)
{
    epi::BST<int> tree {50, 25, 75, 10, 30, 60, 90};
    ASSERT_EQ(tree.height(), 2);
}


TEST(TestTreeHeight, EmptyTree)
{
    epi::BST<int> tree;
    ASSERT_EQ(tree.height(), 0);
}


TEST(TestTreeBalance, UnbalancedTreeSmall)
{
    epi::BST<int> tree{50, 25, 20};
    ASSERT_FALSE(tree.isBalanced());
}


TEST(TestTreeBalance, UnbalancedTreeLarge)
{
    epi::BST<int> tree{50, 25, 20, 30, 10, 15, 75};
    ASSERT_FALSE(tree.isBalanced());
}


TEST(TestTreeBalance, BalancedTreeSmall)
{
    epi::BST<int> tree {50, 25, 75, 10};
    ASSERT_TRUE(tree.isBalanced());
}


TEST(TestTreeBalance, BalancedTreeLarge)
{
    epi::BST<int> tree {50, 25, 75, 10, 30, 60, 90};
    ASSERT_TRUE(tree.isBalanced());
}


TEST(TestTreeBalance, EmptyTree)
{
    epi::BST<int> tree;
    ASSERT_TRUE(tree.isBalanced());
}
