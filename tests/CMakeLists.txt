project(Google_tests)
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        Google_Tests_run
        linkedlist/test_linkedlist.cpp
        stack/test_stack_max.cpp
        tree/test_bst.cpp
)

target_link_libraries(Google_Tests_run linkedlist)
target_link_libraries(Google_Tests_run stack)
target_link_libraries(Google_Tests_run tree)
target_link_libraries(Google_Tests_run gtest gtest_main)
