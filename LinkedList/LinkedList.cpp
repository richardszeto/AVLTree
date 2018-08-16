//
//  LinkedList.cpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#include "LinkedList.hpp"

template <typename T, typename K>
void LinkedList<T, K>::insert(const T &newKey, const K &newValue)
{
    std::unique_ptr<LinkedNode> node(new LinkedNode(newKey, newValue));
    
    if (head_ == nullptr)
    {
        head_ = std::move(node);
    }
    else
    {
        LinkedNode *current = head_.get();
        
        while (current->link() != nullptr)
        {
            current = current->link();
        }
        
        current->link_ = std::move(node);
    }
    
    count_++;
}

template <typename T, typename K>
void LinkedList<T, K>::insertFromIndex(int index, const T &newKey, const K &newValue)
{
    if (index < 0 || index > count_) return;
    
    LinkedNode *prev = nullptr;
    LinkedNode *current = head_.get();
    
    for (int nodeIndex = 0; nodeIndex < index; nodeIndex++)
    {
        prev = current;
        current = current->link();
    }
    
    std::unique_ptr<LinkedNode> nodeToInsert(new LinkedNode(newKey, newValue));
    
    if (prev == nullptr)
    {
        nodeToInsert->link_ = std::move(head_);
        head_ = std::move(nodeToInsert);
    }
    else
    {
        nodeToInsert->link_ = std::move(prev->link_);
        prev->link_ = std::move(nodeToInsert);
    }
    
    count_++;
}

template <typename T, typename K>
bool LinkedList<T, K>::remove(const T &key, K &outValue)
{
    LinkedNode *prev = nullptr;
    LinkedNode *current = head_.get();
    
    while (current != nullptr)
    {
        if (current->key() == key)
        {
            outValue = current->value();
            
            if (prev == nullptr)
            {
                head_ = std::move(current->link_);
            }
            else
            {
                prev->link_ = std::move(current->link_);
            }
            
            count_--;
            
            return true;
        }
        
        prev = current;
        current = current->link();
    }
    
    return false;
}

template <typename T, typename K>
bool LinkedList<T, K>::removeFromIndex(int index, T &outKey, K &outValue)
{
    if (index < 0 || index > getCount() - 1)
    {
        return false;
    }
    
    LinkedNode *prev = nullptr;
    LinkedNode *current = head_.get();
    
    for (int nodeIndex = 0; nodeIndex < index; nodeIndex++)
    {
        prev = current;
        current = current->link();
    }
    
    outKey = current->key();
    outValue = current->value();
    
    if (prev == nullptr)
    {
        head_ = std::move(current->link_);
    }
    else
    {
        prev->link_ = std::move(current->link_);
    }
    
    count_--;
    
    return true;
}

template <typename T, typename K>
bool LinkedList<T, K>::find(const T &key, K &outValue) const
{
    LinkedNode *current = head_.get();
    
    while (current != nullptr)
    {
        if (current->key() == key)
        {
            outValue = current->value();
            
            return true;
        }
        
        current = current->link();
    }
    
    return false;
}

template <typename T, typename K>
bool LinkedList<T, K>::findFromIndex(int index, T &outKey, K &outValue) const
{
    if (index < 0 || index > getCount() - 1)
    {
        return false;
    }
    
    LinkedNode *current = head_.get();
    
    for (int nodeIndex = 0; nodeIndex < index; nodeIndex++)
    {
        current = current->link();
    }
    
    outKey = current->key();
    outValue = current->value();
    
    return true;
}

template <typename T, typename K>
const int LinkedList<T, K>::getCount() const
{
    return count_;
}

template <typename T, typename K>
bool LinkedList<T, K>::isEmpty() const
{
    return getCount() <= 0;
}
