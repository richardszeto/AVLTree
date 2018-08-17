//
//  Stack.hpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

// LinkedList is a template, so implementation needs to be included
#include "../LinkedList/LinkedList.cpp"

#include <iostream>

template <typename T>
class Stack
{
public:
    Stack() : linkedList() {}
    void push(const T &newData);
    T peek() const;
    T pop();
    int getCount() const;
    bool isEmpty() const;
    
private:
    LinkedList<T, T> linkedList;
};

#endif /* Stack_hpp */
