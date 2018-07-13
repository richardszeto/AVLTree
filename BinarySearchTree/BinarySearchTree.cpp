//
//  BinarySearchTree.cpp
//  BinaryTree
//
//  Created by Richard Szeto on 6/28/18.
//  Copyright © 2018 Richard Szeto. All rights reserved.
//

#include "BinarySearchTree.hpp"

#include "../Queue/Queue.hpp"
#include "../Stack/Stack.hpp"

class TreeNode;

// Rotate right with z and y, then rotate left with x and y
// Finally attach y to g
template <typename T, typename K>
std::unique_ptr<typename BinarySearchTree<T, K>::TreeNode>* BinarySearchTree<T, K>::rotate_RightLeft(std::unique_ptr<TreeNode>*& g, std::unique_ptr<TreeNode>*& x, std::unique_ptr<TreeNode>*& z)
{
    // g is parent of x
    // x is parent of z

    //      x
    //  t1     z
    //      y     t4
    //    t2 t3
    
    //      x
    //  t1     y
    //      t2    z
    //          t3 t4
    
    //         y
    //     x      z
    //   t1 t2  t3 t4
    //
    
    //    g?  g?
    //      y
    bool xIsLeftChildOfG = false;
    
    if(g != nullptr)
    {
        if ((*g)->left() == x->get())
        {
            xIsLeftChildOfG = true;
        }
        else
        {
            xIsLeftChildOfG = false;
        }
    }
    
    // z is parent of y
    std::unique_ptr<TreeNode> y(std::move((*z)->left_));
    std::unique_ptr<TreeNode> t3(std::move(y->right_));
    (*z)->left_ = std::move(t3);
    y->right_ = std::move(*z);
    z = &y->right_;
    std::unique_ptr<TreeNode> t2(std::move(y->left_));
    (*x)->right_ = std::move(t2);
    y->left_ = std::move(*x);
    x = &y->left_;
    
    (*x)->updateHeight();
    (*z)->updateHeight();
    y->updateHeight();
    
    if(g != nullptr)
    {
        if (xIsLeftChildOfG)
        {
            (*g)->left_ = std::move(y);
            (*g)->updateHeight();
            return &(*g)->left_;
            
        }
        else
        {
            (*g)->right_ = std::move(y);
            (*g)->updateHeight();
            return &(*g)->right_;
        }
    }
    else
    {
        root_ = std::move(y);
        return &root_;
    }
}

// Rotate left with x and z
// Finally attach z to g
template <typename T, typename K>
std::unique_ptr<typename BinarySearchTree<T, K>::TreeNode>* BinarySearchTree<T, K>::rotate_Left(std::unique_ptr<TreeNode>*& g, std::unique_ptr<TreeNode>*& x, std::unique_ptr<TreeNode>*& z)
{
    // g is parent of x
    // x is parent of z
    
    //        x
    //   t1       z
    //         t23 t4
    
    //        z
    //   x        t4
    // t1 t23
    
    //    g?  g?
    //      z
    bool xIsLeftChildOfG = false;
    
    if (g != nullptr)
    {
        if ((*g)->left() == x->get())
        {
            xIsLeftChildOfG = true;
        }
        else
        {
            xIsLeftChildOfG = false;
        }
    }
    
    std::unique_ptr<TreeNode> t23(std::move((*z)->left_));
    (*x)->right_.swap(t23);
    z = &t23;
    (*z)->left_ = std::move(*x);
    x = &(*z)->left_;
    
    (*x)->updateHeight();
    (*z)->updateHeight();
    
    if (g != nullptr)
    {
        if (xIsLeftChildOfG)
        {
            (*g)->left_ = std::move(*z);
            (*g)->updateHeight();
            return &(*g)->left_;
        }
        else
        {
            (*g)->right_ = std::move(*z);
            (*g)->updateHeight();
            return &(*g)->right_;
        }
    }
    else
    {
        root_ = std::move(*z);
        return &root_;
    }
}

