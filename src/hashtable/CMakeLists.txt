add_library(hashtable "")

target_sources(hashtable
        PRIVATE
        hashtable.cpp
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/hashtable.h
)

target_include_directories(hashtable
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)