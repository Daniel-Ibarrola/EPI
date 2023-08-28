add_library(tree "")

target_sources(tree
        PRIVATE
        binary_tree.cpp
        bst.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/binary_tree.h
        ${CMAKE_CURRENT_LIST_DIR}/bst.h
        ${CMAKE_CURRENT_LIST_DIR}/node.h
)

target_include_directories(tree
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)