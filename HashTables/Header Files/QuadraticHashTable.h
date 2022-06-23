#pragma once

#include<cmath>
#include "LinearHashTable.h"


class QuadraticHashTable : public LinearHashTable {

public:

	QuadraticHashTable();

private:

	/** Private Methods */
	virtual int probe(int hashCode) override;


}; // end of QuadraticHashTable

