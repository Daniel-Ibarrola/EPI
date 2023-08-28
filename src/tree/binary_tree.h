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
    };

    template<typename data_type>
    class BinaryTree : public AbstractBinaryTree<data_type> {
        // A binary tree


    };
}

#endif //INTERVIEWPREP_BINARY_TREE_H
