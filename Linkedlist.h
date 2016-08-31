// Author:              Dr. Spiegel
// Updater:             Youssef Almkari
// Course:              CSC136
// Assignment:          Project 4
// Filename:            LinkedList.h
// Purpose:             *LinkedList Class:
//                       - connected nodes representing a polynomial
//                       - ability to evaluate, multiply, add, and remove nodes
//                         of any type (uses type Term for Polynomial)
//                      *node Class:
//                       - a node with data eltType (uses type Term for Polynomial)
//                       - uses a next type node to point to ther nodes
//                      *listItr Class:
//                       - represents a LinkedList by reference 
//                       - uses start, more, and next function to maneuver
//                         through LinkedList and value function for node data   

#ifndef _LinkedList_
#define _LinkedList_
#include <assert.h>
#include <iostream>

using namespace std;

// Need to prototype template classes if they are to be friends
template <typename eltType> class LinkedList;
template <typename eltType> class listItr;

template <typename eltType> class node
{private:
  node(eltType info, node* link = NULL ) :  data(info), next(link) {};
  eltType data;
  node*   next;
  friend class LinkedList<eltType>;
  friend class listItr<eltType>;
};

template <typename eltType> class LinkedList
{
 public:
 
/*
Function: 	constructor
Member Type:	N/A
Description: 	constructs an empty LinkedList
Parameters: 	none
Returns:      	N/A
*/

  LinkedList();

/*
Function: 	copy constructor
Member Type:	N/A
Description: 	construct deep copy of another LinkedList
Parameters: 	LinkedList - to copy
Returns:      	N/A
*/

  LinkedList(LinkedList&);

/*
Function: 	destructor 
Member Type:	N/A
Description: 	destroy LinkedList
Parameters: 	none
Returns:      	N/A
*/

  ~LinkedList();

/*
Function: 	operator=
Member Type:	Mutator
Description: 	assigns left LinkedList to this LinkedList, deep copy
Parameters: 	LinkedList - to be copied
Returns:      	N/A
*/

  LinkedList& operator=(const LinkedList&);

/*
Function: 	empty
Member Type:	Inspector
Description: 	checks if LinkedList is empty
Parameters: 	none
Returns:      	true if LinkedList empty, false otherwise
*/

  bool empty();

/*
Function: 	find
Member Type:	Facilitator
Description: 	checks if Term is present in LinkedList
Parameters: 	eltType - to look for in LinkedList
Returns:      	true if target is found, false otherwise
*/  
  
  bool find(eltType);

/*
Function: 	orderedInsert
Member Type:	Mutator
Description: 	inserts user specified input in LinkedList in descending order
Parameters: 	eltType - to be added
Returns:      	true if target added, false otherwise
*/

  bool orderedInsert(eltType);

/*
Function: 	remove
Member Type:	Mutator
Description: 	removes user specified target from LinkedList
Parameters: 	eltType - to be removed
Returns:      	true if target added, false otherwise
*/  
  
  bool remove(eltType);

  // Quick example of recursion
  int  countNodesInList();

 private:
  // linked list pointer
  node<eltType>* head;

/*
Function: 	copy
Member Type:	Mutator
Description: 	get a deep copy of a node
Parameters: 	node - to copy
Returns:      	N/A
*/

  node<eltType>* copy(node<eltType> *);

/*
Function: 	destroy
Member Type:	Mutator
Description: 	destroys LinkedList one node at a time
Parameters: 	node - to be destroyed 
Returns:      	void
*/

  void destroy(node<eltType> *);

  // Need this to count nodes in LinkedList
  int countNodes(node<eltType> *);

  // Needed to use a list iterator
  friend class listItr<eltType>;
};

//template <typename eltType> ostream& operator<<(ostream &os,const LinkedList<eltType> &l);

// Set up an iterator;
//      an object that provides a pointer to a linked list (in this case)
template <typename eltType> class listItr
{
 public:
  // Construct a List Iterator
  listItr(const LinkedList<eltType> &l);

  // Set curr to point at the first node of itr
  void start();
  // Is curr null?
  bool more();
  // Go to curr->next
  void next();
  // last node?
  bool isLastNode();
  // Get the value out of curr's node
  eltType &value() const;
  // Get the value out of curr's node, NON-CONST
  eltType &value();

 private:
  const LinkedList<eltType> &itr;
  node<eltType> *curr;
};

#endif
