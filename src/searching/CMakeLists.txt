add_library(searching "")

target_sources(searching
        PRIVATE
        search.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/search.h
)

target_include_directories(searching
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
