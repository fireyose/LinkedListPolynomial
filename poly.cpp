// Author:              Youssef Almkari
// Course:              CSC136
// Assignment:          Project 4
// Filename:            poly.cpp
// Purpose:             Implementation of Class poly
//                      Produce an interface that handles polynomials
//
//**UPDATE**:		The Polynomial Class now handles LinkedLists which handle specific Terms.
//			Access to Terms now can only be done through termList of type LinkedList.

#include "poly.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

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

  Polynomial::Polynomial()
  {}
  
/*
Function: 	getTermList
Member Type:	Inspector
Description:  	returns object termList to be used with  outside class scope functions
Parameters: 	none
Returns:      	LinkedList termList
*/

  const LinkedList<Term>& Polynomial::getTermList() const
  { return (termList); }
  
/*
Function: 	operator ()
Member Type:	Facilitator
Description: 	Evaluate the polynomial for variable x
Parameters: 	x 	- input - variable that is standing for value of x
Returns:      	double	- fully evaluated polynomial value
*/

  double Polynomial::operator()(double x)
  { listItr<Term> itr(termList);
    double total = 0;
    for (itr.start(); itr.more(); itr.next())
      total = total + itr.value()(x);
    return total;
  }
  
/*
Function: 	multiply
Member Type:	Mutator
Description: 	Multiply each coefficient by the scalar arg factor
Parameters: 	factor  - input - variable that is multiplying against all the coefficents
Returns:      	void
*/

  void Polynomial::operator*=(float factor)
  { listItr<Term> itr(termList);
    for (itr.start(); itr.more(); itr.next())
      itr.value() *= factor;
  }
  
/*
Function:       removeTerm
Member Type:    Mutator
Description:    removes requested term
Parameters:     Term - Term to be removed
Returns:        true if term removed, false otherwise 
*/

  bool Polynomial::removeTerm(Term &T) 
  { return (termList.remove(T)); }

/*
Function: 	add
Member Type:	Mutator
Description: 	Add a term to the polynomial
Parameters: 	T  - input - the Term being added
Returns:      	true if the term is added, false otherwise
*/

  bool Polynomial::add(Term &T)
  { return (termList.orderedInsert(T)); }
  
/*
Function: 	operator >>
Description: 	Reads in a Term from a file
Parameters: 	ifstream    - input/output - the input stream
		Polynomial  - input        - holds add function
Returns:      	file 
*/

  ifstream &operator>>(ifstream &file, Polynomial &P)
  { Term aTerm;
    while (file >> aTerm)
      P.add(aTerm);
    file.close();
    return(file);
  }

/*
Function: 	operator <<
Description: 	Print a Polynomial to the screen
Parameters: 	ostream      - input/output - output stream
		Polynomial   - output       - The Polynomial to access termList array
Returns:        out
*/

  ostream &operator<<(ostream &out,const Polynomial &P)
  { listItr<Term> itr(P.getTermList());
    for (itr.start(); itr.more(); itr.next()) {
      if (itr.isLastNode())
        out << itr.value();
      else
	out << itr.value() << " + ";
    }
    return out;
  }

  
