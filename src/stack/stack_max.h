//
// Created by daniel on 26/08/23.
//

#ifndef INTERVIEWPREP_STACK_MAX_H
#define INTERVIEWPREP_STACK_MAX_H

#include <initializer_list>
#include <stack>
#include <stdexcept>


namespace itp{

    class EmptyStackError : public std::exception {
    private:
        std::string message_;

    public:
        explicit EmptyStackError(const char* message)
            : message_ (message) {

        }

        [[nodiscard]] const char* what() const noexcept override {
            return message_.c_str();
        }
    };

    template<typename data_type>
    class StackMax{
        // Stack that supports max operation in O(1) time
    private:
        std::stack<data_type> m_data;
        std::stack<data_type> m_max;

    public:

        StackMax() = default;

        StackMax(std::initializer_list<data_type> stackData){
            for (auto data: stackData)
                push(data);
        }

        void push(data_type data){
            m_data.push(data);
            if (m_max.empty() || m_max.top() <= data){
                m_max.push(data);
            }
        }

        data_type getMax() const {
            if (empty())
                throw EmptyStackError("Cannot get max from empty stack");
            return m_max.top();
        }

        data_type top() const {
            if (empty())
                throw EmptyStackError("Cannot get element from empty stack");
            return m_data.top();
        }

        void pop() {
            if (empty())
                throw EmptyStackError("Cannot pop from empty stack");
            data_type data {m_data.top()};
            m_data.pop();

            if (data == m_max.top())
                m_max.pop();
        }

        [[nodiscard]] bool empty() const {
            return m_data.empty();
        }

    };

}

#endif //INTERVIEWPREP_STACK_MAX_H
