#include "LinearHashTable.h"


LinearHashTable::LinearHashTable() 
	:keyCount_(0){

	for (int i = 0; i < DEFAULT_SIZE; ++i) {

		std::pair<int*, bool> cell(nullptr, false);
		table_.push_back(cell);

	} // end for

} // end default

void LinearHashTable::insert(const int key) {

	int hashCode = probe(hash(key));
	table_[hashCode].first = new int(key);
	table_[hashCode].second = true;
	++keyCount_;

	double loadFactor = keyCount_ / static_cast<double>(table_.size());
	// increase size of vector to maintain loading factor <= .05
	if (loadFactor >= 0.5) {

		// reset & rehash table 
		reHash();

	} // end if 

} // end insert

bool LinearHashTable::remove(const int key) {

	int hashCode = hash(key);
	while (table_[hashCode].first != nullptr) {

		// we should probe
		if (*table_[hashCode].first != key) {

			hashCode = hash(hashCode + 1);

		}
		else {

			// set flag to true
			table_[hashCode].second = false;
			--keyCount_;
			return true;

		} // end if 

	} // end while

	return false;

} // end of remove 

bool LinearHashTable::search(const int key) const {

	if (getPair(key) != nullptr) {

		return true;

	} // end if 

	return false;

} // end search

int LinearHashTable::retrieve(const int key) const {


	const std::pair<int*, bool>* item = getPair(key);

	if (item != nullptr) {

		return *item->first;

	} // end if 

	// replace with a throw 
	return -1;

} // end of retrieve

int LinearHashTable::hash(const int key) const {

	return key % table_.size();

} // end of hash

int LinearHashTable::probe(int hashCode) {

	// linear probing
	while (table_[hashCode].second != false) {

		hashCode = hash(hashCode + 1);

	} // end while

	return hashCode;

} // end probe 

void LinearHashTable::resize() {

	// resize table & initialize
	// get next largest prime number that is 2 times current size

	int size = table_.size() * 2;

	while (!isPrime(size)) {

		++size;

	} // end while

	table_.resize(size, std::pair<int*, bool>(nullptr, false));
	
} // end resize 

void LinearHashTable::reHash() {

	std::vector<int> keys{}; // temp key storage

	for (unsigned int i = 0; i < table_.size(); ++i) {

		if (table_[i].first != nullptr) {

			// save current keys
			keys.push_back(*table_[i].first);

			// release allocated memory & reset
			delete table_[i].first;
			table_[i].first = nullptr;
			table_[i].second = false;

		} // end if 

	} // end for 


	resize();
	keyCount_ = 0;

	for (unsigned int i = 0; i < keys.size(); ++i) {

		insert(keys[i]);

	} // end for 

} // end reHash

bool LinearHashTable::isPrime(int number) {
	// since 0 and 1 is not prime return false.
	if (number == 1 || number == 0) return false;

	// Run a loop from 2 to n-1
	for (int i = 2; i < number; i++) {
		// if the number is divisible by i, then n is not a prime number.
		if (number % i == 0) return false;
	}
	// otherwise, n is prime number.
	return true;

} // end of isPrime

const std::pair<int*, bool>* LinearHashTable::getPair(const int key) const{

	int hashCode = hash(key);
	while (table_[hashCode].second != false) {

		// we should probe
		if (*table_[hashCode].first != key) {

			hashCode = hash(hashCode + 1);

		}
		else {

			return &table_[hashCode];

		} // end if 

	} // end while

	return nullptr;

} // end getPair




