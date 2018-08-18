//
//  BinarySearchTreeUnitTest.cpp
//  BinarySearchTree
//
//  Created by Richard Szeto on 8/15/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#include "BinarySearchTreeUnitTest.hpp"

TEST(BinarySearchTree, NoRotationInsert) {
    BinarySearchTree<int, int> bst;
    EXPECT_EQ(bst.getCount(), 0);
    EXPECT_EQ(bst.getHeight(), 0);
    bst.insert(1, 1);
    EXPECT_EQ(bst.getCount(), 1);
    EXPECT_EQ(bst.getHeight(), 1);
    bst.insert(0, 0);
    EXPECT_EQ(bst.getCount(), 2);
    EXPECT_EQ(bst.getHeight(), 2);
    bst.insert(2, 2);
    EXPECT_EQ(bst.getCount(), 3);
    EXPECT_EQ(bst.getHeight(), 2);
}

TEST(BinarySearchTree, LeftRotationInsert) {
    BinarySearchTree<int, int> bst;
    EXPECT_EQ(bst.getCount(), 0);
    EXPECT_EQ(bst.getHeight(), 0);
    bst.insert(1, 1);
    EXPECT_EQ(bst.getCount(), 1);
    EXPECT_EQ(bst.getHeight(), 1);
    bst.insert(2, 2);
    EXPECT_EQ(bst.getCount(), 2);
    EXPECT_EQ(bst.getHeight(), 2);
    bst.insert(3, 3);
    EXPECT_EQ(bst.getCount(), 3);
    EXPECT_EQ(bst.getHeight(), 2);
}

TEST(BinarySearchTree, RightRotationInsert) {
    BinarySearchTree<int, int> bst;
    EXPECT_EQ(bst.getCount(), 0);
    EXPECT_EQ(bst.getHeight(), 0);
    bst.insert(1, 1);
    EXPECT_EQ(bst.getCount(), 1);
    EXPECT_EQ(bst.getHeight(), 1);
    bst.insert(0, 0);
    EXPECT_EQ(bst.getCount(), 2);
    EXPECT_EQ(bst.getHeight(), 2);
    bst.insert(-1, -1);
    EXPECT_EQ(bst.getCount(), 3);
    EXPECT_EQ(bst.getHeight(), 2);
}

TEST(BinarySearchTree, LeftRightRotationInsert) {
    
}

TEST(BinarySearchTree, RightLeftRotationInsert) {
    
}

TEST(BinarySearchTree, NoRotationRemove) {
    BinarySearchTree<int, int> bst;
    EXPECT_EQ(bst.getCount(), 0);
    EXPECT_EQ(bst.getHeight(), 0);
    bst.insert(1, 1);
    EXPECT_EQ(bst.getCount(), 1);
    EXPECT_EQ(bst.getHeight(), 1);
    bst.insert(0, 0);
    EXPECT_EQ(bst.getCount(), 2);
    EXPECT_EQ(bst.getHeight(), 2);
    bst.insert(2, 2);
    EXPECT_EQ(bst.getCount(), 3);
    EXPECT_EQ(bst.getHeight(), 2);
    int outValue;
    bst.remove(1, outValue);
    EXPECT_EQ(bst.getCount(), 2);
    EXPECT_EQ(bst.getHeight(), 2);
}

TEST(BinarySearchTree, LeftRotationRemove) {
    
}

TEST(BinarySearchTree, RightRotationRemove) {
    
}

TEST(BinarySearchTree, LeftRightRotationRemove) {
    
}

TEST(BinarySearchTree, RightLeftRotationRemove) {
    
}

TEST(BinarySearchTree, GetHeight) {
    BinarySearchTree<int, int> bst;
    for (int i = 1; i <= 1000000; ++i) {
        bst.insert(i, i);
        EXPECT_GE(bst.getHeight(), floor(log2(bst.getCount())));
        EXPECT_LE(bst.getCount(), pow(2, bst.getHeight() + 1) - 1);
    }
    
    for (int i = 1000000; i >= 1; --i) {
        EXPECT_GE(bst.getHeight(), floor(log2(bst.getCount())));
        EXPECT_LE(bst.getCount(), pow(2, bst.getHeight() + 1) - 1);
        int outValue;
        EXPECT_TRUE(bst.remove(i, outValue));
    }
}

TEST(BinarySearchTree, GetCount) {
    BinarySearchTree<int ,int> bst;
    EXPECT_EQ(bst.getCount(), 0);
    for (int i = 1; i <= 1000000; ++i) {
        bst.insert(i, i);
        EXPECT_EQ(bst.getCount(), i);
    }
    
    for (int i = 1000000; i >= 1; --i) {
        EXPECT_EQ(bst.getCount(), i);
        int outValue;
        EXPECT_TRUE(bst.remove(i, outValue));
    }
    EXPECT_EQ(bst.getCount(), 0);
}

TEST(BinarySearchTree, IsEmpty) {
    BinarySearchTree<int ,int> bst;
    EXPECT_TRUE(bst.isEmpty());
    for (int i = 1; i <= 1000000; ++i) {
        bst.insert(i, i);
        EXPECT_FALSE(bst.isEmpty());
    }
    
    for (int i = 1000000; i >= 1; --i) {
        EXPECT_FALSE(bst.isEmpty());
        int outValue;
        EXPECT_TRUE(bst.remove(i, outValue));
    }
    EXPECT_TRUE(bst.isEmpty());
}
