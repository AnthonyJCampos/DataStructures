/** @file DoublyLinkedList.h
* @author Anthony Campos
* @date 06/15/2022
* @brief this header file implements a template DoublyLinkedList for pratice and exploration of concepts
*
*/

	//---------------------------------------------------------------------------
	// DoublyLinkedList:  Linked List
	//   included features:
	//   -- allows Capacity functions: size and empty
	//	  -- allows Element access: front and back
	//   -- allows Modifiers: pushFront, popFront, pushBack, popBack, resize, and clear
	//   -- allows Operations: remove, merge, sort, and reverse
	//   -- allows for assignment and copy of 2 DoublyLinkedList
	//---------------------------------------------------------------------------

#pragma once

// included libraries
#include <iostream>

template<class Data> 
class DoublyLinkedList
{


	/**
	* @brief diplays the DoublyLinkedList object to ostream stream
	* @pre none
	* @post Ostream object in the following format:
	*	1 2 3 4 5
	* @return Ostream object that represents an DoublyLinkedList
	*/
	friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& list)
	{
		Node<Data>* curPtr = list.head_;

		while (curPtr != nullptr)
		{

			out << curPtr->data_;

			if (curPtr->next_ != nullptr)
			{
				out << " ";

			} // end if 

			curPtr = curPtr->next_;

		} // end while

		return out;

	} // end overloaded <<

public:

	/** Constructor(s) */

	/**
	* @brief Defualt Constructor
	* @pre None
	* @post DoublyLinkedList Object created
	*/
	DoublyLinkedList();

	/**
	* @brief Copy Constructor
	* @pre none
	* @post source DoublyLinkedList deep copied and New DoublyLinkedList allocated.
	* Calls the copy to copy
	* @parm const DoublyLinkedList<Data>& [source]
	*/
	DoublyLinkedList(const DoublyLinkedList<Data>& source);


	/**
	* @brief Overloaded assigment operator
	* @pre None
	* @post left hand DoublyLinkedList equals the right hand DoublyLinkedList object
	*	Checks for self assignment and calls copy() to copy.
	* @param DoublyLinkedList [rhs] object to equal
	* @return DoublyLinkedList oject is now equal to right hand DoublyLinkedList object
	*/
	DoublyLinkedList<Data>& operator=(const DoublyLinkedList<Data>& rhs);


	/** Destructor  */

	/**
	* @brief Destructor
	* @pre none
	* @post destroy DoublyLinkedList and release memory
	*/
	~DoublyLinkedList();

	/** Public Methods */

	/** Element access */


	/**
	* @brief front, returns a reference to the first element in the list container.
	* @pre none
	* @post no changes to Linked List
	* @return a reference to the first element in the list container, nullptr otherwise if empty
	*/
	const Data& front() const;

	/**
	* @brief back, returns a reference to the last element in the list container.
	* @pre none
	* @post no changes to Linked List
	* @return a reference to the last element in the list container, nullptr otherwise if empty
	*/
	const Data& back() const;

	/** Modifiers */

	/**
	* @brief pushFront, inserts Template type Data into front of Linked List
	* @pre none
	* @post adds Node with Data data
	* @param Data [data]
	* @return true if data added to Linked List, otherwise false
	*/
	bool pushFront(Data data);


	/**
	* @brief pushBack, inserts Template type Data into back of Linked List
	* @pre none
	* @post adds Node with Data data
	* @param Data [data]
	* @return true if data added to Linked List, otherwise false
	*/
	bool pushBack(Data data);

	/**
	* @brief popFront, removes Template type Data from front of Linked List
	* @pre none
	* @post removes Node with Data data
	* @return true if data removed to Linked List, otherwise false
	*/
	bool popFront();

	/**
	* @brief popBack, removes Template type Data from back of Linked List
	* @pre none
	* @post removes Node with Data data
	* @return true if data removed to Linked List, otherwise false
	*/
	bool popBack();

	/**
	* @brief resize, resizes the Linked List so that it contains n elements.
	* @pre none
	* @post Linked List changes to size provided, no changes if current size_ matches size
	* @param int [size]
	*/
	void resize(int size);

	/**
	* @brief resize, resizes the Linked List so that it contains n elements. new
	*  elements are initialized as copies of val, otherwise, they are value-initialized.
	* @pre none
	* @post Linked List changes to size provided, no changes if current size_ matches size
	*  elements are initialized as copies of val, otherwise, they are value-initialized.
	* @param int [size], const Data& value
	*/
	void resize(int size, const Data& value);

	/**
	* @brief clear, clear all elements from Linked List
	* @pre none
	* @post memory deallocated for all List Nodes
	*/
	void clear();

	/** Operations */

	/**
	* @brief merge, Merges source into the list by transferring all of its elements at their
	*  respective ordered positions into the container (both list shall already be ordered).
	* @pre both list are already in sorted order, ascending 
	* @post merged sort list created, source list is empty
	* @parm DoublyLinkedList& [source]
	*/
	void merge(DoublyLinkedList& source);

	/**
	* @brief remove Template type Data from Linked List
	* @pre none
	* @post if data found in Linked List then removed
	* @param Data [key]
	* @return true if key removed, otherwise false
	*/
	bool remove(Data key);

	/**
	* @brief sort, sorts list in descending order
	* @pre none
	* @post Linked List sorted into descending order
	*/
	void sort();

	/**
	* @brief reverse, reverse order elements in Linked List
	* @pre none
	* @post Linked List order reverse
	*/
	void reverse();

	/** Capacity */

	/**
	* @brief empty, check if Linked List is empty or not
	* @pre none
	* @post no changes to Linked List
	* @return true if zero elements in list, otherwise false
	*/
	bool empty() const;

	/**
	* @brief size, return size/element count in Linked List
	* @pre none
	* @post no changes to Linked List
	* @return integer 0 if empty, or number of elements in list
	*/
	int size() const;

