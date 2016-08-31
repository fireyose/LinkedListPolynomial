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

#include <assert.h>
#include <iostream>
#include "LinkedList.h"

/*
Function: 	constructor
Member Type:	N/A
Description: 	constructs an empty LinkedList
Parameters: 	none
Returns:      	N/A
*/

template <typename eltType> LinkedList<eltType>::LinkedList() : head(NULL)
{}

/*
Function: 	copy constructor
Member Type:	N/A
Description: 	construct deep copy of another LinkedList
Parameters: 	LinkedList - to copy
Returns:      	N/A
*/

template <typename eltType> LinkedList<eltType>::LinkedList(LinkedList<eltType> &cl)
{ head = copy( cl.head ); }

/*
Function: 	destructor 
Member Type:	N/A
Description: 	destroy LinkedList
Parameters: 	none
Returns:      	N/A
*/

template <typename eltType> LinkedList<eltType>::~LinkedList()
{ destroy(head); }

/*
Function: 	operator=
Member Type:	Mutator
Description: 	assigns left LinkedList to this LinkedList, deep copy
Parameters: 	LinkedList - to be copied
Returns:      	N/A
*/

template <typename eltType> LinkedList<eltType>
	&LinkedList<eltType>::operator =(const LinkedList<eltType>& cl)
{ if (this != &cl)
  { destroy(head);
    head = copy(cl.head);
  }
  return *this;
}

/*
Function: 	orderedInsert
Member Type:	Mutator
Description: 	inserts user specified input in LinkedList in descending order
Parameters: 	eltType - to be added
Returns:      	true if target added, false otherwise
*/

template <typename eltType> bool LinkedList<eltType>::orderedInsert(eltType x)
{  if (empty() || x > head->data) {
     assert(head=new node<eltType>(x,head));
     return true;
   }
   else if (find(x)) {
     node<eltType> *p = head;
     while (p != NULL && p->data > x)
       p = p->next;
     (p->data += x);
     return false;
   }
   else   // start at 2nd node...already checked first node
   { node<eltType>*  p       = head -> next; // head;
     node<eltType>*  trailp  = head;         // NULL;
     while (p != NULL && p->data > x)
     { trailp = p;
       p = p->next;
     }
     assert((trailp->next = new node<eltType>(x,p)) != NULL);
     return true;
  }
}

/*
Function: 	find
Member Type:	Facilitator
Description: 	checks if Term is present in LinkedList
Parameters: 	eltType - to look for in LinkedList
Returns:      	true if target is found, false otherwise
*/

template <typename eltType> bool LinkedList<eltType>::find(eltType x)
{  node<eltType> *p = head;
   while (p != NULL && p->data > x)
     p = p->next;
   if (p == NULL)
     return false;
   else
     return true;
}

/*
Function: 	empty
Member Type:	Inspector
Description: 	checks if LinkedList is empty
Parameters: 	none
Returns:      	true if LinkedList empty, false otherwise
*/

template <typename eltType> inline bool LinkedList<eltType>::empty()
{ return (head == NULL); }

/*
Function: 	remove
Member Type:	Mutator
Description: 	removes user specified target from LinkedList
Parameters: 	eltType - to be removed
Returns:      	true if target added, false otherwise
*/

template <typename eltType> bool LinkedList<eltType>::remove(eltType x)
{  assert( !empty() );
   if (find(x)) {
     node<eltType>*  p = head;
     node<eltType>*  trailp = NULL;
     while ( p != NULL && p->data > x )
     { trailp = p;
       p = p->next;
     } 
     assert(p != NULL);              // x is not in the LinkedList
     if (p == head)
       head = head->next;            // x is first in the LinkedList
     else
       trailp->next = p->next;       // x is farther down in the LinkedList
     delete p;
     return true;
   }
   else 
    return false;
}

/*
Function: 	destroy
Member Type:	Mutator
Description: 	destroys LinkedList one node at a time
Parameters: 	node - to be destroyed 
Returns:      	void
*/

template <typename eltType> void LinkedList<eltType>::destroy(node<eltType> *l)
{ while (l != NULL)
  { node<eltType> *doomed = l;
    l = l->next;
    delete doomed;
  }
}

/*
Function: 	copy
Member Type:	Mutator
Description: 	get a deep copy of a node
Parameters: 	node - to copy
Returns:      	N/A
*/

template <typename eltType>
node<eltType>* LinkedList<eltType>::copy(node<eltType> *l)
{ node<eltType>* first = NULL;    // ptr to beginning of copied LinkedList
  node<eltType>* last = NULL;     // ptr to last item insert in the copy
  if (l != NULL)
  { assert((first=last=new node<eltType>(l->data,NULL)) != NULL);
    for (node<eltType>* source=l->next; source!=NULL; source=source->next,last=last->next)
    { last->next = new node<eltType>(source->data,NULL);
      assert(last->next);
    }
  }
  return first;
}
/* Output a linked list, using a list iterator
template <typename eltType> ostream& operator<<(ostream &os,const LinkedList<eltType> &l)
{
  listItr<eltType> lt(l);

  while ( lt.more() ) {
    os << lt.value();
    lt.next();
  }
  return os;
}
*/

// Count nodes in a linked list, starting at l
template <typename eltType> int LinkedList<eltType>::countNodes(node<eltType> *p)
{return ((p) ?  1+countNodes(p->next) : 0);}

// Return number of nodes in *this' list
template <typename eltType> int LinkedList<eltType>::countNodesInList()
{return(countNodes(head));}

/* ****************************************************************
************** List Iterator Implementations *******************
****************************************************************/

// Construct a list iterator. It consists of:
//       a reference to a linked list object
//       a pointer to the actual list, initially pointing to its head
template <typename eltType>
listItr<eltType>::listItr(const LinkedList<eltType> &l): itr(l),curr(l.head)
{}

// Set curr to point at itr's head
template <typename eltType> void listItr<eltType>::start(void)
{curr = itr.head;}

// Is curr at the end of the list?
template <typename eltType> bool listItr<eltType>::more(void)
{ return curr != NULL; }

// Move curr to next node
template <typename eltType> void listItr<eltType>::next(void)
{ assert( curr != NULL );
  curr = curr->next;
}

// Last node?
template <typename eltType> bool listItr<eltType>::isLastNode(void)
{ return (curr->next == NULL); }

// Return data in curr's node. Regardless of assert(), this
// function shouldn't be called until making sure more() returns true
template <typename eltType> eltType &listItr<eltType>::value(void) const
{ assert( curr != NULL );
  return curr->data;
}

// Return data in curr's node. Regardless of assert(), this
// function shouldn't be called until making sure more() returns true, NON-CONST
template <typename eltType> eltType &listItr<eltType>::value(void)
{ assert( curr != NULL );
  return curr->data;
}
