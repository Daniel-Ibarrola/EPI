//
// Created by daniel on 27/08/23.
//
#include "gtest/gtest.h"
#include "binary_tree.h"


TEST(TestFindKey, KeyPresent)
{
    itp::BinaryTree<int> tree {1, 2, 3, 4, 5};
    ASSERT_TRUE(tree.search(3));
}


TEST(TestFindKey, KeyNotPresent)
{
    itp::BinaryTree<int> tree {1, 2, 3, 4, 5};
    ASSERT_FALSE(tree.search(10));
}


TEST(TestIsTreeBalanced, BalancedTree)
{
    itp::BinaryTree<int> tree {1, 2, 3, 4, 5};
    ASSERT_TRUE(tree.isBalanced());
}


TEST(TestIsTreeBalanced, UnbalancedTree)
{
    itp::BinaryTree<int> tree;
    tree.setRootKey(1);
    itp::TreeNode<int>* root {tree.getRoot()};
    itp::TreeNode<int>* child {tree.push(root, 2, itp::Child::LEFT)};
    tree.push(root, 3, itp::Child::RIGHT);

    tree.push(child, 4, itp::Child::LEFT);
    child = tree.push(child, 5, itp::Child::RIGHT);
    tree.push(child, 6, itp::Child::LEFT);

    ASSERT_FALSE(tree.isBalanced());
}