private:


	/** Attributes */

	template<class Data>
	struct Node
	{
		/**
		* @brief Defualt Constructor
		* @pre None
		* @post Node Object created
		*/
		template<class Data>
		inline Node(Data data)
			:data_(data), prev_(nullptr), next_(nullptr) {} // end of defualt constructor 

		/** Attributes */

		Data data_; // holds node data
		Node<Data>* prev_; // points to previous node
		Node<Data>* next_; // points to next node

	}; // end of Node

	Node<Data>* head_; // head of list
	Node<Data>* tail_; // tails of list
	int size_; // element count

	/** Private Methods */

	/**
	* @brief copy, copy contents from starting at provided Node
	* @pre none
	* @post data/list copied from provided node into current Linked List
	* @param const Node<Data>* [node]
	*/
	void copy(const Node<Data>* node);

	/**
	* @brief removeNode, remove node from Linked List
	* @pre node does not equal nullptr
	* @post current node element removed from list, memory deallocated
	* @param const Node<Data>* [node]
	*/
	void removeNode(Node<Data>* node);

	/**
	* @brief MergeSort, Merge Sorts Linked List
	* @pre none
	* @post sorts list in descending order
	* @param const Node<Data>* [node]
	*/
	void mergeSort(Node<Data>*& head);

	/**
	* @brief split, splits the nodes of the given list into front and
	*	back halves, and return the two lists using the reference parameters.
	*	If the length is odd, the extra node should go in the front list.
	*	Uses the fast/slow pointer strategy.
	* @pre none
	* @post Split the nodes into front and back half
	* @param Node<Data>* [source], Node<Data>*& [front], Node<Data>*& [back]
	*/
	void split(Node<Data>* source, Node<Data>*& front, Node<Data>*& back);

	/**
	* @brief mergeHelper, Takes two lists sorted in increasing order
	*	and splices their nodes together. to make one big sorted list which
	*	is returned
	* @pre none
	* @post provided list merged together
	* @param Node<Data>* [listA], Node<Data>* [listB]
	* @return DoublyLinkedList merged from the contents of listA & listB
	*/
	Node<Data>* mergeHelper(Node<Data>* listA, Node<Data>* listB);

	/**
	* @brief mergeFront, merges source node in front of this node setting new head_
	* @pre neither arguments can be nullptr
	* @post sourceNode merged in front of list previous head_ node
	* @param Node<Data>*& [thisNode], Node<Data>*& [sourceNode]
	*/
	void mergeFront(Node<Data>*& thisNode, Node<Data>*& sourceNode);

	/**
	* @brief mergeMiddle, merges source node in behind current this Node
	* @pre neither arguments can be nullptr
	* @post sourceNode merged in behind of this node and previous node
	* @param Node<Data>*& [thisNode], Node<Data>*& [sourceNode]
	*/
	void mergeMiddle(Node<Data>*& thisNode, Node<Data>*& sourceNode);

	/**
	* @brief mergeEnd, merges source node in at the end of list
	* @pre neither arguments can be nullptr
	* @post sourceNode merged in at the end of the list
	* @param Node<Data>*& [thisNode], Node<Data>*& [sourceNode]
	*/
	void mergeEnd(Node<Data>*& thisNode, Node<Data>*& sourceNode);


}; // end of DoublyLinkedList

