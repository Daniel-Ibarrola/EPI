add_executable(InterviewPrep main.cpp)

add_subdirectory(arrays)
add_subdirectory(graph)
add_subdirectory(greedy)
add_subdirectory(hashtable)
add_subdirectory(heap)
add_subdirectory(linkedlist)
add_subdirectory(searching)
add_subdirectory(sorting)
add_subdirectory(stack)
add_subdirectory(tree)


target_link_libraries(InterviewPrep
        PUBLIC
        arrays
        greedy
        hashtable
        heap
        linkedlist
        searching
        stack
        tree
)
