#pragma once

#include "LinkedList.h"

#include<vector>


class ChainingHashTable{

public:

	/** Constructor */
	ChainingHashTable();

	~ChainingHashTable();

	/** Mutator */

	int hash(int key) const;

	void insert(int key);

	void clear();

	/** Accesor */

	int search(int key) const;

private:

	/** Attributes */

	int size_;
	std::vector<LinkedList<int>*> table_;

};

