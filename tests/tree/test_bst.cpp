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


TEST(TestBinarySearchTree, InsertingKeys)
{
    itp::BST<float> tree;
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
    itp::BST<int> tree {5, 7, 2};
    ASSERT_FALSE(tree.search(8));
}


TEST(TestLevelOrderTraversal, SmallTree)
{
    itp::BST<float> tree;
    tree.push(20.);
    tree.push(25.5);
    tree.push(12.75);

    std::vector<float> keys {tree.levelOrder()};
    std::vector<float> expected {20., 12.75, 25.5};
    ASSERT_EQ(keys, expected);
}


TEST(TestLevelOrderTraversal, LargerTree)
{
    itp::BST<int> tree{43, 23, 47, 37, 53, 29, 41, 31};
    std::vector<int> keys {tree.levelOrder()};
    std::vector<int> expected {43, 23, 47, 37, 53, 29, 41, 31};
    ASSERT_EQ(keys, expected);
}


//TEST(TestInOrderTraversal, SmallTree)
//{
//    itp::BST<int> tree {1, 2, 3};
//    std::vector keys {tree.inOrder()};
//    std::vector expected {2, 1, 3};
//    ASSERT_EQ(keys, expected);
//}
//
//
//TEST(TestInorderTraversal, LargerTree)
//{
//    itp::BST<int> tree {1, 2, 3, 4, 5, 6, 7};
//    std::vector keys {tree.inOrder()};
//    std::vector expected {4, 2, 5, 1, 6, 3, 7};
//    ASSERT_EQ(keys, expected);
//}
//
//
//TEST(TestPreorderTraversal, SmallTree)
//{
//    itp::BST<int> tree {1, 2, 3};
//    std::vector keys {tree.preOrder()};
//    std::vector expected {1, 2, 3};
//    ASSERT_EQ(keys, expected);
//}
//
//
//TEST(TestPreorderTraversal, LargerTree)
//{
//    itp::BST<int> tree {1, 2, 3, 4, 5, 6, 7};
//    std::vector keys {tree.preOrder()};
//    std::vector expected {1, 2, 4, 5, 3, 6, 7};
//    ASSERT_EQ(keys, expected);
//}
//
//
//TEST(TestPostOrderTraversal, SmallTree)
//{
//    itp::BST<int> tree {1, 2, 3};
//    std::vector keys {tree.postOrder()};
//    std::vector expected {1, 2, 3};
//    ASSERT_EQ(keys, expected);
//}
//
//
//TEST(TestPostOrderTraversal, LargerTree)
//{
//    itp::BST<int> tree {1, 2, 3, 4, 5, 6, 7};
//    std::vector keys {tree.postOrder()};
//    std::vector expected {4, 5, 2, 6, 7, 3, 1};
//    ASSERT_EQ(keys, expected);
//}
