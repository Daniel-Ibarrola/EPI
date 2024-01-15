//
// Created by daniel on 27/08/23.
//

#ifndef INTERVIEWPREP_BINARY_TREE_H
#define INTERVIEWPREP_BINARY_TREE_H

#include <cmath>
#include <queue>
#include <vector>
#include "node.h"

namespace epi {

    template<typename data_type>
    class AbstractBinaryTree {
    protected:
        TreeNode<data_type>* m_root {nullptr};
        std::size_t m_length {0};

        const int UNBALANCED {-2};

    public:
        virtual void push(data_type key) = 0;
        [[nodiscard]] virtual bool search(data_type key) const = 0;

        [[nodiscard]] bool empty() const {return this->m_length == 0;}
        [[nodiscard]] std::size_t length() const { return this->m_length; }

        [[nodiscard]] std::vector<data_type> levelOrder() const {
            if (this->empty())
                return {};

            std::vector<data_type> keys;
            std::queue<TreeNode<data_type>*> queue;
            queue.push(m_root);

            while (!queue.empty()){
                TreeNode<data_type>* current {queue.front()};
                queue.pop();

                keys.push_back(current->key);

                if (current->left != nullptr)
                    queue.push(current->left);

                if (current->right != nullptr)
                    queue.push(current->right);

            }
            return keys;
        }

        [[nodiscard]] std::vector<data_type> inOrder() const {
            // Return the keys of the tree in "inorder"
            std::vector<data_type> keys;
            inOrderHelper(m_root, keys);
            return keys;
        }

        [[nodiscard]] std::vector<data_type> preOrder() const {
            // Return the keys of the tree in "preorder"
            std::vector<data_type> keys;
            preOrderHelper(m_root, keys);
            return keys;
        }

        [[nodiscard]] std::vector<data_type> postOrder() const {
            // Return the keys if the tree in "postorder"
            std::vector<data_type> keys;
            postOrderHelper(m_root, keys);
            return keys;
        }

        [[nodiscard]] bool isBalanced() const {
            return isBalancedHelper(m_root) != UNBALANCED;
        }

        [[nodiscard]] unsigned int height() const {
            // Compute the height of the tree
            if (empty())
                return 0;
            return heightHelper(m_root) - 1;
        }

        [[nodiscard]] bool isBST() const {
            return false;
        }

    private:

        void inOrderHelper(TreeNode<data_type>* node,
                           std::vector<data_type>& keys) const{
            if (node == nullptr)
                return;

            inOrderHelper(node->left, keys);
            keys.push_back(node->key);
            inOrderHelper(node->right, keys);
        }

        void preOrderHelper(TreeNode<data_type>* node,
                           std::vector<data_type>& keys) const{
            if (node == nullptr)
                return;

            keys.push_back(node->key);
            preOrderHelper(node->left, keys);
            preOrderHelper(node->right, keys);
        }

        void postOrderHelper(TreeNode<data_type>* node,
                            std::vector<data_type>& keys) const{
            if (node == nullptr)
                return;

            postOrderHelper(node->left, keys);
            postOrderHelper(node->right, keys);
            keys.push_back(node->key);
        }

        unsigned int heightHelper(TreeNode<data_type>* root) const {
            if (root == nullptr)
                return 0;
            unsigned int leftTreeHeight {heightHelper(root->left)};
            unsigned int rightTreeHeight {heightHelper(root->right)};
            return std::max(leftTreeHeight, rightTreeHeight) + 1;
        }

        int isBalancedHelper(TreeNode<data_type>* root) const {
            if (root == nullptr)
                return 0;

            int leftTreeH {isBalancedHelper(root->left)};
            if (leftTreeH == UNBALANCED)
                return UNBALANCED;

            int rightTreeH {isBalancedHelper(root->right)};
            if (rightTreeH == UNBALANCED)
                return UNBALANCED;

            if (abs(leftTreeH - rightTreeH) > 1)
                return UNBALANCED;

            return std::max(leftTreeH, rightTreeH) + 1;
        }
    };

    template <>
    bool AbstractBinaryTree<int>::isBST() const;

    enum class Child {
        LEFT,
        RIGHT
    };

    template<typename data_type>
    class BinaryTree : public AbstractBinaryTree<data_type> {
        // A binary tree

    public:

        BinaryTree() = default;

        BinaryTree(std::initializer_list<data_type> treeData){
            for (auto data: treeData){
                push(data);
            }
        }

        void push(data_type key) override {
            // Push a new key to the tree, keeping the tree balanced
        }

        TreeNode<data_type>* push(TreeNode<data_type>* root,
                                  data_type key,
                                  Child child
                ){
            // Push a new tree to the node manually
            auto* newNode = new TreeNode<data_type> {key, this->m_length};
            if (child == Child::LEFT)
                root->left = newNode;
            else
                root->right = newNode;
            ++this->m_length;
            return newNode;
        }

        bool search(data_type key) const override {
            // Search a tree in the key in O(numNodes) time
            return false;
        }

        TreeNode<data_type>* getRoot() { return this->m_root; }

        void setRootKey(data_type key) {
            // Set the key of the root node
            if (this->m_root == nullptr)
                this->m_root = new TreeNode<data_type> {key, 0};
            else
                this->m_root->key = key;
        }
    };
}

#endif //INTERVIEWPREP_BINARY_TREE_H
