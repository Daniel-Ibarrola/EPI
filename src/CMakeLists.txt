add_executable(InterviewPrep main.cpp)

add_subdirectory(linkedlist)
add_subdirectory(stack)
add_subdirectory(tree)

target_link_libraries(InterviewPrep
        PUBLIC
        linkedlist
        stack
        tree
)
