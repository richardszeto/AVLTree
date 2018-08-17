//
//  LinkedListUnitTest.cpp
//  BinarySearchTree
//
//  Created by Richard Szeto on 8/15/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#include "LinkedListUnitTest.hpp"

TEST(LinkedList, Insert) {
    LinkedList<int, int> linkedList;
    EXPECT_EQ(linkedList.getCount(), 0);
    linkedList.insert(1, 1);
    EXPECT_EQ(linkedList.getCount(), 1);
    linkedList.insert(2, 2);
    EXPECT_EQ(linkedList.getCount(), 2);
    linkedList.insert(3, 3);
    EXPECT_EQ(linkedList.getCount(), 3);
    
    int outKey = 0;
    int outValue = 0;
    linkedList.findFromIndex(0, outKey, outValue);
    EXPECT_EQ(outKey, 1);
    EXPECT_EQ(outValue, 1);
    EXPECT_TRUE(linkedList.find(1, outValue));
    EXPECT_EQ(outValue, 1);
    
    linkedList.findFromIndex(1, outKey, outValue);
    EXPECT_EQ(outKey, 2);
    EXPECT_EQ(outValue, 2);
    EXPECT_TRUE(linkedList.find(2, outValue));
    EXPECT_EQ(outValue, 2);
    
    linkedList.findFromIndex(2, outKey, outValue);
    EXPECT_EQ(outKey, 3);
    EXPECT_EQ(outValue, 3);
    EXPECT_TRUE(linkedList.find(3, outValue));
    EXPECT_EQ(outValue, 3);
}

TEST(LinkedList, InsertFromIndex) {
    LinkedList<int, int> linkedList;
    EXPECT_EQ(linkedList.getCount(), 0);
    
    // insert from index in empty list
    linkedList.insertFromIndex(0, 2, 2);
    EXPECT_EQ(linkedList.getCount(), 1);
    
    //insert from index from head
    linkedList.insertFromIndex(0, 1, 1);
    EXPECT_EQ(linkedList.getCount(), 2);
    
    // insert from index from tail
    linkedList.insertFromIndex(2, 4, 4);
    EXPECT_EQ(linkedList.getCount(), 3);
    
    // insert from index in middle
    linkedList.insertFromIndex(2, 3, 3);
    EXPECT_EQ(linkedList.getCount(), 4);
    
    // insert from invalid index
    linkedList.insertFromIndex(-1, 5, 5);
    EXPECT_EQ(linkedList.getCount(), 4);
    
    int outKey = 0;
    int outValue = 0;
    linkedList.findFromIndex(0, outKey, outValue);
    EXPECT_EQ(outKey, 1);
    EXPECT_EQ(outValue, 1);
    EXPECT_TRUE(linkedList.find(1, outValue));
    EXPECT_EQ(outValue, 1);
    
    linkedList.findFromIndex(1, outKey, outValue);
    EXPECT_EQ(outKey, 2);
    EXPECT_EQ(outValue, 2);
    EXPECT_TRUE(linkedList.find(2, outValue));
    EXPECT_EQ(outValue, 2);
    
    linkedList.findFromIndex(2, outKey, outValue);
    EXPECT_EQ(outKey, 3);
    EXPECT_EQ(outValue, 3);
    EXPECT_TRUE(linkedList.find(3, outValue));
    EXPECT_EQ(outValue, 3);
    
    linkedList.findFromIndex(3, outKey, outValue);
    EXPECT_EQ(outKey, 4);
    EXPECT_EQ(outValue, 4);
    EXPECT_TRUE(linkedList.find(4, outValue));
    EXPECT_EQ(outValue, 4);
}

