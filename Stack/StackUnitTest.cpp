//
//  StackUnitTest.cpp
//  BinarySearchTree
//
//  Created by Richard Szeto on 8/15/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#include "StackUnitTest.hpp"
#include "Stack.cpp"
#include "gtest/gtest.h"

TEST(Stack, Push) {
    Stack<int> stack;
    EXPECT_EQ(stack.getCount(), 0);
    
    stack.push(1);
    EXPECT_EQ(stack.getCount(), 1);
    
    stack.push(2);
    EXPECT_EQ(stack.getCount(), 2);
}

TEST(Stack, Peek) {
    Stack<int> stack;
    EXPECT_EQ(stack.getCount(), 0);
    
    stack.push(5);
    EXPECT_EQ(stack.peek(), 5);
    
    stack.push(3);
    EXPECT_EQ(stack.peek(), 3);
    
    stack.pop();
    EXPECT_EQ(stack.peek(), 5);
}

TEST(Stack, Pop) {
    Stack<int> stack;
    EXPECT_EQ(stack.getCount(), 0);
    
    stack.push(5);
    EXPECT_EQ(stack.getCount(), 1);
    
    EXPECT_EQ(stack.pop(), 5);
    EXPECT_EQ(stack.getCount(), 0);
    
    stack.push(10);
    stack.push(20);
    stack.push(40);
    EXPECT_EQ(stack.getCount(), 3);
    EXPECT_EQ(stack.pop(), 40);
    EXPECT_EQ(stack.getCount(), 2);
    EXPECT_EQ(stack.pop(), 20);
    EXPECT_EQ(stack.getCount(), 1);
    EXPECT_EQ(stack.pop(), 10);
    EXPECT_EQ(stack.getCount(), 0);
}

TEST(Stack, GetCount) {
    Stack<int> stack;
    EXPECT_EQ(stack.getCount(), 0);
    
    stack.push(5);
    EXPECT_EQ(stack.getCount(), 1);
    
    EXPECT_EQ(stack.pop(), 5);
    EXPECT_EQ(stack.getCount(), 0);
    
    stack.push(10);
    stack.push(20);
    stack.push(40);
    EXPECT_EQ(stack.getCount(), 3);
    EXPECT_EQ(stack.pop(), 40);
    EXPECT_EQ(stack.getCount(), 2);
    EXPECT_EQ(stack.pop(), 20);
    EXPECT_EQ(stack.getCount(), 1);
    EXPECT_EQ(stack.pop(), 10);
    EXPECT_EQ(stack.getCount(), 0);
}

TEST(Stack, IsEmpty) {
    Stack<int> stack;
    EXPECT_TRUE(stack.isEmpty());
    
    stack.push(5);
    EXPECT_FALSE(stack.isEmpty());
    
    EXPECT_EQ(stack.pop(), 5);
    EXPECT_TRUE(stack.isEmpty());
    
    stack.push(10);
    EXPECT_FALSE(stack.isEmpty());
    stack.push(20);
    EXPECT_FALSE(stack.isEmpty());
    stack.push(40);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.pop(), 40);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.pop(), 20);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.pop(), 10);
    EXPECT_TRUE(stack.isEmpty());
}
