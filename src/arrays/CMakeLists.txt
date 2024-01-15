add_library(arrays "")

target_sources(arrays
        PRIVATE
        arrays.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/arrays.h
)

target_include_directories(arrays
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