// Rotate left with z and y, then rotate right with x and y
// Finally attach y to g
template <typename T, typename K>
std::unique_ptr<typename BinarySearchTree<T, K>::TreeNode>* BinarySearchTree<T, K>::rotate_LeftRight(std::unique_ptr<TreeNode>*& g, std::unique_ptr<TreeNode>*& x, std::unique_ptr<TreeNode>*& z)
{
    // g is parent of x
    // x is parent of z
    // z is parent of y
    
    //          x
    //     z        t4
    // t1     y
    //      t2 t3
    
    //          x
    //      y        t4
    //   z     t3
    // t1 t2
    
    //          y
    //      z       x
    //    t1 t2   t3 t4
    
    //    g?  g?
    //      y
    bool xIsLeftChildOfG = false;
    
    if (g != nullptr)
    {
        if ((*g)->left() == x->get())
        {
            xIsLeftChildOfG = true;
        }
        else
        {
            xIsLeftChildOfG = false;
        }
    }
    
    std::unique_ptr<TreeNode> y(std::move((*z)->right_));
    std::unique_ptr<TreeNode> t2(std::move(y->left_));
    (*z)->right_ = std::move(t2);
    y->left_ = std::move(*z);
    z = &y->left_;
    std::unique_ptr<TreeNode> t3(std::move(y->right_));
    (*x)->left_ = std::move(t3);
    y->right_ = std::move(*x);
    x = &y->right_;
    
    (*x)->updateHeight();
    (*z)->updateHeight();
    y->updateHeight();
    
    if (g != nullptr)
    {
        if (xIsLeftChildOfG)
        {
            (*g)->left_ = std::move(y);
            (*g)->updateHeight();
            return &(*g)->left_;
        }
        else
        {
            (*g)->right_ = std::move(y);
            (*g)->updateHeight();
            return &(*g)->right_;
        }
    }
    else
    {
        root_ = std::move(y);
        return &root_;
    }
}

// Rotate right with x and z
// Finally attach z to g
template <typename T, typename K>
std::unique_ptr<typename BinarySearchTree<T, K>::TreeNode>* BinarySearchTree<T, K>::rotate_Right(std::unique_ptr<TreeNode>*& g, std::unique_ptr<TreeNode>*& x, std::unique_ptr<TreeNode>*& z)
{
    // g is parent of x
    // x is parent of z
    
    //          x
    //     z        t4
    //   t1 t23
    
    //          z
    //     t1       x
    //           t23 t4
    
    //    g?  g?
    //      z
    bool xIsLeftChildOfG = false;
    
    if (g != nullptr)
    {
        if ((*g)->left() == x->get())
        {
            xIsLeftChildOfG = true;
        }
        else
        {
            xIsLeftChildOfG = false;
        }
    }
    
    std::unique_ptr<TreeNode> t23(std::move((*z)->right_));
    (*x)->left_.swap(t23);
    z = &t23;
    (*z)->right_ = std::move(*x);
    x = &(*z)->right_;
    
    (*x)->updateHeight();
    (*z)->updateHeight();
    
    if (g != nullptr)
    {
        if (xIsLeftChildOfG)
        {
            (*g)->left_ = std::move(*z);
            (*g)->updateHeight();
            return &(*g)->left_;
        }
        else
        {
            (*g)->right_ = std::move(*z);
            (*g)->updateHeight();
            return &(*g)->right_;
        }
    }
    else
    {
        root_ = std::move(*z);
        return &root_;
    }
}

