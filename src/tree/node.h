//
// Created by daniel on 27/08/23.
//

#ifndef INTERVIEWPREP_NODE_H
#define INTERVIEWPREP_NODE_H

#include <cstddef>

namespace epi {

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
}

#endif //INTERVIEWPREP_NODE_H
