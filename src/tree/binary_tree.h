//
// Created by daniel on 27/08/23.
//

#ifndef INTERVIEWPREP_BINARY_TREE_H
#define INTERVIEWPREP_BINARY_TREE_H

#include <queue>
#include <vector>
#include "node.h"

namespace itp {

    template<typename data_type>
    class AbstractBinaryTree {
    protected:
        TreeNode<data_type>* m_root {nullptr};
        std::size_t m_length {0};

    public:
        virtual void push(data_type key) = 0;
        virtual bool search(data_type key) const = 0;

        [[nodiscard]] bool empty() const {return this->m_length == 0;}
        [[nodiscard]] std::size_t length() const { return this->m_length; }

        std::vector<data_type> levelOrder() const {
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

        std::vector<data_type> inOrder() const {
            // Return the keys of the tree in "inorder"
            std::vector<data_type> keys;
            inOrderHelper(m_root, keys);
            return keys;
        }

        std::vector<data_type> preOrder() const {
            // Return the keys of the tree in "preorder"
            std::vector<data_type> keys;
            preOrderHelper(m_root, keys);
            return keys;
        }

        std::vector<data_type> postOrder() const {
            // Return the keys if the tree in "postorder"
            std::vector<data_type> keys;
            postOrderHelper(m_root, keys);
            return keys;
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

    };

    template<typename data_type>
    class BinaryTree : public AbstractBinaryTree<data_type> {
        // A binary tree


    };
}

#endif //INTERVIEWPREP_BINARY_TREE_H
