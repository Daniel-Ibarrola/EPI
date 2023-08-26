//
// Created by daniel on 26/08/23.
//

#include "gtest/gtest.h"
#include "stack_max.h"


TEST(TestStackMax, FindMaxElement)
{
    itp::StackMax<int> stack {1, 4, 3, 2};
    int max {stack.getMax()};
    ASSERT_EQ(max, 4);
}

TEST(TestStackMax, FindMaxAfterRemovingElements)
{
    itp::StackMax<int> stack {1, 4, 3, 5};
    int max {stack.getMax()};
    ASSERT_EQ(max, 5);

    stack.pop();  // new stack is {1, 4, 3}
    max = stack.getMax();
    ASSERT_EQ(max, 4);

    stack.pop();  // new stack is {1, 4}
    max = stack.getMax();
    ASSERT_EQ(max, 4);

    stack.pop();  // new stack is {1}
    max = stack.getMax();
    ASSERT_EQ(max, 1);
}

TEST(TestStackMax, AllElementsEqual)
{
    itp::StackMax<int> stack {4, 4, 4, 4};
    int max {stack.getMax()};
    ASSERT_EQ(max, 4);

    stack.pop();
    max = stack.getMax();
    ASSERT_EQ(max, 4);
}


TEST(TestStackMax, ThrowsExceptionIfEmpty)
{
    itp::StackMax<int> stack;
    ASSERT_THROW(stack.getMax(), itp::EmptyStackError);
}