/**
* @brief Defualt Constructor
* @pre None
* @post DoublyLinkedList Object created
*/
template<class Data>
inline DoublyLinkedList<Data>::DoublyLinkedList()
	:head_(nullptr), tail_(nullptr), size_(0) {} // end of defualt constructor 

/**
* @brief Copy Constructor
* @pre none
* @post source DoublyLinkedList deep copied and New DoublyLinkedList allocated.
* Calls the copy to copy
* @parm const DoublyLinkedList<Data>& [source]
*/
template<class Data>
inline DoublyLinkedList<Data>::DoublyLinkedList(const DoublyLinkedList<Data>& source)
{

	// clear current list
	clear();
	// copy list
	copy(source.head_);

} // end of copy constructor

/**
* @brief Overloaded assigment operator
* @pre None
* @post left hand DoublyLinkedList equals the right hand DoublyLinkedList object
*	Checks for self assignment and calls copy() to copy.
* @param DoublyLinkedList [rhs] object to equal
* @return DoublyLinkedList oject is now equal to right hand DoublyLinkedList object
*/
template<class Data>
inline DoublyLinkedList<Data>& DoublyLinkedList<Data>::operator=(const DoublyLinkedList<Data>& rhs)
{
	
	if (this == &rhs)
	{

		return *this;

	} // end if 

	// clear current mem
	clear();

	// copy rhs Linked List

	copy(rhs.head_);

	return *this;

} // end of overloaded operator=

/**
* @brief copy, copy contents from starting at provided Node
* @pre none
* @post data/list copied from provided node into current Linked List
* @param const Node<Data>* [node]
*/
template<class Data>
inline void DoublyLinkedList<Data>::copy(const Node<Data>* node)
{

	while (node != nullptr)
	{

		// insert node data
		pushFront(node->data_);
		// traverse forward
		node = node->next_;

	} // end while

} // end of copy

/**
* @brief Destructor
* @pre none
* @post destroy DoublyLinkedList and release memory
*/
template<class Data>
inline DoublyLinkedList<Data>::~DoublyLinkedList()
{

	// call clear
	clear();

} // end of destructor 

/**
* @brief clear, clear all elements from Linked List
* @pre none
* @post memory deallocated for all List Nodes
*/
template<class Data>
inline void DoublyLinkedList<Data>::clear()
{

	while (popFront());
	size_ = 0;

} // end of clear

/**
* @brief front, returns a reference to the first element in the list container.
* @pre none
* @post no changes to Linked List
* @return a reference to the first element in the list container, nullptr otherwise if empty
*/
template<class Data>
inline const Data& DoublyLinkedList<Data>::front() const
{
	if (head_ == nullptr)
	{
		return nullptr;

	} // end if 

	return head_->data_;

} // end front

