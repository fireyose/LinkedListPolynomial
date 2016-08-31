// Author: 		Dr. Spiegel
// Updater:		Youssef Almkari
// Course:		CSC136
// Assignment:		Project 4
// Filename:		poly.h
// Purpose:		Definition of the Polynomial Class
//			This class provides the user the functionality of a polynomial, including
//			the ability to add terms, evaluate, and multiply the coefficients.
//			It also provides basic set and get functionality.
//			A function is provided to read terms from a file, and two associated 
//			non-member, non-friend stream operators are present for reading a Term 
//			and outputting the Polynomial in its entirety.
//
//**UPDATE**:		The Polynomial Class now handles LinkedLists which handle specific Terms.
//			Access to Terms now can only be done through termList of type LinkedList.

#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "term.h"

using namespace std;

class Polynomial
{
 public:
  
  //////
  // Constructor
  //////

/*
Function: 	constructor
Member Type:	N/A
Description: 	activates termList
Parameters: 	none
Returns:      	N/A
*/

  Polynomial();
  
/*
Function: 	getTermList
Member Type:	Inspector
Description:  	returns object termList to be used with  outside class scope functions
Parameters: 	none
Returns:      	LinkedList termList
*/

  const LinkedList<Term>& getTermList() const;
  
/*
Function: 	operator ()
Member Type:	Facilitator
Description: 	Evaluate the polynomial for variable x
Parameters: 	x 	- input - variable that is standing for value of x
Returns:      	double	- fully evaluated polynomial value
*/

  double operator()(double x);
  
/*
Function: 	multiply
Member Type:	Mutator
Description: 	Multiply each coefficient by the scalar arg factor
Parameters: 	factor  - input - variable that is multiplying against all the coefficents
Returns:      	void
*/

  void operator*=(float factor);

/*
Function:       removeTerm
Member Type:    Mutator
Description:    removes requested term
Parameters:     Term - Term to be removed
Returns:        true if term removed, false otherwise 
*/

  bool removeTerm(Term &T);

/*
Function: 	add
Member Type:	Facilitator
Description: 	Add a term to the polynomial
Parameters: 	T  - input - the Term being added
Returns:      	true if the term is added, false otherwise
*/

  bool add(Term &T);
 
 private:
  LinkedList<Term> termList;

};

/*
Function: 	operator >>
Description: 	Reads in a Term from a file
Parameters: 	ifstream    - input/output - the input stream
		Polynomial  - input        - holds add function
Returns:      	file 
*/

  ifstream &operator>> (ifstream &file, Polynomial &P);

/*
Function: 	operator <<
Description: 	Print a Polynomial to the screen
Parameters: 	ostream      - input/output - output stream
		Polynomial   - output       - The Polynomial to access termList array
Returns:        out
*/

  ostream &operator<< (ostream &out,const Polynomial &P);

#endif
