add_library(tree "")

target_sources(tree
        PRIVATE
        bst.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/bst.h
)

target_include_directories(tree
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)