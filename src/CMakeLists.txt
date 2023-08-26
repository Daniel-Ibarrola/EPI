add_executable(InterviewPrep main.cpp)

add_subdirectory(linkedlist)

target_link_libraries(InterviewPrep
        PUBLIC
        linkedlist
)
