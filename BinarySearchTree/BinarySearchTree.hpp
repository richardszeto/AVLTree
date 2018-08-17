//
//  BinarySearchTree.hpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/28/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

// Queue and Stack are templates, so implementation needs to be included
#include "../Queue/Queue.cpp"
#include "../Stack/Stack.cpp"

#include <iostream>

template <typename T, typename K>
class BinarySearchTree
{
public:
    class TreeNode
    {
    private:
        T key_;
        K data_;
        std::unique_ptr<TreeNode> left_;
        std::unique_ptr<TreeNode> right_;
        int height_;
        
    public:
        const T& key() const { return key_; }
        const K& data() const { return data_; }
        TreeNode* left() const { return left_.get(); }
        TreeNode* right() const { return right_.get(); }
        const int height() const { return height_; }
        
        const int balanceFactor() const
        {
            int leftHeight = 0;
            int rightHeight = 0;
            
            if (left() != nullptr)
            {
                leftHeight = left()->height();
            }
            
            if (right() != nullptr)
            {
                rightHeight = right()->height();
            }
            
            return rightHeight - leftHeight;
        }
        
        void updateHeight()
        {
            int leftHeight = 0;
            int rightHeight = 0;
            
            if (left() != nullptr)
            {
                leftHeight = left()->height();
            }
            
            if (right() != nullptr)
            {
                rightHeight = right()->height();
            }
            
            if (leftHeight > rightHeight)
            {
                height_ = leftHeight + 1;
            }
            else
            {
                height_ = rightHeight + 1;
            }
        }
        
        TreeNode(const T &newKey, const K &newData) : key_(newKey), data_(newData), left_(nullptr), right_(nullptr), height_(1) {}
        
        friend class BinarySearchTree<T, K>;
    };
    
    BinarySearchTree() : root_(nullptr), count_(0) {}
    void insert(const T &newKey, const K &newData);
    bool remove(const T &key, K &outData);
    bool find(const T &key, K &outData) const;
    int getHeight() const;
    void printTree() const;
    int getCount() const;
    bool isEmpty() const;
    
private:
    std::unique_ptr<TreeNode> root_;
    int count_;
    
    std::unique_ptr<TreeNode>* rotate_RightLeft(std::unique_ptr<TreeNode>*& g, std::unique_ptr<TreeNode>*& x, std::unique_ptr<TreeNode>*& z);
    std::unique_ptr<TreeNode>* rotate_Left(std::unique_ptr<TreeNode>*& g, std::unique_ptr<TreeNode>*& x, std::unique_ptr<TreeNode>*& z);
    std::unique_ptr<TreeNode>* rotate_LeftRight(std::unique_ptr<TreeNode>*& g, std::unique_ptr<TreeNode>*& x, std::unique_ptr<TreeNode>*& z);
    std::unique_ptr<TreeNode>* rotate_Right(std::unique_ptr<TreeNode>*& g, std::unique_ptr<TreeNode>*& x, std::unique_ptr<TreeNode>*& z);
};

#endif /* BinarySearchTree_hpp */
