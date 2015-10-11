#include "list.h"
#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

/**
*	const_interator class
**/

//Constructor
template < typename Data >
List<Data>::const_iterator::const_iterator(List::Node * p) : 
	current { p }{}

//Return the value of current node
template < typename Data >
const Data & List<Data>::const_iterator::operator*() const{
	if(current != nullptr)
		return current->info;
	else 
		throw runtime_error("Null point exception!");
}

//Return the next node
template < typename Data >
typename List<Data>::const_iterator & List<Data>::const_iterator::operator++(){
	if(current != nullptr){
		current = current->next;
		return *this;
	}
	else 
		throw runtime_error("Null point exception!");
}

//Return the next node
template < typename Data >
typename List<Data>::const_iterator List<Data>::const_iterator::operator++( int ){
	if(current != nullptr){
		current = current->next;
		return *this;
	}
	else 
		throw runtime_error("Null point exception!");
}
//Return the previous node
template < typename Data >
typename List<Data>::const_iterator & List<Data>::const_iterator::operator--(){
	if(current != nullptr){
		current = current->previous;
		return *this;
	}
	else 
		throw runtime_error("Null point exception!");
}

//Return the previous node
template < typename Data >
typename List<Data>::const_iterator List<Data>::const_iterator::operator--( int ){
	if(current != nullptr){
		current = current->previous;
		return *this;
	}
	else 
		throw runtime_error("Null point exception!");
}

//Verify if iterators are equal
template < typename Data >
bool List<Data>::const_iterator::operator==( const const_iterator & rhs )const{
	if(current != nullptr && rhs.current != nullptr)
		return current->info == rhs.current->info;
	else
		throw runtime_error("Null point exception!");
}	

//Verify if iterators are equal
template < typename Data >
bool List<Data>::const_iterator::operator!=( const const_iterator & rhs )const{
	if(current != nullptr && rhs.current != nullptr)
		return current->info != rhs.current->info;
	else
		throw runtime_error("Null point exception!");
}

/**
*	iterator class
**/

//Return the value of current node
template < typename Data >
const Data & List<Data>::iterator::operator*() const{
	if(this->current != nullptr)
		return this->current->info;
	else 
		throw runtime_error("Null point exception!");
}

//Return the value of current node
template < typename Data >
Data & List<Data>::iterator::operator*(){
	if(this->current != nullptr)
		return this->current->info;
	else 
		throw runtime_error("Null point exception!");
}

//Return the next node
template < typename Data >
typename List<Data>::iterator & List<Data>::iterator::operator++(){
	if(this->current != nullptr){
		this->current = this->current->next;
		return *this;
	}else{ 
		throw runtime_error("Null point exception!");
	}
}

//Return the next node
template < typename Data >
typename List<Data>::iterator List<Data>::iterator::operator++( int ){
	if(this->current != nullptr){
		this->current = this->current->next;
		return *this;
	}else{ 
		throw runtime_error("Null point exception!");
	}
}

//Return the previous node
template < typename Data >
typename List<Data>::iterator & List<Data>::iterator::operator--(){
	if(this->current != nullptr){
		this->current = this->current->previous;
		return *this;
	}else{ 
		throw runtime_error("Null point exception!");
	}
}

//Return the previous node
template < typename Data >
typename List<Data>::iterator List<Data>::iterator::operator--( int ){
	if(this->current != nullptr){
		this->current = this->current->previous;
		return *this;
	}else{ 
		throw runtime_error("Null point exception!");
	}
}

/**
*	List class
**/

//Init
template < typename Data >
void List<Data>::init(){

	listSize = 0;
	
	head = new Node;
	tail = new Node;
	
	head->next = tail;
	tail->previous = head;

}
//Constructor
template < typename Data >
List<Data>::List(){
	init();
}

//Constructor 2
template < typename Data>
List<Data>::List( const List & rhs ){
	init();
	if(!rhs.empty()){
		Node * node = new Node(rhs.begin->info);
		
		head->next = node;
		tail->previous = node;
		node->previous = head;
		node->next = tail;

		for( auto i = rhs.begin()->next; i != rhs.end(); ++i ){
			//	New node with info of current iterator
			Node * newNode = new Node(*i);
			
			//	The previous tail receives newNode
			tail->previous->next = newNode;

			//	The previous newNode receives the previous tail
			newNode->previous = tail->previous;

			//	The previous tail receives newNode
			tail->previous = newNode;

			//	The next newNode receives tail
			newNode->next = tail;
		}
	}	
}

template < typename Data >
List<Data>::~List(){
	clear();
	delete head;
	delete tail;
}

//Operator = 
template < typename Data >
const List<Data> & List<Data>::operator=(const List<Data> & rhs){
	return rhs;
}

//Begin method (iterator)
template < typename Data >
typename List<Data>::iterator List<Data>::begin(){
	if(head != nullptr)
		return head->next;
	else return nullptr;
}

//Begin method (const_iterator)
template < typename Data >
typename List<Data>::const_iterator List<Data>::begin() const{
	if(head != nullptr)
		return head->next;
	else return nullptr;
}

//End method (iterator)
template < typename Data >
typename List<Data>::iterator List<Data>::end(){
	if(tail != nullptr)
		return tail;
	else return nullptr;
}

//End method (const_iterator)
template < typename Data >
typename List<Data>::const_iterator List<Data>::end() const{
	if(tail != nullptr)
		return tail;
	else return nullptr;
}

//Size
template < typename Data >
int List<Data>::size() const{
	return listSize;
}

//Empty
template < typename Data>
bool List<Data>::empty() const{
	return head == tail;
}

//Clear
template < typename Data >
void List<Data>::clear(){
	while(head->next != tail){
		head->next = head->next->next;
		delete head->next->previous;
		head->next->previous = head;
	}
	listSize = 0;
}

//Print list
template < typename Data >
void List<Data>::printList(){
	cout<<"[ ";
	for(auto i = begin(); i != end(); ++i){
		cout<<*i<<" ";
	}
	cout<<"]"<<endl;
}

//Insert 
template < typename Data >
typename List<Data>::iterator List<Data>::insert( iterator itr, const Data & _x ){
	Node * newNode = new Node(_x);
	newNode->previous = itr.current->previous;
	newNode->next = itr.current;

	newNode->previous->next = newNode;
	newNode->next->previous = newNode;
	
	++listSize;
	
	return itr;
}

//Erase one element
template < typename Data >
typename List<Data>::iterator List<Data>::erase( iterator itr){
	if(itr.current == tail){
		throw runtime_error("Null point exception!");
	}else{
		itr.current->previous->next = itr.current->next;
		itr.current->next->previous = itr.current->previous;
		delete itr.current;
	}

	return itr;
}

//Erase in a range
template < typename Data >
typename List<Data>::iterator List<Data>::erase( iterator start, iterator end){
	for(auto i = start; i != end; ++i){
		erase(i);
	}
	if(end.current != tail){
		erase(tail);
	}

	return end;
}

//Find an element (iterator)
template < typename Data >
typename List<Data>::iterator List<Data>::find( const Data & _x  ){
	auto i = begin();
	for(; i != end(); ++i){
		if(*i == _x) 
			break;
	}

	return i;
}

//Find an element (const_iterator)
template < typename Data >
typename List<Data>::const_iterator List<Data>::find( const Data & _x ) const{
	auto i = begin();
	for(; i != end(); ++i){
		if(*i == _x) 
			break;
	}

	return i;
}