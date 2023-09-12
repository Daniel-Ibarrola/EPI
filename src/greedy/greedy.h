//
// Created by daniel on 12/09/23.
//

#ifndef INTERVIEWPREP_GREEDY_H
#define INTERVIEWPREP_GREEDY_H

#include <algorithm>
#include <iostream>
#include <vector>

namespace epi {

    struct Worker {
        int task1;
        int task2;

        bool operator==(const Worker& other) const {
            return task1 == other.task1 and task2 == other.task2;
        }

        bool operator!=(const Worker& other) const {
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream& out, const Worker& worker);
    };

    std::vector<Worker> assignTasks(std::vector<int>& tasks);

}

#endif //INTERVIEWPREP_GREEDY_H
