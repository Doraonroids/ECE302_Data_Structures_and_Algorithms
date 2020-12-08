//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"


template<class ItemType>
Stack<ItemType>::Stack()
{
	headPtr = NULL;
	currentSize = 0;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
}  // end destructor


template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return headPtr == NULL;
}  // end isEmpty


template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}  // end size


template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* temp = new Node<ItemType>(newItem, headPtr);
	headPtr = temp;
	temp = nullptr;
	currentSize ++;
	return true;
}  // end push

template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
	if(!isEmpty()){
		return headPtr->getItem();
	}else{
		throw logic_error("Cannot peek at empty stack");
	}
}  // end peek


template<class ItemType>
bool Stack<ItemType>::pop() 
{

	if(headPtr == NULL){
		std::cout << "UNDERFLOW\n";
		return false;
	}else{
		headPtr = headPtr->getNext();
		currentSize --;
		return true;
	}
}  // end pop


template<class ItemType>
void Stack<ItemType>::clear()
{
	while(headPtr != NULL){
		headPtr = headPtr->getNext();
	}
}  // end clear

