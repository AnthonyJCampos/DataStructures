#pragma once


template<typename T>
class Node{

public:

	/** Constructor */
	Node(T data);

	/** Mutator */
	void setData(T data);

	void setNext(Node<T>* next);

	/** Accesors */

	T getData() const;

	Node<T>* getNext() const;

private:

	/** Attributes */
	T data_;
	Node<T>* next_;

}; // end of Node

template<typename T>
Node<T>::Node(T data)
	:data_(data), next_(nullptr) {
} // end of constructor

template<typename T>
void Node<T>::setData(T data) {

	data_(data);

} // end of setData

template<typename T>
void Node<T>::setNext(Node<T>* next){

	if (next != nullptr) {

		next_ = next;
	}
	else {
		next_ = nullptr;
	} // end if 
	

} // end of setNext

template<typename T>
T Node<T>::getData() const{

	return data_;

} // end of getData

template<typename T>
Node<T>* Node<T>::getNext() const{

	return next_;

} // end getNext