/**
* @brief back, returns a reference to the last element in the list container.
* @pre none
* @post no changes to Linked List
* @return a reference to the last element in the list container, nullptr otherwise if empty
*/
template<class Data>
inline const Data& DoublyLinkedList<Data>::back() const
{
	// // O: insert return statement here

	if (tail_ == nullptr)
	{

		return nullptr;

	} // end if 

	return tail_->data_;

} // end of back

/**
* @brief pushFront, inserts Template type Data into front of Linked List
* @pre none
* @post adds Node with Data data
* @param Data [data]
* @return true if data added to Linked List, otherwise false
*/
template<class Data>
inline bool DoublyLinkedList<Data>::pushFront(Data data)
{
	
	Node<Data>* node;

	// first case, empty list
	if (head_ == nullptr)
	{

		// allocate memory, prev_ nullptr
		node = new Node<Data>(data);
		head_ = node;
		tail_ = node;

		//increment size, element added
		++size_;

		return true;

	} // end if 

	if (head_ != nullptr)
	{
		// insert in front approach 
		Node<Data>* temp = head_;
		node = new Node<Data>(data);
		head_ = node;
		node->next_ = temp;
		temp->prev_ = node;
		temp = nullptr;

		//increment size, element added
		++size_;

		return true;

	} // end if 

	return false;

} // end of insert

/**
* @brief pushBack, inserts Template type Data into back of Linked List
* @pre none
* @post adds Node with Data data
* @param Data [data]
* @return true if data added to Linked List, otherwise false
*/
template<class Data>
inline bool DoublyLinkedList<Data>::pushBack(Data data)
{
	
	Node<Data>* node;
	
	// list empty
	if (head_ == nullptr)
	{

		node = new Node<Data>(data);
		head_ = node;
		tail_ = node;
		++size_;
		return true;

	}
	else
	{

		Node<Data>* curNode = head_;
		while (curNode != nullptr)
		{

			// last node
			if (curNode->next_ == nullptr) 
			{
				node = new Node<Data>(data);
				curNode->next_ = node;
				node->prev_ = curNode;
				tail_ = node;
				++size_;
				return true;

			} // end if 

			curNode = curNode->next_;

		} // end while

	} // end if 
	
	return false;

} // end pushBack

/**
* @brief popFront, removes Template type Data from front of Linked List
* @pre none
* @post removes Node with Data data
* @return true if data removed to Linked List, otherwise false
*/
template<class Data>
inline bool DoublyLinkedList<Data>::popFront()
{
	
	// check if list empty
	if (head_ == nullptr)
	{
		return false;

	} // end if 


	if (head_->next_ != nullptr) {

		Node<Data>* temp = head_->next_;
		temp->prev_ = nullptr;
		delete head_;
		head_ = temp;


	}
	else // only 1 node
	{
		delete head_;
		head_ = nullptr;
		tail_ = nullptr;

	} // end if 

	--size_;

	return true;

} // end of popFront

/**
* @brief popBack, removes Template type Data from back of Linked List
* @pre none
* @post removes Node with Data data
* @return true if data removed to Linked List, otherwise false
*/
template<class Data>
inline bool DoublyLinkedList<Data>::popBack()
{
	
	// list is empty
	if (head_ == nullptr)
	{
		
		return false;

	} // end if 

	if (head_->next_ != nullptr)
	{

		Node<Data>* curNode = head_;

		while (curNode != nullptr)
		{

			if (curNode != nullptr)
			{

				// last node, pop
				if (curNode->next_ == nullptr)
				{
					// set previous node to point to nullptr
					curNode->prev_->next_ = nullptr;
					// set tail to previous node
					tail_ = curNode->prev_;
					// release memory
					delete curNode; 
					curNode = nullptr;

				}
				else 
				{
					
					curNode = curNode->next_;

				} // end if 

			} // end if 

		} // end while 
		
	}
	else // only 1 element in list
	{

		delete head_;
		head_ = nullptr;
		tail_ = nullptr;

	} // end if 

	--size_;

	return true;

} // end of popBack

