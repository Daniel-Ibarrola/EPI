add_library(stack "")

target_sources(stack
        PRIVATE
        stack_max.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/stack_max.h
)

target_include_directories(stack
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)