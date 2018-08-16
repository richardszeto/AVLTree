//
//  main.cpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#include <iostream>
#include <string>
#include "./BinarySearchTree/BinarySearchTree.cpp"
#include "./LinkedList/LinkedList.cpp"
#include "./Queue/Queue.cpp"
#include "./Stack/Stack.cpp"
#include "gtest/gtest.h"

using namespace std;

int main(int argc, const char * argv[])
{
    
    testing::InitGoogleTest(&argc, (char**)argv);
    int result = RUN_ALL_TESTS();
    
    BinarySearchTree<int, int> bst;
    
    clock_t insertionStart;
    double insertionDuration;
    insertionStart = clock();
    for (int i = 0; i < 1000000; ++i) {
        bst.insert(i, i);
    }
    insertionDuration = (clock() - insertionStart) / (double)CLOCKS_PER_SEC;
    cout << "Insert 1,000,000 elements in ascending order." << endl;
    cout << "insertionDuration: " << insertionDuration << "." << endl;
    
    int outValue;
    clock_t findStart;
    double findDuration;
    findStart = clock();
    bst.find(999999, outValue);
    findDuration = (clock() - findStart) / (double)CLOCKS_PER_SEC;
    cout << "Find 1,000,000th element." << endl;
    cout << "findDuration: " << findDuration << "." << endl;
    
    return result;
}
