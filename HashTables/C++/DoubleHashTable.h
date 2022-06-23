#pragma once

#include "LinearHashTable.h"

class DoubleHashTable : public LinearHashTable{

public:

	DoubleHashTable();

	virtual void insert(const int key) override;

private:

	int doubleHash(const int key, const int collision);

	int doubleProbe(const int key);

	
}; // end of DoubleHashTable


