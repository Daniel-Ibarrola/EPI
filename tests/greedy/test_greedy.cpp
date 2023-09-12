//
// Created by daniel on 12/09/23.
//

#include "gtest/gtest.h"
#include "greedy.h"


TEST(AssignTasks, FindsOptimalAssignment)
{
    std::vector<int> tasks {5, 2, 1, 6, 4, 4};
    std::vector<epi::Worker> workers {epi::assignTasks(tasks)};
    std::vector<epi::Worker> expected {
            {1, 6},
            {2, 5},
            {4, 4}
    };
    ASSERT_EQ(workers, expected);
}