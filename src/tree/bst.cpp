//
// Created by daniel on 26/08/23.
//

#include "bst.h"


bool isBSTHelper(const epi::TreeNode<int>* root, int min, int max){
    if (root == nullptr)
        return true;

    if (root->key < min || root->key > max)
        return false;

    return isBSTHelper(root->left, min, root->key) &&
        isBSTHelper(root->right, root->key, max);
}

template<>
bool epi::AbstractBinaryTree<int>::isBST() const {
    int min {std::numeric_limits<int>::min()};
    int max {std::numeric_limits<int>::max()};
    return isBSTHelper(m_root, min, max);
}
