#pragma once

#include<vector>

class LinearHashTable{

public:

	LinearHashTable();

	virtual void insert(const int key);

	bool remove(const int key);

	bool search(const int key) const;

	int retrieve(const int key) const;

protected:

	// default vector size for hash table
	static const int DEFAULT_SIZE = 11;

	int keyCount_; // current amount of keys in table_

	std::vector<std::pair<int*, bool>> table_;

	int hash(const int key) const;

	virtual int probe(int hashCode);

	void reHash();

	bool isPrime(int number);

private:

	/** Private Methods */
	
	void resize();

	const std::pair<int*, bool>* getPair(const int key) const;

}; // end of LinearHashTable