/**
* @brief resize, resizes the Linked List so that it contains n elements.
* @pre none
* @post Linked List changes to size provided, no changes if current size_ matches size
* @param int [size]
*/
template<class Data>
inline void DoublyLinkedList<Data>::resize(int size)
{

	// if negative value passed, exit
	if (size < 0)
	{
		return;

	} // end if 

	int difference;
	if (size == 0)
	{
		clear();
	} // end if 
	else if (size < size_)
	{


		difference = size_ - size;
		for (int i = 0; i < difference; ++i)
		{
			popBack();

		} // end for

	}
	else // size is greater then 
	{

		difference = size - size_;
		for (int i = 0; i < difference; ++i)
		{
			Data data{};
			pushBack(data);

		} // end for 

	} // end if 

} // end of resize 

/**
* @brief resize, resizes the Linked List so that it contains n elements. new
*  elements are initialized as copies of val, otherwise, they are value-initialized.
* @pre none
* @post Linked List changes to size provided, no changes if current size_ matches size
*  elements are initialized as copies of val, otherwise, they are value-initialized.
* @param int [size], const Data& [value]
*/
template<class Data>
inline void DoublyLinkedList<Data>::resize(int size, const Data& value)
{

	// if negative value passed, exit
	if (size < 0)
	{
		return;

	} // end if 

	int difference;
	if (size == 0)
	{
		clear();
	} // end if 
	else if (size < size_)
	{


		difference = size_ - size;
		for (int i = 0; i < difference; ++i)
		{
			popBack();

		} // end for

	}
	else // size is greater then 
	{

		difference = size - size_;
		for (int i = 0; i < difference; ++i)
		{
			Data data = value;
			pushBack(data);

		} // end for 

	} // end if 

} // end of resize

/**
* @brief merge, Merges source into the list by transferring all of its elements at their
*  respective ordered positions into the container (both list shall already be ordered).
* @pre both list are already in sorted order, ascending
* @post merged sort list created, source list is empty
* @parm DoublyLinkedList& [source]
*/
template<class Data>
inline void DoublyLinkedList<Data>::merge(DoublyLinkedList& source)
{

	// check for self 
	if (this == &source)
	{
		
		return;

	} // end if 


	if (!empty())
	{
		
		if (!source.empty())
		{

			Node<Data>* thisNode = head_;
			Node<Data>* sourceNode = source.head_;

			int count = 0;
			while (source.size_ > 0)
			{

				//std::cout << "[Current This Node: " << thisNode->data_ << " ]\n";
				//std::cout << "[Current Source Node: " << sourceNode->data_ << " ]\n";
				//std::cout << "[Rep: " << count << " ]" << *this << std::endl;
				count++;

				// if the next node is not empty
				if (sourceNode->data_ <= thisNode->data_)
				{

					// insert in front
					if (thisNode->prev_ == nullptr && thisNode->next_ != nullptr)
					{

						mergeFront(thisNode, sourceNode);

					}
					else // insert middle
					{

						mergeMiddle(thisNode, sourceNode);


					} // end if 


					--source.size_;
					++size_;

				} // insert at end
				else if(thisNode->next_ == nullptr)
				{

					
					mergeEnd(thisNode, sourceNode);
					--source.size_;
					++size_;

				}
				else
				{

					thisNode = thisNode->next_;


				} // end if 

			} // end while


		} // end if 

	}
	else 
	{
		// target list is empty
		// source list empty does not impact first condition 
		head_ = source.head_;
		tail_ = source.tail_;

	} // end if 

	source.head_ = nullptr;
	source.tail_ = nullptr;

} // end if 

/**
* @brief mergeFront, merges source node in front of this node setting new head_
* @pre neither arguments can be nullptr
* @post sourceNode merged in front of list previous head_ node
* @param Node<Data>*& [thisNode], Node<Data>*& [sourceNode]
*/
template<class Data>
inline void DoublyLinkedList<Data>::mergeFront(Node<Data>*& thisNode, Node<Data>*& sourceNode)
{

	// connect source node to previous front node
	thisNode->prev_ = sourceNode;
	// set head to new head node
	head_ = sourceNode;

	// taverse one node forward
	sourceNode = sourceNode->next_;

	// set new head to point to the previous head node
	thisNode->prev_->next_ = thisNode;

	head_->prev_ = nullptr;

} // end of mergeFront

