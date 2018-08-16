//
//  QueueUnitTest.cpp
//  BinarySearchTree
//
//  Created by Richard Szeto on 8/15/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#include "QueueUnitTest.hpp"
#include "Queue.cpp"
#include "gtest/gtest.h"

TEST(Queue, Enqueue) {
    Queue<int> queue;
    EXPECT_EQ(queue.getCount(), 0);
    
    queue.enqueue(1);
    EXPECT_EQ(queue.getCount(), 1);
    
    queue.enqueue(2);
    EXPECT_EQ(queue.getCount(), 2);
    
    queue.enqueue(3);
    EXPECT_EQ(queue.getCount(), 3);
}

TEST(Queue, Peek) {
    Queue<int> queue;
    EXPECT_EQ(queue.getCount(), 0);
    
    queue.enqueue(1);
    EXPECT_EQ(queue.peek(), 1);
    
    queue.enqueue(5);
    EXPECT_EQ(queue.peek(), 1);
    
    queue.enqueue(10);
    EXPECT_EQ(queue.peek(), 1);
    
    EXPECT_EQ(queue.dequeue(), 1);
    EXPECT_EQ(queue.peek(), 5);
    
    EXPECT_EQ(queue.dequeue(), 5);
    EXPECT_EQ(queue.peek(), 10);
    
    EXPECT_EQ(queue.dequeue(), 10);
}

TEST(Queue, Dequeue) {
    Queue<int> queue;
    EXPECT_EQ(queue.getCount(), 0);
    
    queue.enqueue(1);
    EXPECT_EQ(queue.peek(), 1);
    
    queue.enqueue(5);
    EXPECT_EQ(queue.peek(), 1);
    
    queue.enqueue(10);
    EXPECT_EQ(queue.peek(), 1);
    
    EXPECT_EQ(queue.dequeue(), 1);
    EXPECT_EQ(queue.peek(), 5);
    
    EXPECT_EQ(queue.dequeue(), 5);
    EXPECT_EQ(queue.peek(), 10);
    
    EXPECT_EQ(queue.dequeue(), 10);
}

TEST(Queue, GetCount) {
    Queue<int> queue;
    EXPECT_EQ(queue.getCount(), 0);
    
    queue.enqueue(1);
    EXPECT_EQ(queue.getCount(), 1);
    
    queue.enqueue(2);
    EXPECT_EQ(queue.getCount(), 2);
    
    queue.enqueue(3);
    EXPECT_EQ(queue.getCount(), 3);
    
    EXPECT_EQ(queue.dequeue(), 1);
    EXPECT_EQ(queue.getCount(), 2);
    
    EXPECT_EQ(queue.dequeue(), 2);
    EXPECT_EQ(queue.getCount(), 1);
    
    EXPECT_EQ(queue.dequeue(), 3);
    EXPECT_EQ(queue.getCount(), 0);
}

TEST(Queue, IsEmpty) {
    Queue<int> queue;
    EXPECT_TRUE(queue.isEmpty());
    
    queue.enqueue(1);
    EXPECT_FALSE(queue.isEmpty());
    
    queue.enqueue(2);
    EXPECT_FALSE(queue.isEmpty());
    
    queue.enqueue(3);
    EXPECT_FALSE(queue.isEmpty());
    
    EXPECT_EQ(queue.dequeue(), 1);
    EXPECT_FALSE(queue.isEmpty());
    
    EXPECT_EQ(queue.dequeue(), 2);
    EXPECT_FALSE(queue.isEmpty());
    
    EXPECT_EQ(queue.dequeue(), 3);
    EXPECT_TRUE(queue.isEmpty());
}
