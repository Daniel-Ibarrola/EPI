add_library(sorting "")

target_sources(sorting
        PRIVATE
        sorting.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/sorting.h
)

target_include_directories(sorting
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)