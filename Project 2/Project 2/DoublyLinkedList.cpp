//
//  DoublyLinkedList.cpp
//  Project 2
//
//  Created by William Chen on 6/13/22.
//

#include "DoublyLinkedList.hpp"
//constuctor
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList():first_(nullptr),last_(nullptr),itemCount(0){}

//copy constructor
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& list){
    itemCount=list.itemCount;
    DoubleNode<ItemType>* original_chain_ptr=list.first_;
    
if(original_chain_ptr==nullptr){
    first_=nullptr;
    last_=nullptr;
}
else{
    first_=new DoubleNode<ItemType>(original_chain_ptr->getItem());
    DoubleNode<ItemType>* new_chain_ptr=first_;
    original_chain_ptr=original_chain_ptr->getNext();
    while(original_chain_ptr!=nullptr){
        ItemType next_item=original_chain_ptr->getItem();
        DoubleNode<ItemType>* new_node_ptr=new DoubleNode<ItemType>(next_item);
        new_chain_ptr->setNext(new_node_ptr);
        new_chain_ptr=new_chain_ptr->getNext();
        original_chain_ptr=original_chain_ptr->getNext();
    }
  last_=new
    
    
}
}
template<class Itemtype>
DoublyLinkedList<Itemtype>::~DoublyLinkedList(){
    DoubleNode<Itemtype>* temp=first_;
    while (first_!=nullptr) {
        first_=first_->getNext();
        delete temp;
        temp=first_;
    
    }
    delete first_;
    delete last_;
}

template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item,const int& position){
    DoubleNode<ItemType>* new_node_ptr=new DoubleNode<ItemType>(item);
    DoubleNode<ItemType>* pos_ptr= getAtPos(position);
    //attach new node to chain
    if(first_==nullptr){
        //inseting first node
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrev(nullptr);
        first_=new_node_ptr;
        last_=new_node_ptr;
    }
    else if(pos_ptr==first_){
        //this is inserting new node at the head
        new_node_ptr->setNext(first_);
        new_node_ptr->setPrev(nullptr);
        first_->setPrev(new_node_ptr);
        first_=new_node_ptr;
    }
    else if (pos_ptr==nullptr)//inserting at end
    {
        new_node_ptr->setNext(nullptr);
        new_node_ptr->setPrev(last_);
        last_->setNext(new_node_ptr);
        last_= new_node_ptr;
    }
    else//inserting anywhere else
    {
        new_node_ptr->setNext(pos_ptr);
        new_node_ptr->setPrev(pos_ptr->getPrev());
        pos_ptr->getPrev()->setNext(new_node_ptr);
        pos_ptr->setPrev(new_node_ptr);
    }
    itemCount++;
    return true;
}

template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position){
    DoubleNode<ItemType>* pos_ptr=getAtPos(position);
    if(pos_ptr==nullptr){
        return false;
    }
    else{
        if(pos_ptr==first_){
            first_=pos_ptr->getNext();
            first_->setPrev(nullptr);
            pos_ptr->setNext(nullptr);
            delete pos_ptr;
            pos_ptr=nullptr;
        }
        else if (pos_ptr==last_){
            last_=pos_ptr->getPrev();
            last_->setNext(nullptr);
            pos_ptr->setPrev(nullptr);
            delete pos_ptr;
            pos_ptr=nullptr;
        }
        else{
            pos_ptr->getPrev()->setNext(pos_ptr->getNext());
            pos_ptr->getNext()->setPrev(pos_ptr->getPrev());
            pos_ptr->setNext(nullptr);
            pos_ptr->setPrev(nullptr);
            delete pos_ptr;
            pos_ptr=nullptr;
        }
    }
    itemCount--;
    return true;
    
}

template<class ItemType>
int DoublyLinkedList<ItemType>::getSize()const{
    return itemCount;
}

template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr()const{
    return first_;
}

template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos)const{
    DoubleNode<ItemType>* find_ptr=first_;
    int count{1};
    while (count<pos) {
        find_ptr=find_ptr->getNext();
        count++;
    }
    return find_ptr;
}

template <class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty()const{
    if (first_==nullptr) {
        return true;
    }
    else{
        return false;
    }
}

template<class ItemType>
void DoublyLinkedList<ItemType>::clear(){
    itemCount=0;//hmmm
    first_=nullptr;
    for(int i{0};i<itemCount;i++){
        remove(i);
    }
}

template<class ItemType>
void DoublyLinkedList<ItemType>::display()const{
    DoubleNode<ItemType>* temp=first_;//sets temp ptr to first
    while (temp!=nullptr && temp!=last_) {
        std::cout<<temp->getItem()<<" ";//prints item
        temp=temp->getNext(); //goes to next node
    }
    std::cout<<last_->getItem()<<std::endl;
}

template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards()const{
    DoubleNode<ItemType>* temp=first_;//temp ptr to first

    while (temp->getNext()!=nullptr) {//goes to the end of the list
        temp=temp->getNext();
    }
   // std::cout<<last_->getItem();
    while (temp!=nullptr && temp!=first_) //goes to previous null ptr&& temp != nullptr
    {
        std::cout<<temp->getItem()<<" ";//prints item
        temp=temp->getPrev();
    }
    std::cout<<first_->getItem()<<std::endl; 
}

template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &list){
    DoublyLinkedList<ItemType> ListB;
    DoubleNode<ItemType>* ptr1=list.first_;
    DoubleNode<ItemType>* ptr2=first_;
    int counter=1;
    while(ptr1 != nullptr|| ptr2!=nullptr){
        if(ptr2!=nullptr){
            ListB.insert(ptr2->getItem(),counter);
            ptr2=ptr2->getNext();
            counter++;
        }
        if(ptr1!=nullptr){
            ListB.insert(ptr1->getItem(),counter);
            ptr1=ptr1->getNext();
            counter++;
        }
    }
    return ListB;
}
