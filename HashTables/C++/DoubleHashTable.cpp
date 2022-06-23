#include "DoubleHashTable.h"


DoubleHashTable::DoubleHashTable()
	:LinearHashTable() {} // end of Constructor


void DoubleHashTable::insert(const int key) {

   int hashCode = doubleProbe(key);
   table_[hashCode].first = new int(key);
   table_[hashCode].second = true;
   ++keyCount_;

   double loadFactor = keyCount_ / static_cast<double>(table_.size());
   // increase size of vector to maintain loading factor <= .05
   if (loadFactor >= 0.5) {

      // reset & rehash table 
      LinearHashTable::reHash();

   } // end if 

} // end insert

int DoubleHashTable::doubleHash(const int key, const int collision) {

   // get prime number closest to table_.size
   int prime = static_cast<int>(table_.size() - 1);

   while (!LinearHashTable::isPrime(prime)) {

      // decrement prime till prime number is reached
      --prime;

   } // end while 

   int hash1 = LinearHashTable::hash(key);
   int hash2 = (prime - (key % prime));

   return (hash1 + collision * hash2) % table_.size();

} // end of doubleHash

int DoubleHashTable::doubleProbe(const int key) {

   int collision = 0;

   int hashCode = doubleHash(key, collision);

   while (table_[hashCode].second != false) {

      ++collision;
      hashCode = doubleHash(key, collision);

   } // end while

   return hashCode;

}





