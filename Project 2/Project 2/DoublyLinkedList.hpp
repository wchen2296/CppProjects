//
//  DoublyLinkedList.hpp
//  Project 2
//
//  Created by William Chen on 6/13/22.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include "DoubleNode.hpp"
#include <iostream>
template<class ItemType>
class DoublyLinkedList{
public:
    DoublyLinkedList();
    //copy constuctor
    DoublyLinkedList(const DoublyLinkedList<ItemType>& list);
    ~DoublyLinkedList();
    bool insert(const ItemType& item,const int& position);
    bool remove(const int& position);
    int getSize()const;
    DoubleNode<ItemType>* getHeadPtr()const;
    DoubleNode<ItemType>* getAtPos(const int& pos)const;
    bool isEmpty()const;
    void clear();
    void display()const;
    void displayBackwards()const;
    DoublyLinkedList<ItemType>interleave(const DoublyLinkedList<ItemType>& list);
    
    
private:
    DoubleNode<ItemType>* HeadPtr;//pointer to head ptr
    DoubleNode<ItemType>* first_;//first node
    DoubleNode<ItemType>* last_;//last node
    int itemCount;//tracks amount of items
    
};
#include "DoublyLinkedList.cpp"
#endif /* DoublyLinkedList_hpp */