/**
* @brief mergeMiddle, merges source node in behind current this Node
* @pre neither arguments can be nullptr
* @post sourceNode merged in behind of this node and previous node
* @param Node<Data>*& [thisNode], Node<Data>*& [sourceNode]
*/
template<class Data>
inline void DoublyLinkedList<Data>::mergeMiddle(Node<Data>*& thisNode, Node<Data>*& sourceNode)
{

	// set previous node to point to source node
	thisNode->prev_->next_ = sourceNode;

	// set source node to point back at this node's previous node
	sourceNode->prev_ = thisNode->prev_;
	// set this node to point back at source node
	thisNode->prev_ = sourceNode;

	// taverse one node forward
	sourceNode = sourceNode->next_;

	// the new previous node now points to this Node
	thisNode->prev_->next_ = thisNode;

} // end of mergeMiddle

/**
* @brief mergeEnd, merges source node in at the end of list
* @pre neither arguments can be nullptr
* @post sourceNode merged in at the end of the list
* @param Node<Data>*& [thisNode], Node<Data>*& [sourceNode]
*/
template<class Data>
inline void DoublyLinkedList<Data>::mergeEnd(Node<Data>*& thisNode, Node<Data>*& sourceNode)
{

	// set this last node to point to new last node
	thisNode->next_ = sourceNode;
	// set source node to point back to previous last this node
	sourceNode->prev_ = thisNode;
	// set new tail_
	tail_ = sourceNode;
	sourceNode = sourceNode->next_;

} // end of mergeEnd


/**
* @brief remove Template type Data from Linked List
* @pre none
* @post if data found in Linked List then removed
* @param Data [key]
* @return true if key removed, otherwise false
*/
template<class Data>
inline bool DoublyLinkedList<Data>::remove(Data key)
{
	
	// list empty
	if (head_ == nullptr) 
	{
		return false;

	} // end if

	if (head_->data_ == key)
	{
		popFront();
		--size_;
		return true;

	} // end if 

	Node<Data>* curNode = head_;

	while (curNode != nullptr)
	{

		if (curNode->data_ == key)
		{

			removeNode(curNode);
			--size_;
			return true;

		} // end if

		curNode = curNode->next_;

	} // end while
	
	// key was not found, return false
	return false;

} // end remove

/**
* @brief removeNode, remove node from Linked List
* @pre node does not equal nullptr
* @post current node element removed from list, memory deallocated
* @param const Node<Data>* [node]
*/
template<class Data>
inline void DoublyLinkedList<Data>::removeNode(Node<Data>* node)
{

	// in between nodes
	if (node->next_ != nullptr)
	{

		// set previous node next to point to node after targer node
		node->prev_->next_ = node->next_;
		// set target nodes next node to point to targest nodes previous node
		node->next_->prev_ = node->prev_;
		delete node;
		node = nullptr;

	}
	else // end node
	{

		popBack();

	} // end if 	

} // end removeNode

/**
* @brief reverse, reverse order elements in Linked List
* @pre none
* @post Linked List order reverse
*/
template<class Data>
inline void DoublyLinkedList<Data>::reverse()
{

	if (head_ != nullptr)
	{

		//  must be more then one node
		if (head_->next_ != nullptr)
		{

			// switch head with tail
			head_ = tail_;
			tail_ = nullptr;

			// set previous node to next node
			head_->next_ = head_->prev_;
			// new head should point to nullptr for prev
			head_->prev_ = nullptr;

			Node<Data>* curNode = head_->next_;
			while (curNode != nullptr)
			{
				
				// store new previous node
				Node<Data>* temp = curNode->next_;
				curNode->next_ = curNode->prev_;
				curNode->prev_ = temp;
				temp = nullptr;

				if (curNode->next_ == nullptr) 
				{

					tail_ = curNode;

				} // end if 

				curNode = curNode->next_;

			} // end while

		} // end if 

	} // end if 

} // end reverse

