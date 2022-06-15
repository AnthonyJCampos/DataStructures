/** @file SinglyLinkedList.h
* @author Anthony Campos
* @date 06/08/2022
* @brief this header file implements a template SinglyLinkedList
* 	
*/

	//---------------------------------------------------------------------------
	// SinglyLinkedList:  Linked List
	//   included features:
	//   -- allows basic functions remove, insert , find, clear, size, isEmpty, print
	//	  -- allows for sorting (merge sort), reverse, retrieve
	//   -- allows for assignment and copy of 2 SinglyLinkedList
	//---------------------------------------------------------------------------

#pragma once


#include <iostream>

template <class Data>
class SinglyLinkedList
{

	/**
	* @brief diplays the SinglyLinkedList object to ostream stream
	* @pre none
	* @post Ostream object in the following format:
	*	1 2 3 4 5
	* @return Ostream object that represents an SinglyLinkedList 
	*/
	friend std::ostream& operator<<(std::ostream& out, const SinglyLinkedList& list) 
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
	* @post SinglyLinkedList Object created
	*/
	SinglyLinkedList();

	/**
	* @brief Copy Constructor
	* @pre none
	* @post source SinglyLinkedList deep copied and New SinglyLinkedList allocated.
	* Calls the copy to copy
	* @parm const SinglyLinkedList<Data>& [source]
	*/
	SinglyLinkedList(const SinglyLinkedList<Data>& source);

	/** Destructor  */


	/**
	* @brief Destructor
	* @pre none
	* @post destroy SinglyLinkedList and release memory
	*/
	~SinglyLinkedList();

	/**
	* @brief Overloaded assigment operator
	* @pre None
	* @post left hand SinglyLinkedListobject equals the right hand SinglyLinkedList object
	*	Checks for self assignment and calls copy() to copy.
	* @param SinglyLinkedList [rhs] object to equal
	* @return SinglyLinkedList oject is now equal to right hand SinglyLinkedList object
	*/
	SinglyLinkedList<Data>& operator=(const SinglyLinkedList<Data>& rhs);

	/** Public Methods */


	/**
	* @brief insert, inserts Template type Data into Linked List
	* @pre none
	* @post adds Node with Data data
	* @param Data [data]
	* @return true if data added to Linked List, otherwise false
	*/
	bool insert(Data data);

	/**
	* @brief remove Template type Data from Linked List
	* @pre none
	* @post if data found in Linked List then removed
	* @param Data [data]
	* @return true if data removed, otherwise false
	*/
	bool remove(Data data);

	/**
	* @brief find, whether this Linked List contains a given Template type Data
	* @pre none
	* @post no changes to Linked List
	* @param Data [key]
	* @return true if list conatains key, otherwise false
	*/
	bool find(Data key) const;


	/**
	* @brief retrieve, whether this Linked List contains a given Template type Data and retrieves it
	* @pre none
	* @post no changes to Linked List, data set to value if found
	* @param Data [key], Data& [data]
	* @return true if list conatains key, otherwise false
	*/
	bool retrieve(Data key, Data& data) const;

	/**
	* @brief size, return size/element count in Linked List
	* @pre none
	* @post no changes to Linked List
	* @return integer 0 if empty, or number of elements in list
	*/
	int size() const;

	/**
	* @brief isEmpty, check if Linked List is empty or not
	* @pre none
	* @post no changes to Linked List
	* @return true if zero elements in list, otherwise false
	*/
	bool isEmpty() const;

	/**
	* @brief sort, sorts list in descending order
	* @pre none
	* @post Linked List sorted into descending order
	*/
	void sort();

	/**
	* @brief print, prints contents of Linked List
	* @pre none
	* @post no changes to list
	*/
	void print() const;

	/**
	* @brief reverse, reverse order elements in Linked List
	* @pre none
	* @post Linked List order reverse
	*/
	void reverse();

	/**
	* @brief clear, clear all elements from Linked List
	* @pre none
	* @post memory deallocated for all List Nodes
	*/
	void clear();


private:


	// attributes
	template <class Data>
	struct Node
	{
		
		/**
		* @brief Defualt Constructor
		* @pre None
		* @post Node Object created
		*/
		template <class Data>
		inline Node(Data data)
			:data_(data), next_(nullptr){} // end of Node constructor
		

