//
//  Stack.hpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "../LinkedList/LinkedList.hpp"

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
