//
//  main.cpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#include "LinkedList/LinkedList.cpp"
#include "Stack/Stack.cpp"
#include "Queue/Queue.cpp"
#include "BinarySearchTree/BinarySearchTree.cpp"

#include <iostream>

void insertAndPrintBinarySearchTree(BinarySearchTree<int, int>&, int);

void removeAndPrintBinarySearchTree(BinarySearchTree<int, int>&, int);

int main(int argc, const char * argv[])
{
    std::cout << "LinkedList" << std::endl;
    LinkedList<int, int> linkedList;
    
    linkedList.insert(0, 0);
    linkedList.insert(1, 1);
    linkedList.insert(2, 2);
    linkedList.insert(3, 3);
    
    int outKey = 0;
    int outValue = 0;
    linkedList.removeIndex(2, outKey, outValue);
    std::cout << linkedList.getCount() << std::endl;
    
    for (int nodeIndex = 0, listSize = linkedList.getCount(); nodeIndex < listSize; nodeIndex++)
    {
        if (linkedList.findFromIndex(nodeIndex, outKey, outValue))
        {
            std::cout << outKey << " " << outValue << std::endl;
        }
    }
    
    std::cout << "Stack" << std::endl;
    
    Stack<int> stack;
    
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.getCount() << std::endl;
    
    for (int nodeCount = 0, stackSize = stack.getCount(); nodeCount < stackSize; nodeCount++)
    {
        int peekValue = stack.peek();
        std::cout << peekValue << " " << stack.pop() << std::endl;
    }
    
    std::cout << "Queue" << std::endl;
    
    Queue<int> queue;
    
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << queue.getCount() << std::endl;
    
    for (int nodeCount = 0, queueSize = queue.getCount(); nodeCount < queueSize; nodeCount++)
    {
        std::cout << queue.dequeue() << std::endl;
    }
    
    std::cout << "BinarySearchTree" << std::endl;
    
    BinarySearchTree<int, int> binarySearchTree;
    
    insertAndPrintBinarySearchTree(binarySearchTree, 5);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 6);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 4);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 7);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 3);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 8);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 9);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 10);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 11);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 12);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 2);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 1);
    
    insertAndPrintBinarySearchTree(binarySearchTree, -100);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 0);
    
    insertAndPrintBinarySearchTree(binarySearchTree, -1);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 3);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 4);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 2);
    
    removeAndPrintBinarySearchTree(binarySearchTree, -1);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 9);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 7);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 10);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 12);
    
    insertAndPrintBinarySearchTree(binarySearchTree, 13);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 5);
    
    removeAndPrintBinarySearchTree(binarySearchTree, 6);
}

void insertAndPrintBinarySearchTree(BinarySearchTree<int, int> &binarySearchTree, int key)
{
    std::cout << "Inserting " << key << std::endl;
    binarySearchTree.insert(key, key);
    binarySearchTree.printTree();
    std::cout << std::endl;
}

void removeAndPrintBinarySearchTree(BinarySearchTree <int, int> &binarySearchTree, int key)
{
    std::cout << "Removing " << key << std::endl;
    int outValue = 0;
    binarySearchTree.remove(key, outValue);
    std::cout << "Value " << outValue << std::endl;
    binarySearchTree.printTree();
    std::cout << std::endl;
}
