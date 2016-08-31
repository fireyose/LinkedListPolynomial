# Author:              Dr. Spiegel
# Course:              CSC136
# Assignment:          Project 4
# Filename:            makefile
# Purpose:             to build an executable 'p4' using the following classes:
#                      - Polynomial, LinkedList, listItr, node, and Term
#                      connects to p4.cpp application

CC=/opt/csw/gcc3/bin/g++
DebugFlag=-g

p4: poly.o p4.o LinkedList.o term.o
	$(CC) $(DebugFlag) -o p4 p4.o poly.o LinkedList.o term.o

LinkedList.o: LinkedList.cpp LinkedList.h types.tpp
	cp LinkedList.cpp temp.cpp
	cat types.tpp >> temp.cpp
#	Compile temporary file created with instantiations at the end; save as LinkedList.o
	$(CC) -c temp.cpp -g -o LinkedList.o
#	Uncomment the next line before submission
	\rm -f temp.cpp 

p4.o:   p4.cpp poly.h term.h
	$(CC) $(DebugFlag) -c p4.cpp

poly.o: poly.cpp poly.h LinkedList.h term.h
	$(CC) $(DebugFlag) -c poly.cpp

term.o: term.h term.cpp
	$(CC) $(DebugFlag) -c term.cpp

clean:
	\rm -rf *.o p4
