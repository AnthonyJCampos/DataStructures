/** @file Comparable.cpp
 @author Anthony Campos
 @date 01/11/2022
 This is implementation file implements a  data structure known as a
	Comparable that holds a char */

//---------------------------------------------------------------------------
// Comparable class:  simple data structure that holds a char value
//   included features:
//   -- provides overloaded comparison operators
//   -- provides overloaded ostream and istream operators
//---------------------------------------------------------------------------

// included .h files
#include "Comparable.h"

/** Friend Methods */

/** overloaded operator<<
@pre must be a Comparable object
@post Comparable object's values outputted via ostream.
@param std::istream [in], Comparable [object]
@return istream */
std::ostream& operator<<(std::ostream& out, const Comparable& object) {

	out << object.data_;

	return out; // return ostream

} // end of overloaded ostream
	
 /** overloaded operator>>
@pre must be a Comparable object
@post Comparable object's values retrieved from the istream and set
@param std::istream [in], Comparable [object]
@return istream */
std::istream& operator>>(std::istream& in, Comparable& object) {

	in >> object.data_;

	return in; // return istream

} // end of overloaded istream

/** Public Methods */

/** overloaded operator==
@pre must be a Comparable objects
@post two Comparable objects equal or not dependent they data_ attribute
@param Comparable [rhs]
@return true if data_ member is equal to rhs data_ member, false otherwise */
bool Comparable::operator==(const Comparable& rhs) const{

	return data_ == rhs.data_; // return true if equal, otherwise false

} // end of overloaded ==

/** overloaded operator!=
@pre must be a Comparable objects
@post two Comparable objects equal or not dependent they data_ attribute
@param Comparable [rhs]
@return true if data_ member is are not equal to rhs data_ member,
false otherwise */
bool Comparable::operator!=(const Comparable& rhs) const{

	return data_ != rhs.data_; // return true if not equal, otherwise false

} // end of overloaded !=

/** overloaded operator<
@pre must be a Comparable objects
@post determine if lhs Comparable object is less then rhs Comparable object
@param Comparable [rhs]
@return true if lhs data_ member is less then rhs data_ member,
false otherwise */
bool Comparable::operator<(const Comparable& rhs) const{

	return data_ < rhs.data_; // return true if less then, otherwise false

} // end of overloaded <

/** overloaded operator<
@pre must be a Comparable objects
@post determine if lhs Comparable object is greater then rhs Comparable object
@param Comparable [rhs]
@return true if lhs data_ member is greater then rhs data_ member,
false otherwise */
bool Comparable::operator>(const Comparable& rhs) const{

	return data_ > rhs.data_; // return true if greater then, otherwise false

} // end of overloaded >

/** End of Comparable class */
