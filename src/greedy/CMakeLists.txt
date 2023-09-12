add_library(greedy "")

target_sources(greedy
        PRIVATE
        greedy.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/greedy.h
)

target_include_directories(greedy
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
