#ifndef _LINKED_LIST_
#define _LINKED_LIST_

template <typename Data>
class List{
	
	private:

		// The main structure of List
		struct Node{
			Data info;
			Node * before;
			Node * next;

			Node(const Data & _info = Data(), Node * _before = nullptr, Node * _next = nullptr) :
				info { _info }, before { _before }, next {_next}{}
		};

		Node * head;
		Node * tail;
		int listSize;

	//	Iterator classes
	public:

		class const_iterator{

			protected:

				Node * current;

				const_iterator( Node * p );

				friend class List<Data>

			public:

				const_iterator(){}

				const Data & operator * () const;

				const_iterator & operator ++ ();

				const_iterator operator ++ ( int );

				const_iterator & operator -- ();

				const_iterator operator -- ( int );

				bool operator == ( const const_iterator & rhs )	const;
				bool operator != ( const const_iterator & rhs )	const;				
		};

		class iterator : public const_iterator{

			protected:
				
				iterator( Node * p ) : const_iterator (p){}

				friend class List<Data>;

			public:

				iterator(){}

				const Data & operator * () const;

				Data & operator * ();

				iterator & operator ++ ();

				iterator operator ++ ( int );

				iterator & operator -- ();

				iterator operator -- ( int );

		};

	//	Generic methods
	public:

		List();
		~List();
		List(const List & rhs);
		const List & operator = (const List & rhs);

	//	Specific methods
	public:

		//	Verifying the start and the end of list 
		iterator begin();	// Multable iterator;
		iterator end();		// Multable iterator;

		const_iterator begin() const;	//	Imultable iterator;
		const_iterator end() const;		//	Imultable iterator;

		int size () const;	//	The current size of list
		bool empty() const;	// 	State of list
		void clear();	// Clear the List

		Data & front ( return * begin(); ); // Return the value of first element (with iterator)
		const Data & front() const;	// Return the value of first element (with const_iterator)

		Data & back (); // Return the value of last element (with iterator)
		const Data & back () const; // Return the value of last element (with const_iterator)

		void push_front( const Data & _x ) { insert( begin() , _x ); } // Insert an element at first position of list
		void push_back( const Data & _x ); // Insert an element at last position of list

		void pop_front();	// Remove the fisrt element of list;
		void pop_back();	// Remove the last element of list;

		iterator insert ( iterator itr, const Data & _x); //	Insert an element at the position of an iterator itr

		iterator erase ( iterator itr ); // Remove the element of position itr
		iterator erase ( iterator start, iterator end);	// 	Remove elements of range start to end

		const_iterator find( const Data & _x ) const; // Return an const_iterator to element _x in List
		iterator find( const Data & _x ); // Return an iterator to element _x in List

};

#include "../src/list.inl"

#endif