//
// Created by daniel on 27/08/23.
//
#include "gtest/gtest.h"
#include "bst.h"


TEST(TestBST, BSTTree)
{
    epi::BST<int> tree {10 ,15, 20, 5};
    ASSERT_TRUE(tree.isBST());
}


TEST(TESTBST, NonBST1)
{
    // Create the tree
    //      15
    //     /  \
    //   10    13
    epi::BinaryTree<int> tree;
    tree.setRootKey(15);
    tree.push(tree.getRoot(), 10, epi::Child::LEFT);
    tree.push(tree.getRoot(), 13, epi::Child::RIGHT);
    ASSERT_FALSE(tree.isBST());
}


TEST(TESTBST, NonBST2)
{
    // Create the tree:
    //       15
    //     /    \
    //    10     20
    //   /  \   /  \
    //  5   12 14  25
    epi::BinaryTree<int> tree;
    tree.setRootKey(15);
    tree.push(tree.getRoot(), 10, epi::Child::LEFT);
    tree.push(tree.getRoot(), 20, epi::Child::RIGHT);

    tree.push(tree.getRoot()->left, 5, epi::Child::LEFT);
    tree.push(tree.getRoot()->left, 12, epi::Child::RIGHT);

    tree.push(tree.getRoot()->right, 14, epi::Child::LEFT);
    tree.push(tree.getRoot()->right, 25, epi::Child::RIGHT);

    ASSERT_FALSE(tree.isBST());
}