		Data data_; // data member
		Node<Data>* next_; // pointer to next node

	}; // end of Node
			
	Node<Data>* head_; // head pointer
	int size_; // elements count


	/**
	* @brief copy, copy contents from starting at provided Node
	* @pre none
	* @post data/list copied from provided node into current Linked List
	* @param const Node<Data>* [node]
	*/
	void copy(const Node<Data>* node);

	/**
	* @brief removehead, remove head_ node from Linked List
	* @pre head_ node does not equal nullptr
	* @post current head_ node element removed from list, memory deallocated
	*/
	void removeHead();
	

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
	void MergeSort(Node<Data>*& node);

	/**
	* @brief frontBackSplit, Split the nodes of the given list into front and 
	*	back halves, and return the two lists using the reference parameters.
	*	If the length is odd, the extra node should go in the front list.
	*	Uses the fast/slow pointer strategy.
	* @pre none
	* @post Split the nodes into front and back half
	* @param Node<Data>* [source], Node<Data>*& [front], Node<Data>*& [back]
	*/
	void frontBackSplit(Node<Data>* source, Node<Data>*& front, Node<Data>*& back);

	/**
	* @brief sortedMerge, Takes two lists sorted in increasing order
	*	and splices their nodes together. to make one big sorted list which
	*	is returned
	* @pre none
	* @post provided list merged together
	* @param Node<Data>* [listA], Node<Data>* [listB]
	* @return SinglyLinkedList merged from the contents of listA & listB
	*/
	Node<Data>* sortedMerge(Node<Data>* listA, Node<Data>* listB);


}; // end of SinglyLinkedList


/**
* @brief Defualt Constructor
* @pre None
* @post SinglyLinkedList Object created
*/
template<class Data>
inline SinglyLinkedList<Data>::SinglyLinkedList()
	:head_(nullptr), size_(0)
{
} // default constructor

/**
* @brief Copy Constructor
* @pre none
* @post source SinglyLinkedList deep copied and New SinglyLinkedList allocated.
* Calls the copy to copy
* @parm const SinglyLinkedList<Data>& [source]
*/
template<class Data>
inline SinglyLinkedList<Data>::SinglyLinkedList(const SinglyLinkedList<Data>& source)
{

	copy(source.head_);

} // end copy constructor 

/**
* @brief Destructor
* @pre none
* @post destroy SinglyLinkedList and release memory
*/
template<class Data>
inline SinglyLinkedList<Data>::~SinglyLinkedList()
{

	clear();

} // end of destructor

/**
* @brief clear, clear all elements from Linked List
* @pre none
* @post memory deallocated for all List Nodes
*/
template<class Data>
inline void SinglyLinkedList<Data>::clear()
{

	while (head_ != nullptr)
	{
		removeHead();

	} // end while

	size_ = 0;

} // end of clear


/**
* @brief Overloaded assigment operator
* @pre None
* @post left hand SinglyLinkedListobject equals the right hand SinglyLinkedList object
*	Checks for self assignment and calls copy() to copy.
* @param SinglyLinkedList [rhs] object to equal
* @return SinglyLinkedList oject is now equal to right hand SinglyLinkedList object
*/
template<class Data>
inline SinglyLinkedList<Data>& SinglyLinkedList<Data>::operator=(const SinglyLinkedList<Data>& rhs)
{
	
	// check for self assignment 
	if (this == &rhs)
	{
		return *this;

	} // end if 

	// deallocate lhs Linked List
	clear();

	// do copy
	copy(rhs.head_);

	// return the existing object so we can chain this operator
	return *this;
	
	// // O: insert return statement here
}

/**
* @brief copy, copy contents from starting at provided Node
* @pre none
* @post data/list copied from provided node into current Linked List
* @param const Node<Data>* [node]
*/
template<class Data>
inline void SinglyLinkedList<Data>::copy(const Node<Data>* node)
{

	while (node != nullptr)
	{
		insert(node->data_);
		node = node->next_;

	} // end while;

} // end of copy.

