//
//  Stack.cpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#ifndef Stack_cpp
#define Stack_cpp

#include "Stack.hpp"

template <typename T>
void Stack<T>::push(const T &newData)
{
    linkedList.insert(newData, newData);
}

template <typename T>
T Stack<T>::peek() const
{
    T outKey;
    T outValue;
    
    linkedList.findFromIndex(linkedList.getCount() - 1, outKey, outValue);
    
    return outKey;
}

template<typename T>
T Stack<T>::pop()
{
    T outKey;
    T outValue;
    
    linkedList.removeFromIndex(getCount() - 1, outKey, outValue);
    
    return outKey;
}

template <typename T>
int Stack<T>::getCount() const
{
    return linkedList.getCount();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return getCount() <= 0;
}

#endif
