add_library(linkedlist "")

target_sources(linkedlist
        PRIVATE
        linkedlist.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/linkedlist.h
)

target_include_directories(linkedlist
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)