//
// Created by daniel on 26/08/23.
//

#ifndef INTERVIEWPREP_BST_H
#define INTERVIEWPREP_BST_H

#include <initializer_list>
#include <stack>
#include <vector>
#include "binary_tree.h"
#include "node.h"

namespace itp {

    template <typename data_type>
    class BST : public AbstractBinaryTree<data_type> {
        // Binary Search tree class

        void insertKey(TreeNode<data_type>* root,
                       data_type key,
                       std::size_t keyId){
            if (key <= root->key){
                if (root->left == nullptr)
                    root->left = new TreeNode<data_type> {key, keyId};
                else
                    insertKey(root->left, key, keyId);
            }
            else {
                if (root->right == nullptr)
                    root->right = new TreeNode<data_type> {key, keyId};
                else
                    insertKey(root->right, key, keyId);
            }
        }

        bool recursiveSearch(TreeNode<data_type>* root, data_type key) const {
            if (root == nullptr)
                return false;

            if (root->key == key)
                return true;

            if (key < root->key)
                return recursiveSearch(root->left, key);
            else
                return recursiveSearch(root->right, key);
        }

    public:
        BST() = default;

        BST(std::initializer_list<data_type> treeData){
            for (auto data: treeData){
                push(data);
            }
        }

        std::vector<data_type> sortedKeys() const {
            std::vector<data_type> keys;
            std::stack<TreeNode<data_type>*> nodes;
            TreeNode<data_type>* current {this->m_root};

            while (!nodes.empty() || current) {
                if (current){
                    nodes.push(current);
                    current = current->left;
                } else {
                    current = nodes.top();
                    nodes.pop();
                    keys.push_back(current->key);
                    current = current->right;
                }
            }
            return keys;
        }

        void push(data_type key) override {
            if (this->m_root == nullptr)
                this->m_root = new TreeNode<data_type> {key, this->m_length};
            else
                insertKey(this->m_root, key, this->m_length);
            ++this->m_length;
        }

        bool search(data_type key) const override {
            // Search for a specific key in the tree. Returns true if
            // the key is present, false otherwise
            return recursiveSearch(this->m_root, key);
        }
    };
}

#endif //INTERVIEWPREP_BST_H