/**
* @brief insert, inserts Template type Data into Linked List
* @pre none
* @post adds Node with Data data
* @param Data [data]
* @return true if data added to Linked List, otherwise false
*/
template<class Data>
inline bool SinglyLinkedList<Data>::insert(Data data)
{
	
	// create node
	Node<Data>* node = nullptr;
	
	// empty inserts
	if (head_ == nullptr)
	{

		node = new Node<Data>(data);
		head_ = node;

		++size_; // increment size
		return true;

	} // end if 

	if (head_ != nullptr)
	{

		// traverse till nullptr
		Node<Data>* curPtr = head_;
		while (curPtr != nullptr)
		{
			if (curPtr->next_ == nullptr)
			{
				node = new Node<Data>(data);
				curPtr->next_ = node;

				++size_; // increment size
				return true;

			} // end if 

			// move to next node
			curPtr = curPtr->next_;

		} // end while 

	}// end if 

	return false;

} // end of insert

/**
* @brief remove Template type Data from Linked List
* @pre none
* @post if data found in Linked List then removed
* @param Data [data]
* @return true if data removed, otherwise false
*/
template<class Data>
inline bool SinglyLinkedList<Data>::remove(Data data)
{

	if (head_ == nullptr)
	{

		return false;

	} // end if 


	if (head_ != nullptr)
	{

		if (head_->data_ == data)
		{

			removeHead();
			--size_;
			return true;

		} // end if 

		Node<Data>* curPtr = head_;

		while (curPtr->next_ != nullptr)
		{

			if (curPtr->next_->data_ == data)
			{

				removeNode(curPtr);
				--size_;
				return true;

			} // end if

			curPtr = curPtr->next_;

		} // end while

	} // end if 


	return false;

} // end remove


/**
* @brief removehead, remove head_ node from Linked List
* @pre head_ node does not equal nullptr
* @post current head_ node element removed from list, memory deallocated
*/
template<class Data>
inline void SinglyLinkedList<Data>::removeHead()
{

	if (head_->next_ != nullptr)
	{


		Node<Data>* temp = head_->next_;
		delete head_;
		head_ = temp;
		temp = nullptr;

	}
	else // only 1 item in list
	{

		delete head_;
		head_ = nullptr;

	} // end if 

} // end if 


/**
* @brief removeNode, remove node from Linked List
* @pre node does not equal nullptr
* @post current node element removed from list, memory deallocated
* @param const Node<Data>* [node]
*/
template<class Data>
inline void SinglyLinkedList<Data>::removeNode(Node<Data>* node)
{

	// in between nodes
	if (node->next_->next_ != nullptr)
	{

		// save node ahead of target node
		Node<Data>* temp = node->next_->next_;
		delete node->next_;
		node->next_ = temp;
		temp = nullptr;

	}
	else // end node
	{

		delete node->next_;
		node->next_ = nullptr;


	} // end if 	

} // end of removeNode


/**
* @brief find, whether this Linked List contains a given Template type Data
* @pre none
* @post no changes to Linked List
* @param Data [key]
* @return true if list conatains key, otherwise false
*/
template<class Data>
inline bool SinglyLinkedList<Data>::find(Data key) const
{
	
	Node<Data>* curPtr = head_;

	while (curPtr != nullptr)
	{

		if (curPtr->data_ = key)
		{

			return true;

		}

		curPtr = curPtr->next_;

	} // end while
	
	return false;


} // end find


/**
* @brief retrieve, whether this Linked List contains a given Template type Data and retrieves it
* @pre none
* @post no changes to Linked List, data set to value if found
* @param Data [key], Data& [data]
* @return true if list conatains key, otherwise false
*/
template<class Data>
inline bool SinglyLinkedList<Data>::retrieve(Data key, Data& data) const
{
	
	Node<Data>* curPtr = head_;

	while (curPtr != nullptr)
	{

		if (curPtr->data_ = key)
		{

			data = curPtr->data_;
			return true;

		}

		curPtr = curPtr->next_;

	} // end while

	return false;

} // end retrieve


/**
* @brief size, return size/element count in Linked List
* @pre none
* @post no changes to Linked List
* @return integer 0 if empty, or number of elements in list
*/
template<class Data>
inline int SinglyLinkedList<Data>::size() const
{
	return size_;

} // end of size

/**
* @brief isEmpty, check if Linked List is empty or not
* @pre none
* @post no changes to Linked List
* @return true if zero elements in list, otherwise false
*/
template<class Data>
inline bool SinglyLinkedList<Data>::isEmpty() const
{
	
	return head_ == nullptr;

} // isEmpty();

