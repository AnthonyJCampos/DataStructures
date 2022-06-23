#include "QuadraticHashTable.h"


QuadraticHashTable::QuadraticHashTable()
	:LinearHashTable(){
} // end default


int QuadraticHashTable::probe(int hashCode) {

	
	int quad = 1;
	while (table_[hashCode].second != false) {

		quad = static_cast<int>(pow(quad, 2));
		hashCode = LinearHashTable::hash(hashCode + quad);
		++quad;

	} // end while

	return hashCode;

} // end probe 



