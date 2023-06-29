//
//  DoubleNode.cpp
//  Project 2
//
//  Created by William Chen on 6/13/22.
//

#include "DoubleNode.hpp"
//constuctors
template<class ItemType>
DoubleNode<ItemType>::DoubleNode():item_(0),next_(nullptr),prev_(nullptr){}
//parameterized constructor
template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& item):item_(item),next_(nullptr),prev_(nullptr){}
//parameterized construuctor
template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& item, DoubleNode* next_ptr, DoubleNode* prev_ptr):item_(item),next_(next_ptr),prev_(prev_ptr){}

template<class ItemType>
ItemType DoubleNode<ItemType>::getItem()const{
    return item_;
}

template<class ItemType>
bool DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *ptr){
    next_=ptr;
    return true;
}

template <class ItemType>
bool DoubleNode<ItemType>::setPrev(DoubleNode<ItemType> *ptr){
    prev_=ptr;
    return true;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
  return next_;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() const
{
  return prev_;
}
