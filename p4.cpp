// Author:          Youssef Almkari
// Course:          CSC136
// Assignment:      Project 4
// Filename:        p4.cpp
// Purpose:         To construct a menu to deal with polynomials
//                  Evaluate, Multiply, Print, Remove and Add a polynomial

#include "poly.h"
#include "term.h"
#include <iostream> 
#include <fstream>
#include <cmath>
#include <cctype>
using namespace std;

/** PROTOTYPES **/

bool openFile (ifstream &, string &, Polynomial &); // Opens input file stream
void printMenu ();                                  // Displays Menu
bool choiceIsX (char &);                            // Checks if user choice is 'X'
float evalPoly (Polynomial &);                      // Evaluates polynomial for user input 'X'
void multPoly (Polynomial &);                       // Multiplies polynomial by user input coefficient 
void addPoly (Polynomial &);                        // Adds term to the polynomial
void removeTerm (Polynomial &);                     // Removes specified term from Polynomial

int main()
{ Polynomial thePoly;    // Declare object 'thePoly' type Polynomial
  ifstream infile;       // Holds input file stream
  ofstream outfile;      // Holds output file stream
  string filename;       // Hold user input filename
  char choice;           // Holds user's menu choice

  // Check if file is successfully opened
  if (openFile (infile, filename, thePoly)) {
    printMenu (); 
    cin >> choice;
    // Menu displays after every choice
    // while user does not exit
    while (toupper(choice) != 'X') {
      switch (toupper(choice)) {
      case 'E':
	cout << evalPoly(thePoly);
	break;
      case 'M':
	multPoly(thePoly);
	break;
      case 'P':
	cout << thePoly;
	break;
      case 'A':
	addPoly(thePoly);
	break;
      case 'R':
	removeTerm(thePoly);
	break;
      default:
	// User does not enter a menu option
	cout << endl;
	cout << "Entry not an option, try again." << endl;
	break;
      }
      printMenu ();
      cin >> choice;
    }

    // User chooses to exit
    if (choiceIsX (choice))
      return 0;
  }
}

/*
  Functon:          openFile
  Description:      opens input stream
                    checks if successful
  Parameters:       ifstream inf    - input/output - holds input file stream
                    string filename - input/output - holds filename
		    Polynomial Poly - input        - holds object 
  Returns:          True if file successfuly opened and read, else false
*/

bool openFile (ifstream &inf, string &fileName, Polynomial &Poly) {
  cout << "Enter file name: ";	      // Ask user for file name
  cin >> fileName;                    // Inserts name in string "fileName"
  cout << endl << endl;
  inf.open(fileName.c_str());         // Opens file
  
  // Checks if the file exists 
  if (inf.fail()) {
    cout << "FILE NOT FOUND" << endl << endl;  // File was not successfully found
    return false;                              // Bool returns false, program exists 
  }
  else {
    cout << "FILE FOUND" << endl << endl;      // File successfully streaming under "infile"
    inf >> Poly;
    return true;                               // Bool returns true, program continues
  }
}

/*
  Function:         printMenu
  Description:      prints menu
  Parameters:       None
  Returns:          void
*/

void printMenu () { 
  cout << endl << endl;
  cout << " **The Polynomial Program** " << endl << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "(E)valuate" << endl;
  cout << "(M)ultiply" << endl;
  cout << "(P)rint" << endl;
  cout << "(A)dd" << endl;
  cout << "e(X)it" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;
  cout << "Choose one, any one:  ";
}

/*
  Function:       choiceIsX
  Description:    checks if user choice is 'X'
  Parameters:     char C - input - holds user's choice
  Returns:        True is choice is 'X', else false
*/

bool choiceIsX (char &C) {
  if (toupper (C) == 'X')
    return true;
  else
    return false;
}

/*
  Function:       evalPoly
  Description:    Evaluates the polynomial for user input 'X'
  Parameters:     Polynomial Poly - input - holds object
  Returns:        evaluated polynomial total type float
*/

float evalPoly (Polynomial &Poly) {
  double X;
  cout << "Enter a value for 'X':  ";
  cin >> X;
  cout << endl;
  return Poly(X);
}

/*
  Function:       multPoly
  Description:    multiplies polynomial by the user's input
  Parameter:      Polynomial Poly - input - holds object
  Returns:        void
*/

void multPoly (Polynomial &Poly) {
  float factor;
  cout << "What number would you like to multiply the polynomial by?:  ";
  cin >> factor;
  Poly *= factor;
}

/*
  Function:       addPoly
  Description:    adds user input coefficient and exponent
                  to Polynomial
  Parameters:     Polynomial Poly - input - holds object
  Returns:        void
*/

void addPoly (Polynomial &Poly) {
  Term newTerm;
  double coeff;
  int expn;
  cout << endl << endl;
  cout << "Enter Coefficient:  ";
  cin >> coeff;
  newTerm.setCoefficient (coeff);
  cout << endl << endl;
  cout << "Enter Exponent:  ";
  cin >> expn;
  newTerm.setExponent (expn);
  // Term was not added
  if (Poly.add(newTerm) == false)
    cout << "\n** Term was successfully updated **\n";
  else 
    cout << "\n** Term successfully added **\n";
}

/*
  Function:       removeTerm
  Description:    removes user input Term from Polynomial
  Parameters:     Polynomial Poly - input - holds object
  Returns:        void
*/

void removeTerm (Polynomial &Poly) {
  Term newTerm;
  double coeff = 1;
  int expn;
  cout << endl << endl;
  newTerm.setCoefficient (coeff);
  cout << endl << endl;
  cout << "Which Term must you remove? (Enter Exponent):  ";
  cin >> expn;
  newTerm.setExponent (expn);
  if (Poly.removeTerm( newTerm ))
    cout << "\n\n** Term was successfully removed **";
  else
    cout << "\n\n** Term was NOT found **";
}