TEST(LinkedList, Remove) {
    LinkedList<int, int> linkedList;
    int outValue = 0;
    // try to remove from empty linked list
    EXPECT_FALSE(linkedList.remove(5, outValue));
    EXPECT_EQ(linkedList.getCount(), 0);
    
    linkedList.insert(1, 1);
    linkedList.insert(2, 2);
    linkedList.insert(3, 3);
    linkedList.insert(4, 4);
    EXPECT_EQ(linkedList.getCount(), 4);
    
    // try to remove non existent element
    EXPECT_FALSE(linkedList.remove(6, outValue));
    EXPECT_EQ(linkedList.getCount(), 4);
    
    // remove from head
    EXPECT_TRUE(linkedList.remove(1, outValue));
    EXPECT_EQ(outValue, 1);
    EXPECT_EQ(linkedList.getCount(), 3);
    
    // remove from middle
    EXPECT_TRUE(linkedList.remove(3, outValue));
    EXPECT_EQ(outValue, 3);
    EXPECT_EQ(linkedList.getCount(), 2);
    
    // remove from tail
    EXPECT_TRUE(linkedList.remove(4, outValue));
    EXPECT_EQ(outValue, 4);
    EXPECT_EQ(linkedList.getCount(), 1);
}

TEST(LinkedList, RemoveFromIndex) {
    LinkedList<int, int> linkedList;
    int outKey = 0;
    int outValue = 0;
    
    // try to remove from index from empty linked list
    EXPECT_FALSE(linkedList.removeFromIndex(0, outKey, outValue));
    
    linkedList.insert(1, 1);
    linkedList.insert(2, 2);
    linkedList.insert(3, 3);
    linkedList.insert(4, 4);
    linkedList.insert(5, 5);
    EXPECT_EQ(linkedList.getCount(), 5);
    
    // try to remove from non-existent index
    EXPECT_FALSE(linkedList.removeFromIndex(8, outKey, outValue));
    EXPECT_EQ(linkedList.getCount(), 5);
    
    // try to remove from invalid index
    EXPECT_FALSE(linkedList.removeFromIndex(-1, outKey, outValue));
    EXPECT_EQ(linkedList.getCount(), 5);
    
    // try to remove from index from head
    EXPECT_TRUE(linkedList.removeFromIndex(0, outKey, outValue));
    EXPECT_EQ(linkedList.getCount(), 4);
    EXPECT_EQ(outKey, 1);
    EXPECT_EQ(outValue, 1);
    
    // try to remove from index from middle
    EXPECT_TRUE(linkedList.removeFromIndex(1, outKey, outValue));
    EXPECT_EQ(linkedList.getCount(), 3);
    EXPECT_EQ(outKey, 3);
    EXPECT_EQ(outValue, 3);
    
    // try to remove from index from tail
    EXPECT_TRUE(linkedList.removeFromIndex(2, outKey, outValue));
    EXPECT_EQ(linkedList.getCount(), 2);
    EXPECT_EQ(outKey, 5);
    EXPECT_EQ(outValue, 5);
}

TEST(LinkedList, Find) {
    LinkedList<int, int> linkedList;
    EXPECT_EQ(linkedList.getCount(), 0);
    
    int outValue = 0;
    
    // try to find from an empty linked list
    EXPECT_FALSE(linkedList.find(1, outValue));
    EXPECT_EQ(linkedList.getCount(), 0);
    
    linkedList.insert(1, 1);
    linkedList.insert(2, 2);
    linkedList.insert(3, 3);
    linkedList.insert(4, 4);
    linkedList.insert(5, 5);
    EXPECT_EQ(linkedList.getCount(), 5);
    
    // try to find a non-existent element
    EXPECT_FALSE(linkedList.find(7, outValue));
    EXPECT_EQ(linkedList.getCount(), 5);
    
    EXPECT_TRUE(linkedList.find(1, outValue));
    EXPECT_EQ(outValue, 1);
    EXPECT_EQ(linkedList.getCount(), 5);
    
    EXPECT_TRUE(linkedList.find(2, outValue));
    EXPECT_EQ(outValue, 2);
    EXPECT_EQ(linkedList.getCount(), 5);
    
    EXPECT_TRUE(linkedList.find(3, outValue));
    EXPECT_EQ(outValue, 3);
    EXPECT_EQ(linkedList.getCount(), 5);
    
    EXPECT_TRUE(linkedList.find(4, outValue));
    EXPECT_EQ(outValue, 4);
    EXPECT_EQ(linkedList.getCount(), 5);
    
    EXPECT_TRUE(linkedList.find(5, outValue));
    EXPECT_EQ(outValue, 5);
    EXPECT_EQ(linkedList.getCount(), 5);
}