template <typename T, typename K>
void BinarySearchTree<T, K>::insert(const T &newKey, const K &newData)
{
    if (root_ == nullptr)
    {
        // variable node is type std::unique_ptr<TreeNode>, so the node variable is an object that
        // stores a pointer to a dynamically allocated object of type TreeNode. When the node variable
        // goes out of scope, the destructor of the stored pointer's object will be called
        // automatically.
        std::unique_ptr<TreeNode> node(new TreeNode(newKey, newData));
        
        // std::move is used to move the resources from one std::unique_ptr<TreeNode> object to
        // another. The source object will then have a null set to nullptr. This is required so that
        // the store pointer's object's destructor is not called.
        root_ = std::move(node);
        
        count_++;
        
        return;
    }
    
    // current is a pointer to std::unique_ptr<TreeNode>, and root_ is an object of type
    // std::unique_ptr<TreeNode>. To define current, we need the reference of root_.
    std::unique_ptr<TreeNode> *current = &root_;
    
    bool insertedNode = false;
    
    // We want to store pointers to std::unique_ptr<TreeNode> into the stack so that we are not making
    // copies of the actual std::unique_ptr<TreeNode> object. There should only be one
    // std::unique_ptr<TreeNode> per TreeNode object to avoid memory management conflicts.
    Stack<std::unique_ptr<TreeNode>*> ancestryStack;
    
    while (current->get() != nullptr)
    {
        // We need to push each node into the stack as we traverse down the tree. This will allow us
        // to traverse back up the tree when we attempt to balance it.
        ancestryStack.push(current);
        
        if (newKey < (*current)->key())
        {
            if ((*current)->left() != nullptr)
            {
                current = &(*current)->left_;
            }
            else
            {
                // We need to create a std::unique_ptr<TreeNode> object called node to store the
                // pointer to the new TreeNode object so that the pointer can be transfered to the
                // left child of current.
                std::unique_ptr<TreeNode> node(new TreeNode(newKey, newData));
                (*current)->left_ = std::move(node);
                
                // At this point, the pointer inside the node object points to nullptr due to
                // std::move. At the end of this scope, the node object will be removed from memory.
                
                current = &(*current)->left_;
                
                count_++;
                
                insertedNode = true;
                
                break;
            }
        }
        else if (newKey > current->get()->key())
        {
            if ((*current)->right() != nullptr)
            {
                current = &(*current)->right_;
            }
            else
            {
                std::unique_ptr<TreeNode> node(new TreeNode(newKey, newData));
                (*current)->right_ = std::move(node);
                
                current = &(*current)->right_;
                
                count_++;
                
                insertedNode = true;
                
                break;
            }
        }
        else
        {
            (*current)->data_ = newData;
            
            break;
        }
    }
    
    if (insertedNode)
    {
        while (!ancestryStack.isEmpty())
        {
            // Need parentOfCurrent. Rotation requires both parent and child
            // After rotation of parent and child, we need to attach new root of subtree to
            // grandparent
            std::unique_ptr<TreeNode>* parentOfCurrent = ancestryStack.pop();
            std::unique_ptr<TreeNode>* grandParentOfCurrent = nullptr;
            
            // current is right child of parentOfCurrent
            if (current->get() == (*parentOfCurrent)->right())
            {
                // parentOfCurrent is right heavy and has a balance factor of +2
                if ((*parentOfCurrent)->balanceFactor() > 1)
                {
                    if (!ancestryStack.isEmpty())
                    {
                        grandParentOfCurrent = ancestryStack.pop();
                        ancestryStack.push(grandParentOfCurrent);
                    }
                    
                    if ((*current)->balanceFactor() < 0)
                    {
                        rotate_RightLeft(grandParentOfCurrent, parentOfCurrent, current);
                    }
                    else
                    {
                        rotate_Left(grandParentOfCurrent, parentOfCurrent, current);
                    }
                    
                    // After rotation, we know entire tree is balanced. Tree was AVL balanced before
                    // insertion. After rotation, the height of tree will be same as before
                    // insertion.
                    break;
                }
                else
                {
                    // no rotation has been done this iteration, so we need to update the height of
                    // the parentOfCurrent node to account for any changes in its children from
                    // previous iterations.
                    (*parentOfCurrent)->updateHeight();
                    
                    // There's no change in height
                    if ((*parentOfCurrent)->balanceFactor() == 0)
                    {
                        break;
                    }
                    
                    current = parentOfCurrent;
                    continue;
                }
            }
            // current is left child of parentOfCurrent
            else
            {
                // parentOfCurrent is left heavy with a balanceFactor of -2
                if ((*parentOfCurrent)->balanceFactor() < -1)
                {
                    if (!ancestryStack.isEmpty())
                    {
                        grandParentOfCurrent = ancestryStack.pop();
                        ancestryStack.push(grandParentOfCurrent);
                    }
                    
                    if ((*current)->balanceFactor() > 0)
                    {
                        rotate_LeftRight(grandParentOfCurrent, parentOfCurrent, current);
                    }
                    else
                    {
                        rotate_Right(grandParentOfCurrent, parentOfCurrent, current);
                    }
                    
                    // After rotation, we know entire tree is balanced. Tree was AVL balanced before
                    // insertion. After rotation, the height of tree will be same as before
                    // insertion.
                    break;
                }
                else
                {
                    (*parentOfCurrent)->updateHeight();
                    
                    if ((*parentOfCurrent)->balanceFactor() == 0)
                    {
                        break;
                    }
                    
                    current = parentOfCurrent;
                    continue;
                }
            }
        }
    }
}

