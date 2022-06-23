#include "ChainingHashTable.h"



ChainingHashTable::ChainingHashTable()
	:size_(10) {

	for (int i = 0; i < 10; ++i) {

		LinkedList<int>* list = new LinkedList<int>;
		table_.push_back(list);

	} // end for

} // end if 

ChainingHashTable::~ChainingHashTable() {

	for (int i = 0; i < size_; ++i) {

		delete table_[i];

	} // end for 

} // end of Destructor

void ChainingHashTable::clear() {

	for (int i = 0; i < size_; ++i) {

		table_[i]->clear();

	} // end for 

} // end of clear

int ChainingHashTable::hash(int key) const{

	return key % 10;

} // end of hash;

void ChainingHashTable::insert(int key) {

	int hashCode = hash(key);
	table_[hashCode]->sortedInsert(key);

} // end insert

int ChainingHashTable::search(int key) const{

	int hashCode = hash(key);

	const Node<int>* result = table_[hashCode]->search(key);

	if (result != nullptr) {

		return result->getData();

	} // end if

	// key was not in table 
	return -1;

} // end search 