TEST(LinkedList, FindFromIndex) {
    LinkedList<int, int> linkedList;
    EXPECT_EQ(linkedList.getCount(), 0);
    
    int outKey = 0;
    int outValue = 0;
    
    // try to find from index in an empty linked list
    EXPECT_FALSE(linkedList.findFromIndex(0, outKey, outValue));
    EXPECT_FALSE(linkedList.findFromIndex(10, outKey, outValue));
    
    linkedList.insert(1, 1);
    linkedList.insert(2, 2);
    linkedList.insert(3, 3);
    linkedList.insert(4, 4);
    linkedList.insert(5, 5);
    EXPECT_EQ(linkedList.getCount(), 5);
    
    // try to find from non-existent index
    EXPECT_FALSE(linkedList.findFromIndex(5, outKey, outValue));
    EXPECT_EQ(linkedList.getCount(), 5);
    
    // try to find from invalid index
    EXPECT_FALSE(linkedList.findFromIndex(-1, outKey, outValue));
    EXPECT_EQ(linkedList.getCount(), 5);
    
    for (int i = 0; i < 5; ++i) {
        EXPECT_TRUE(linkedList.findFromIndex(i, outKey, outValue));
        EXPECT_EQ(outKey, i + 1);
        EXPECT_EQ(outValue, i + 1);
        EXPECT_EQ(linkedList.getCount(), 5);
    }
}

TEST(LinkedList, GetCount) {
    LinkedList<int, int> linkedList;
    EXPECT_EQ(linkedList.getCount(), 0);
    int outValue;
    
    linkedList.insert(1, 1);
    EXPECT_EQ(linkedList.getCount(), 1);
    linkedList.insert(2, 2);
    EXPECT_EQ(linkedList.getCount(), 2);
    linkedList.insert(3, 3);
    EXPECT_EQ(linkedList.getCount(), 3);
    linkedList.remove(2, outValue);
    EXPECT_EQ(linkedList.getCount(), 2);
    linkedList.insert(10, 10);
    EXPECT_EQ(linkedList.getCount(), 3);
    linkedList.remove(1, outValue);
    EXPECT_EQ(linkedList.getCount(), 2);
    linkedList.remove(3, outValue);
    EXPECT_EQ(linkedList.getCount(), 1);
    linkedList.remove(10, outValue);
    EXPECT_EQ(linkedList.getCount(), 0);
    linkedList.insert(20, 20);
    EXPECT_EQ(linkedList.getCount(), 1);
    linkedList.remove(20, outValue);
    EXPECT_EQ(linkedList.getCount(), 0);
}

TEST(LinkedList, IsEmpty) {
    LinkedList<int, int> linkedList;
    
    int outValue;
    
    EXPECT_TRUE(linkedList.isEmpty());
    
    linkedList.insert(1, 1);
    EXPECT_FALSE(linkedList.isEmpty());
    linkedList.insert(2, 2);
    EXPECT_FALSE(linkedList.isEmpty());
    linkedList.remove(2, outValue);
    EXPECT_FALSE(linkedList.isEmpty());
    linkedList.remove(1, outValue);
    EXPECT_TRUE(linkedList.isEmpty());
    linkedList.insert(10, 10);
    EXPECT_FALSE(linkedList.isEmpty());
    linkedList.remove(10, outValue);
    EXPECT_TRUE(linkedList.isEmpty());
}