template <typename T, typename K>
bool BinarySearchTree<T, K>::remove(const T &key, K &outData)
{
    std::unique_ptr<TreeNode> *parentOfCurrent = nullptr;
    std::unique_ptr<TreeNode> *current = &root_;
    
    bool foundNodes = false;
    
    Stack<std::unique_ptr<TreeNode>*> ancestryStack;
    
    while (current->get() != nullptr && !foundNodes)
    {
        if (key < (*current)->key())
        {
            if ((*current)->left() != nullptr &&
                (*current)->left()->key() == key)
            {
                foundNodes = true;
            }
            
            ancestryStack.push(current);
            
            parentOfCurrent = current;
            current = &(*current)->left_;
        }
        else if (key > (*current)->key())
        {
            if ((*current)->right() != nullptr &&
                (*current)->right()->key() == key)
            {
                foundNodes = true;
            }
            
            ancestryStack.push(current);
            
            parentOfCurrent = current;
            current = &(*current)->right_;
        }
        else
        {
            foundNodes = true;
        }
    }
    
    if (!foundNodes)
    {
        return false;
    }
    
    outData = (*current)->data();
    
    if ((*current)->left() == nullptr &&
        (*current)->right() == nullptr)
    {
        // since we know that current has no children, we can safely destroy it.
        
        if (parentOfCurrent != nullptr)
        {
            if (key < (*parentOfCurrent)->key())
            {
                // use std::unique_ptr<TreeNode>.reset() to call the pointer's object's destructor,
                // then set the pointer to nullptr.
                (*parentOfCurrent)->left_.reset();
                
                // Since we are removing a node, the sibling of current may become too heavy, so we still need to keep track of where current used to be.
                current = &(*parentOfCurrent)->left_;
            }
            else
            {
                (*parentOfCurrent)->right_.reset();
                current = &(*parentOfCurrent)->right_;
            }
        }
        else
        {
            current->reset();
        }
    }
    else if ((*current)->left() == nullptr &&
             (*current)->right() != nullptr)
    {
        // current has a right child, so we need to transfer this child to the parentOfCurrent before
        // destroying the object that current points to.
        
        if (parentOfCurrent != nullptr)
        {
            if (key < (*parentOfCurrent)->key())
            {
                (*parentOfCurrent)->left_ = std::move((*current)->right_);
                current = &(*parentOfCurrent)->left_;
            }
            else
            {
                (*parentOfCurrent)->right_ = std::move((*current)->right_);
                current = &(*parentOfCurrent)->right_;
            }
        }
        else
        {
            // current has no parent, so we know that current points to root_. However, we cannot
            // transfer current's child to itself. We need a temporary std::unique_ptr<TreeNode>
            // object to transfer the internal TreeNode pointer.
            
            // root_ = std::move((*current)->right_); will not work, since the pointer's object's
            // destructor in root_ is called before we can grab root_'s right child.
            std::unique_ptr<TreeNode> temp(std::move((*current)->right_));
            root_ = std::move(temp);
            current = &root_;
        }
    }
    else if ((*current)->left() != nullptr &&
             (*current)->right() == nullptr)
    {
        // current has a left child, so we need to transfer this child to the parentOfCurrent before
        // destroying the object that current points to.
        
        if (parentOfCurrent != nullptr)
        {
            if (key < (*parentOfCurrent)->key())
            {
                (*parentOfCurrent)->left_ = std::move((*current)->left_);
                current = &(*parentOfCurrent)->left_;
            }
            else
            {
                (*parentOfCurrent)->right_ = std::move((*current)->left_);
                current = &(*parentOfCurrent)->right_;
            }
        }
        else
        {
            std::unique_ptr<TreeNode> temp(std::move((*current)->left_));
            root_ = std::move(temp);
            current = &root_;
        }
    }
    else
    {
        // current is either either slightly right heavy with a balance factor of +1 or has equal
        // children subtree heights with a balance factor of 0.
        if ((*current)->balanceFactor() >= 0)
        {
            // current is the node to be removed. We want to remove the current node while using the
            // left most node in current's right subtree as its replacement.
            std::unique_ptr<TreeNode> *tempParent = current;
            std::unique_ptr<TreeNode> *temp = &(*tempParent)->right_;
            
            // We need to keep track of nodes to traverse down after replacement, since the subtree
            // height decrease may be lower than where current resides.
            int ancestorCount = 0;
            
            while ((*temp)->left() != nullptr)
            {
                tempParent = temp;
                temp = &(*temp)->left_;
                ancestorCount++;
            }
            
            // Need another temporary variable to store temp because &(*tempParent)->left_ may be the
            // same as temp. temp is also a pointer, so the actual object temp is pointing to must not
            // go out of scope too early.
            std::unique_ptr<TreeNode> newTemp(std::move(*temp));
            
            if (tempParent != current)
            {
                (*tempParent)->left_ = std::move(newTemp->right_);
                (*tempParent)->updateHeight();
            }
            
            temp = &newTemp;
        
            (*temp)->left_ = std::move((*current)->left_);
            
            if (tempParent != current)
            {
                (*temp)->right_ = std::move((*current)->right_);
            }
            
            (*temp)->updateHeight();
            
            if (parentOfCurrent != nullptr)
            {
                if (key < (*parentOfCurrent)->key())
                {
                    (*parentOfCurrent)->left_ = std::move(*temp);
                    current = &(*parentOfCurrent)->left_;
                }
                else
                {
                    (*parentOfCurrent)->right_ = std::move(*temp);
                    current = &(*parentOfCurrent)->right_;
                }
            }
            else
            {
                root_ = std::move(*temp);
                current = &root_;
            }
            
            // After we finished finding current's replacement and manipulating smart pointers, we
            // need to add the ancestry traversal path to the stack for balance evaluation.
            ancestryStack.push(current);
            parentOfCurrent = current;
            current = &(*current)->right_;
            
            for (int nodeCount = 1; nodeCount <= ancestorCount; nodeCount++)
            {
                ancestryStack.push(current);
                parentOfCurrent = current;
                current = &(*current)->left_;
            }
        }
        // current is slightly left heavy with a balance factor to -1
        else
        {
            // current is the node to be removed. We want to remove the current node while using the
            // right most node in current's left subtree as its replacement.
            std::unique_ptr<TreeNode> *tempParent = current;
            std::unique_ptr<TreeNode> *temp = &(*current)->left_;
            
            int ancestorCount = 0;
            
            while ((*temp)->right() != nullptr)
            {
                tempParent = temp;
                temp = &(*temp)->right_;
                ancestorCount++;
            }
            
            std::unique_ptr<TreeNode> newTemp(std::move(*temp));
            
            if (tempParent != current)
            {
                (*tempParent)->right_ = std::move(newTemp->left_);
                (*tempParent)->updateHeight();
            }
            
            temp = &newTemp;
            
            (*temp)->right_ = std::move((*current)->right_);
            
            if (tempParent != current)
            {
                (*temp)->left_ = std::move((*current)->left_);
            }
            
            (*temp)->updateHeight();
            
            if (parentOfCurrent != nullptr)
            {
                if (key < (*parentOfCurrent)->key())
                {
                    (*parentOfCurrent)->left_ = std::move(*temp);
                    current = &(*parentOfCurrent)->left_;
                }
                else
                {
                    (*parentOfCurrent)->right_ = std::move(*temp);
                    current = &(*parentOfCurrent)->right_;
                }
            }
            else
            {
                root_ = std::move(*temp);
                current = &root_;
            }
            
            ancestryStack.push(current);
            parentOfCurrent = current;
            current = &(*current)->left_;
            
            for (int nodeCount = 1; nodeCount <= ancestorCount; nodeCount++)
            {
                ancestryStack.push(current);
                parentOfCurrent = current;
                current = &(*current)->right_;
            }
        }
    }
    
    count_--;
    
    while (!ancestryStack.isEmpty())
    {
        parentOfCurrent = ancestryStack.pop();
        std::unique_ptr<TreeNode> *siblingOfCurrent = nullptr;
        
        std::unique_ptr<TreeNode> *grandParentOfCurrent = nullptr;
        
        if (!ancestryStack.isEmpty())
        {
            grandParentOfCurrent = ancestryStack.pop();
            ancestryStack.push(grandParentOfCurrent);
        }
        
        if (current->get() == (*parentOfCurrent)->left())
        {
            if ((*parentOfCurrent)->balanceFactor() > 1)
            {
                // reverse of insertion. Need to use sibling of current as node of rotation, since
                // weight lifted from current ancestry may make sibling ancestry heavy.
                siblingOfCurrent = &(*parentOfCurrent)->right_;
                int balanceFactor = (*siblingOfCurrent)->balanceFactor();
                
                if (balanceFactor < 0)
                {
                    current = rotate_RightLeft(grandParentOfCurrent, parentOfCurrent, siblingOfCurrent);
                }
                else
                {
                    current = rotate_Left(grandParentOfCurrent, parentOfCurrent, siblingOfCurrent);
                    
                    // sibling of current has children with equal heights. Rotation after removal
                    // would have the same height as before removal, so we know entire tree is
                    // balanced since it was balanced before removal.
                    if (grandParentOfCurrent != nullptr && balanceFactor == 0)
                    {
                        break;
                    }
                }
            }
            else
            {
                (*parentOfCurrent)->updateHeight();
                
                if ((*parentOfCurrent)->balanceFactor() == 0)
                {
                    break;
                }
                
                current = parentOfCurrent;
                continue;
            }
        }
        else
        {
            if ((*parentOfCurrent)->balanceFactor() < -1)
            {
                siblingOfCurrent = &(*parentOfCurrent)->left_;
                int balanceFactor = (*siblingOfCurrent)->balanceFactor();
                
                if (balanceFactor > 0)
                {
                    current = rotate_LeftRight(grandParentOfCurrent, parentOfCurrent, siblingOfCurrent);
                }
                else
                {
                    current = rotate_Right(grandParentOfCurrent, parentOfCurrent, siblingOfCurrent);
                    
                    // sibling of current has children with equal heights. Rotation after removal
                    // would have the same height as before removal, so we know entire tree is
                    // balanced since it was balanced before removal.
                    if (grandParentOfCurrent != nullptr && balanceFactor == 0)
                    {
                        break;
                    }
                }
            }
            else
            {
                (*parentOfCurrent)->updateHeight();
                
                if ((*parentOfCurrent)->balanceFactor() == 0)
                {
                    break;
                }
                
                current = parentOfCurrent;
                continue;
            }
        }
    }
    
    return true;
}

