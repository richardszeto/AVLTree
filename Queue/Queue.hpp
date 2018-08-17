//
//  Queue.hpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

// LinkedList is a template, so implementation needs to be included
#include "../LinkedList/LinkedList.cpp"

#include <iostream>

template <typename T>
class Queue
{
private:
    LinkedList<T, T> linkedList;
    
public:
    Queue() : linkedList() {}
    void enqueue(const T &newData);
    T peek() const;
    T dequeue();
    int getCount() const;
    bool isEmpty() const;
};

#endif /* Queue_hpp */
