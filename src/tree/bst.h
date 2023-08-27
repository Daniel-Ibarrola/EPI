//
// Created by daniel on 26/08/23.
//

#ifndef INTERVIEWPREP_BST_H
#define INTERVIEWPREP_BST_H

#include <initializer_list>
#include <stack>
#include <vector>

namespace itp {

    template <typename data_type>
    struct TreeNode {
        data_type key;
        TreeNode<data_type>* left;
        TreeNode<data_type>* right;
        std::size_t id;

        explicit TreeNode(data_type key_, std::size_t id_)
            : key {key_}, id {id_}, left {nullptr}, right {nullptr}
        {

        }

    };

    template <typename data_type>
    class BST {
        // Binary Search tree class
        TreeNode<data_type>* m_root {nullptr};
        std::size_t m_length {0};

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
            if (empty())
                return {};

            std::vector<data_type> keys;
            std::vector<bool> visited(m_length);
            std::stack<TreeNode<data_type>*> nodes;
            nodes.push(m_root);

            while (!nodes.empty()) {
                TreeNode<data_type>* current {nodes.top()};
                nodes.pop();

                if (visited[current->id]){
                    keys.push_back(current->key);
                    continue;
                }

                if (current->left == nullptr)
                    keys.push_back(current->key);

                if (current->right != nullptr && !visited[current->right->id])
                    nodes.push(current->right);

                if (current->left != nullptr)
                    nodes.push(current);

                if (current->left != nullptr && !visited[current->left->id])
                    nodes.push(current->left);

                visited[current->id] = true;
            }

            return keys;
        }

        std::vector<data_type> levelOrder() const {
            return {};
        }

        void push(data_type key){
            if (m_root == nullptr)
                m_root = new TreeNode<data_type> {key, m_length};
            else
                insertKey(m_root, key, m_length);
            ++m_length;
        }

        [[nodiscard]] std::size_t length() const { return m_length; }

        bool search(data_type key) const {
            // Search for a specific key in the tree. Returns true if
            // the key is present, false otherwise
            return recursiveSearch(m_root, key);
        }

        [[nodiscard]] bool empty() const {return m_length == 0;}
    };
}

#endif //INTERVIEWPREP_BST_H
