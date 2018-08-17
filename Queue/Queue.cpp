//
//  Queue.cpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#ifndef Queue_cpp
#define Queue_cpp

#include "Queue.hpp"

template <typename T>
void Queue<T>::enqueue(const T &newData)
{
    linkedList.insert(newData, newData);
}

template<typename T>
T Queue<T>::peek() const
{
    T outKey;
    T outValue;
    
    linkedList.findFromIndex(0, outKey, outValue);
    
    return outKey;
}

template <typename T>
T Queue<T>::dequeue()
{
    T outKey;
    T outValue;
    
    linkedList.removeFromIndex(0, outKey, outValue);
    
    return outKey;
}

template <typename T>
int Queue<T>::getCount() const
{
    return linkedList.getCount();
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return getCount() <= 0;
}

#endif
