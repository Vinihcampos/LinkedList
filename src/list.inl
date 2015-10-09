#include "list.h"

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
	return current->info;
}

//Return the next node
template < typename Data >
typename List<Data>::const_iterator & List<Data>::const_iterator::operator++(){
	return current->next;
}

//Return the next node
template < typename Data >
typename List<Data>::const_iterator List<Data>::const_iterator::operator++( int ){
	return current->next;
}

//Return the previous node
template < typename Data >
typename List<Data>::const_iterator & List<Data>::const_iterator::operator--(){
	return current->before;
}

//Return the previous node
template < typename Data >
typename List<Data>::const_iterator List<Data>::const_iterator::operator--( int ){
	return current->before;
}

//Verify if iterators are equal
template < typename Data >
bool List<Data>::const_iterator::operator==( const const_iterator & rhs )const{
	return current->info == rhs->info;
}

//Verify if iterators are equal
template < typename Data >
bool List<Data>::const_iterator::operator!=( const const_iterator & rhs )const{
	return current->info != rhs->info;
}

/**
*	iterator class
**/

//Return the value of current node
template < typename Data >
const Data & List<Data>::iterator::operator*() const{
	return this->current->info;
}

//Return the value of current node
template < typename Data >
Data & List<Data>::iterator::operator*(){
	return this->current->info;
}

//Return the next node
template < typename Data >
typename List<Data>::iterator & List<Data>::iterator::operator++(){
	return this->current->next;
}

//Return the next node
template < typename Data >
typename List<Data>::iterator List<Data>::iterator::operator++( int ){
	return this->current->next;
}

//Return the previous node
template < typename Data >
typename List<Data>::iterator & List<Data>::iterator::operator--(){
	return this->current->before;
}

//Return the previous node
template < typename Data >
typename List<Data>::iterator List<Data>::iterator::operator--( int ){
	return this->current->before;
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
	tail->before = head;

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
	*this = rhs;
}