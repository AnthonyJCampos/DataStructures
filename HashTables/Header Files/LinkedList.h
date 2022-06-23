#pragma once

#include "Node.h"


template <typename T>
class LinkedList{

public:

	/** Constructors */
	LinkedList();

	/** Destructor */
	~LinkedList();

	/** Mutators */

	bool sortedInsert(const T data);

	bool remove(const T data);

	void clear();

	/** Accesors */

	bool isEmpty() const;

	const Node<T>* search(T data);


private:

	/** Attributes */
	Node<T>* head_;

}; // end of Linked List


/** Constructors */
template<typename T>
LinkedList<T>::LinkedList()
	:head_(nullptr) {} // end of Default Constructor

template<typename T>
LinkedList<T>::~LinkedList() {

	clear();

} // end of destructor

template<typename T>
bool LinkedList<T>::sortedInsert(const T data) {

	// allocate memory for new node
	Node<T>* newNode = new Node<T>(data);

	if (head_ != nullptr) {

		Node<T>* curr = head_;

		// case new node is less then first node
		if (curr->getData() > newNode->getData()) {

			newNode->setNext(curr);
			head_ = newNode;
			curr = nullptr;
			return true;

		} // end if


		// case: at leasts one node
		while (curr != nullptr) {

			// case insert between
			if (curr->getNext() != nullptr && curr->getNext()->getData() > newNode->getData()) {

				newNode->setNext(curr->getNext());
				curr->setNext(newNode);
				curr = nullptr;
				return true;

			} // end if

			// case insert at end
			if (curr->getNext() == nullptr) {

				curr->setNext(newNode);
				curr = nullptr;
				return true;

			} // end if 

			curr = curr->getNext();

		} // end while

	}
	else { // empty list, insert at front

		head_ = newNode;
		return true;

	} // end if 

	return false;

} // end of sortedInsert


template<typename T>
bool LinkedList<T>::remove(const T data) {

	if (!isEmpty()) {

		// first node is to be removed
		if (head_->getData() == data) {

			Node<T>* junk = head_;
			head_ = head_->getNext();

			// release memory
			delete junk;
			junk = nullptr;

			return true;

		} // end if 

		Node<T>* curr = head_;

		while (curr->getNext() != nullptr) {

			// remove node
			if (curr->getNext()->getData() == data) {

				Node<T>* junk = curr->getNext();
				curr->setNext(curr->getNext()->getNext());

				// release memory
				delete junk;
				junk = nullptr;

				return true;

			}
				curr = curr->getNext();

		} // end while

	} // end if 
	
	return false;

} // end of remove

template<typename T>
void LinkedList<T>::clear() {

	Node<T>* curr = head_;

	while (curr != nullptr) {

		remove(curr->getData());
		curr = head_;

	} // end while

} // end of clear


template<typename T>
bool LinkedList<T>::isEmpty() const {

	return head_ == nullptr;

} // end of isEmpty

template<typename T>
const Node<T>* LinkedList<T>::search(T data) {

	// list is empty
	if (isEmpty()) {

		return nullptr;

	} // end if 

	Node<T>* curr = head_;

	while (curr != nullptr){

		if (curr->getData() == data) {

			return curr;

		} // end if

		curr = curr->getNext();

	} // end while

	// item was not found
	return nullptr;

} // end of search