/**
* @brief sort, sorts list in descending order
* @pre none
* @post Linked List sorted into descending order
*/
template<class Data>
inline void SinglyLinkedList<Data>::sort()
{

	MergeSort(head_);

} // end of sort

/**
* @brief MergeSort, Merge Sorts Linked List
* @pre none
* @post sorts list in descending order
* @param const Node<Data>* [node]
*/
template<class Data>
inline void SinglyLinkedList<Data>::MergeSort(Node<Data>*& node)
{

	Node<Data>* curHead = node;

	if (curHead == nullptr || curHead->next_ == nullptr)
	{
		return;

	} // end if 


	// Split head into 'listA' and 'listB' sublists
	Node<Data>* listA;
	Node<Data>* listB;
	frontBackSplit(curHead, listA, listB);

	// Recursively sort the sublists
	MergeSort(listA);
	MergeSort(listB);

	// merge the two sorted lists together
	node = sortedMerge(listA, listB);


} // end of MergeSort

/**
* @brief frontBackSplit, Split the nodes of the given list into front and
*	back halves, and return the two lists using the reference parameters.
*	If the length is odd, the extra node should go in the front list.
*	Uses the fast/slow pointer strategy.
* @pre none
* @post Split the nodes into front and back half
* @param Node<Data>* [source], Node<Data>*& [front], Node<Data>*& [back]
*/
template<class Data>
inline void SinglyLinkedList<Data>::frontBackSplit(Node<Data>* source, Node<Data>*& front, Node<Data>*& back)
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
	slow->next_ = nullptr;


} // end if frontBackSplit

/**
* @brief sortedMerge, Takes two lists sorted in increasing order
*	and splices their nodes together. to make one big sorted list which
*	is returned
* @pre none
* @post provided list merged together
* @param Node<Data>* [listA], Node<Data>* [listB]
* @return SinglyLinkedList merged from the contents of listA & listB
*/
template<class Data>
inline SinglyLinkedList<Data>::Node<Data>* SinglyLinkedList<Data>::sortedMerge(Node<Data>* listA, Node<Data>* listB)
{

	Node<Data>* result = nullptr;

	if (listA == nullptr)
	{
		return listB;

	} // end if 

	if (listB == nullptr)
	{
		return listA;

	} // end if 

	if (listA->data_ <= listB->data_)
	{
		result = listA;
		result->next_ = sortedMerge(listA->next_, listB);

	}
	else
	{

		result = listB;
		result->next_ = sortedMerge(listA, listB->next_);

	}

	return result;

} // end of sortedMerge

/**
* @brief print, prints contents of Linked List
* @pre none
* @post no changes to list
*/
template<class Data>
inline void SinglyLinkedList<Data>::print() const
{

	Node<Data>* curPtr = head_;

	while (curPtr != nullptr)
	{

		std::cout << curPtr->data_;

		if (curPtr->next_ != nullptr)
		{
			std::cout << " ";

		} // end if 

		curPtr = curPtr->next_;

	} // end while

} // end of print

/**
* @brief reverse, reverse order elements in Linked List
* @pre none
* @post Linked List order reverse
*/
template<class Data>
inline void SinglyLinkedList<Data>::reverse()
{

	// empty list or 1 element
	if (head_ == nullptr || head_->next_ == nullptr)
	{
		
		return;

	} // end if 

	SinglyLinkedList reversedList;

	// front insert

	Node<Data>* curPtr = head_;
	reversedList.head_;

	while (curPtr != nullptr)
	{

		// first insert
		if (reversedList.head_ == nullptr)
		{

			reversedList.head_ = curPtr;
			head_ = curPtr->next_;
			reversedList.head_->next_ = nullptr; // remove connection to orginal list

		}
		else
		{
			
			// store current reversed head 
			Node<Data>* temp = reversedList.head_;
			reversedList.head_ = curPtr;
			head_ = curPtr->next_;
			reversedList.head_->next_ = temp; // remove connection to orginal list

		} // end if 

		curPtr = head_;

	} // end while

	head_ = reversedList.head_;
	reversedList.head_ = nullptr;

} // end reverse







