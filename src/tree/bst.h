//
// Created by daniel on 26/08/23.
//

#ifndef INTERVIEWPREP_BST_H
#define INTERVIEWPREP_BST_H

#include <initializer_list>
#include <vector>

namespace itp {


    template <typename data_type>
    class BST {
        // Binary Search tree class
    public:
        BST() = default;

        BST(std::initializer_list<data_type> treeData){

        }

        std::vector<data_type> sortedKeys() const {
            return {};
        }
    };
}

#endif //INTERVIEWPREP_BST_H
