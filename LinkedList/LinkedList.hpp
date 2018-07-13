//
//  LinkedList.hpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/27/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>

template <typename T, typename K>
class LinkedList
{
public:
    class LinkedNode
    {
    private:
        T key_;
        K value_;
        std::unique_ptr<LinkedNode> link_;
        
    public:
        const T& key() { return key_; }
        const K& value() { return value_; }
        LinkedNode* link() { return link_.get(); }
        LinkedNode(const T &newKey, const K &newValue) : key_(newKey), value_(newValue), link_(nullptr) {}
        
        friend class LinkedList<T, K>;
    };
    
    LinkedList() : head_(nullptr), count_(0) {}
    void insert(const T &newKey, const K &newValue);
    void insertFromIndex(int index, const T &newKey, const K &newValue);
    bool remove(const T &key, K &outValue);
    bool removeIndex(int index, T &outKey, K &outValue);
    bool find(const T &key, K &outValue) const;
    bool findFromIndex(int index, T &outKey, K &outValue) const;
    const int getCount() const;
    bool isEmpty() const;
    
private:
    std::unique_ptr<LinkedNode> head_;
    int count_;
};

#endif /* LinkedList_hpp */