template <typename T, typename K>
bool BinarySearchTree<T, K>::find(const T &key, K &outData) const
{
    TreeNode *current = root_.get();
    
    while (current != nullptr)
    {
        if (current->key() < key)
        {
            current = current->left();
        }
        else if (current->key() > key)
        {
            current = current->right();
        }
        else
        {
            outData = current->data();
            
            return true;
        }
    }
    
    return false;
}

template <typename T, typename K>
int BinarySearchTree<T, K>::getHeight() const
{
    // use breadth first traversal to calculate height of tree iteratively.
    
    if (root_ == nullptr)
    {
        return 0;
    }
    
    int height = 0;
    
    Queue<TreeNode*> queue;
    queue.enqueue(root_.get());
    
    do
    {
        int queueSize = queue.getCount();
        
        while (queueSize > 0)
        {
            TreeNode* node = queue.dequeue();
            
            if (node->left() != nullptr)
            {
                queue.enqueue(node->left());
            }
            
            if (node->right() != nullptr)
            {
                queue.enqueue(node->right());
            }
            
            queueSize--;
        }
        
        height++;
    } while (!queue.isEmpty());
    
    return height;
}

template <typename T, typename K>
void BinarySearchTree<T, K>::printTree() const
{
    // use breadth first traversal to print tree nodes at each height iteratively.
    
    if (root_ == nullptr)
    {
        return;
    }
    
    Queue<TreeNode*> queue;
    queue.enqueue(root_.get());
    
    do
    {
        int queueSize = queue.getCount();
        
        while (queueSize > 0)
        {
            TreeNode* node = queue.dequeue();
            
            if (node != nullptr)
            {
                std::cout << node->key() << " ";
                
                if (node->left() != nullptr)
                {
                    queue.enqueue(node->left());
                }
                else
                {
                    queue.enqueue(nullptr);
                }
                
                if (node->right() != nullptr)
                {
                    queue.enqueue(node->right());
                }
                else
                {
                    queue.enqueue(nullptr);
                }
            }
            else
            {
                std::cout << "nullptr ";
                
                queue.enqueue(nullptr);
                
                queue.enqueue(nullptr);
            }
            
            queueSize--;
        }
        
        std::cout << std::endl;
        
        Queue<TreeNode*> tempQueue;
        
        bool foundNonNullElement = false;
        
        while (!queue.isEmpty())
        {
            TreeNode* tempNode = queue.dequeue();
            
            if (tempNode != nullptr)
            {
                foundNonNullElement = true;
            }
            
            tempQueue.enqueue(tempNode);
        }
        
        if (foundNonNullElement)
        {
            while (!tempQueue.isEmpty())
            {
                queue.enqueue(tempQueue.dequeue());
            }
        }
    } while (!queue.isEmpty());
}

template <typename T, typename K>
int BinarySearchTree<T, K>::getCount() const
{
    return count_;
}

template <typename T, typename K>
bool BinarySearchTree<T, K>::isEmpty() const
{
    return getCount() <= 0;
}