/**
* @brief empty, check if Linked List is empty or not
* @pre none
* @post no changes to Linked List
* @return true if zero elements in list, otherwise false
*/
template<class Data>
inline bool DoublyLinkedList<Data>::empty() const
{
	
	return head_ == nullptr;

} // end of empty

/**
* @brief size, return size/element count in Linked List
* @pre none
* @post no changes to Linked List
* @return integer 0 if empty, or number of elements in list
*/
template<class Data>
inline int DoublyLinkedList<Data>::size() const
{
	
	return size_;

} // end of size


/**
* @brief sort, sorts list in descending order
* @pre none
* @post Linked List sorted into descending order
*/
template<class Data>
inline void DoublyLinkedList<Data>::sort()
{

	mergeSort(head_);


} // end of sort


/**
* @brief MergeSort, Merge Sorts Linked List
* @pre none
* @post sorts list in ascending order
* @param const Node<Data>* [node]
*/
template<class Data>
inline void DoublyLinkedList<Data>::mergeSort(Node<Data>*& head)
{
	
	Node<Data>* curHead = head;

	// empty list or single element 
	if (curHead == nullptr )
	{	
		return;

	} // end if


	if (curHead->next_ == nullptr)
	{

		// saves highest value as tail 
		if (tail_->data_ < curHead->data_)
		{

			tail_ = curHead;

		} // end if 

		return;

	} // end if

	// Split head into 'listA' and 'listB' sublists
	Node<Data>* listA;
	Node<Data>* listB;

	split(curHead, listA, listB);

	// Recursively sort the sublists
	mergeSort(listA);
	mergeSort(listB);

	// merge the two sorted lists together
	head = mergeHelper(listA, listB);

} // end of MergeSort


/**
* @brief split, splits the nodes of the given list into front and
*	back halves, and return the two lists using the reference parameters.
*	If the length is odd, the extra node should go in the front list.
*	Uses the fast/slow pointer strategy.
* @pre none
* @post Split the nodes into front and back half
* @param Node<Data>* [source], Node<Data>*& [front], Node<Data>*& [back]
*/
template<class Data>
inline void DoublyLinkedList<Data>::split(Node<Data>* source, Node<Data>*& front, Node<Data>*& back)
{

	Node<Data>* fast = source->next_;
	Node<Data>* slow = source;

	// Advance 'fast' two nodes, and advance 'slow' one node
	while (fast != nullptr)
	{
		fast = fast->next_;

		if (fast != nullptr)
		{

			slow = slow->next_;
			fast = fast->next_;

		} // end if 

	} // end while


	// 'slow' is before the midpoint in the list, so split it in two at that point.
	front = source;
	back = slow->next_;
	
	if (back != nullptr)
	{
		back->prev_ = nullptr;

	} // end if 
	
	slow->next_ = nullptr;

} // end if split

/**
* @brief mergeHelper, Takes two lists sorted in increasing order
*	and splices their nodes together. to make one big sorted list which
*	is returned
* @pre none
* @post provided list merged together
* @param Node<Data>* [listA], Node<Data>* [listB]
* @return DoublyLinkedList merged from the contents of listA & listB
*/
template<class Data>
inline DoublyLinkedList<Data>::Node<Data>* DoublyLinkedList<Data>::mergeHelper(Node<Data>* listA, Node<Data>* listB)
{

	Node<Data>* result = nullptr;

	// If linked list A is empty
	if (listA == nullptr)
	{
		return listB;

	} // end if 

	// If second linked list B is empty
	if (listB == nullptr)
	{
		return listA;

	} // end if 


	// Pick the smaller value
	if (listA->data_ < listB->data_)
	{
		
		
		result = listA;
		result->next_ = mergeHelper(listA->next_, listB);
		result->next_->prev_ = listA;
		result->prev_ = nullptr;

	}
	else
	{

		result = listB;
		result->next_ = mergeHelper(listA, listB->next_);
		result->next_->prev_ = listB;
		result->prev_ = nullptr;

	} // end if 

	return result;

} // end of mergeHelper





