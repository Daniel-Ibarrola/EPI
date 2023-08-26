cmake_minimum_required(VERSION 3.26)
project(InterviewPrep)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
