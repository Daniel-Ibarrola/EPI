//
// Created by daniel on 12/09/23.
//

#include "greedy.h"


namespace epi {

    std::vector<Worker> assignTasks(std::vector<int>& tasks) {
        // Returns an optimal assignments of tasks to each worker.
        // Each worker is assigned exactly two tasks
        std::vector<Worker> workers;
        if (tasks.empty())
            return workers;

        std::sort(tasks.begin(), tasks.end());
        std::size_t ii {0};
        std::size_t jj {tasks.size() - 1};
        while (ii < jj) {
            workers.emplace_back(Worker{tasks[ii], tasks[jj]});
            ++ii;
            --jj;
        }
        return workers;
    }

    std::ostream &operator<<(std::ostream &out, const Worker &worker) {
        out << "Worker<" << worker.task1 << ", " << worker.task2 << ">";
        return out;
    }
}
