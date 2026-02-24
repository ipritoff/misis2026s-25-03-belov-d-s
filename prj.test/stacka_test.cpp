#include <stacka/stacka.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[stacka] - basic operations") {
    StackA stack;

    CHECK(stack.is_empty() == true);

    stack.push(10);
    CHECK(stack.is_empty() == false);
    CHECK(stack.top() == 10);

    stack.push(20);
    CHECK(stack.top() == 20);

    stack.pop();
    CHECK(stack.top() == 10);

    stack.pop();
    CHECK(stack.is_empty() == true);
}

TEST_CASE("[stacka] - exceptions") {
    StackA stack;

    CHECK_THROWS(stack.top());
}

TEST_CASE("[stacka] - copy") {
    StackA stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    StackA stack2(stack1);
    CHECK(stack2.top() == 3);

    stack2.pop();
    CHECK(stack2.top() == 2);
    CHECK(stack1.top() == 3);
}