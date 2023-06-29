//
//  DoubleNode.hpp
//  Project 2
//
//  Created by William Chen on 6/13/22.
//

#ifndef DoubleNode_hpp
#define DoubleNode_hpp

#include <iostream>
template <class ItemType>
class DoubleNode{
public:
    DoubleNode();
    DoubleNode(const ItemType& item);
    DoubleNode(const ItemType& item,DoubleNode<ItemType>* next_ptr, DoubleNode<ItemType>* prev_ptr);
    ItemType getItem()const;
    bool setNext(DoubleNode* ptr);
    bool setPrev(DoubleNode* ptr);
    DoubleNode<ItemType>* getPrev() const;
    DoubleNode<ItemType>* getNext() const;
    
    
private:
    ItemType item_;
    DoubleNode<ItemType>* prev_;
    DoubleNode<ItemType>* next_;
    
    
    
};
#include "DoubleNode.cpp"
#endif /* DoubleNode_hpp */
