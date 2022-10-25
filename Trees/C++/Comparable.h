/** @file Comparable.h
 @author Anthony Campos
 @date 01/11/2022
 This header class file implements a  data structure known as a
	Comparable that holds a char object */

//---------------------------------------------------------------------------
// Comparable class:  simple data structure that holds a char value
//   included features:
//   -- provides overloaded comparison operators
//   -- provides overloaded ostream and istream operators
//---------------------------------------------------------------------------

#pragma once

// Included libraries

#include <iostream>

/** Comparable class */

class Comparable{

	/** Friend Methods */

	/** overloaded operator<<
	@pre must be a Comparable object
	@post Comparable object's values outputted via ostream.
	@param std::istream [in], Comparable [object]
	@return istream */
	friend std::ostream& operator<<(std::ostream& out, const Comparable& object);

	/** overloaded operator>>
	@pre must be a Comparable object
	@post Comparable object's values retrieved from the istream and set
	@param std::istream [in], Comparable [object]
	@return istream */
	friend std::istream& operator>>(std::istream& in, Comparable& object);

public:

	/** Public Methods */

	/** overloaded operator==
	@pre must be a Comparable objects
	@post two Comparable objects equal or not dependent they data_ attribute
	@param Comparable [rhs]
	@return true if data_ member is equal to rhs data_ member, false otherwise */
	bool operator==(const Comparable& rhs) const;

	/** overloaded operator!=
	@pre must be a Comparable objects
	@post two Comparable objects equal or not dependent they data_ attribute
	@param Comparable [rhs]
	@return true if data_ member is are not equal to rhs data_ member,
	false otherwise */
	bool operator!=(const Comparable& rhs) const;

	/** overloaded operator<
	@pre must be a Comparable objects
	@post determine if lhs Comparable object is less then rhs Comparable object
	@param Comparable [rhs]
	@return true if lhs data_ member is less then rhs data_ member,
	false otherwise */
	bool operator<(const Comparable& rhs) const;

	/** overloaded operator<
	@pre must be a Comparable objects
	@post determine if lhs Comparable object is greater then rhs Comparable object
	@param Comparable [rhs]
	@return true if lhs data_ member is greater then rhs data_ member,
	false otherwise */
	bool operator>(const Comparable& rhs) const;

private:

	/** Private Attributes */

	// holds char
	char data_; 

}; // end of Comparable

