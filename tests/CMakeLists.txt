project(Google_tests)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        hashtable/test_can_form_palindrome.cpp
        hashtable/test_write_letter.cpp
        linkedlist/test_linkedlist.cpp
        searching/test_binary_search.cpp
        stack/test_stack_max.cpp
        tree/test_bst.cpp
        tree/test_binary_tree.cpp
)

target_link_libraries(Google_Tests_run hashtable)
target_link_libraries(Google_Tests_run linkedlist)
target_link_libraries(Google_Tests_run searching)
target_link_libraries(Google_Tests_run stack)
target_link_libraries(Google_Tests_run tree)
target_link_libraries(Google_Tests_run gtest gtest_main)
