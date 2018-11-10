//============================================================================
// Name        : CppKnowledgePractice.cpp
// Author      : Harrison
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "class_sizeof.hpp"
#include "non_virtual.h"
#include "virtual.h"

int main() {
	cout << "!!! Test Cpp practise !!!" << endl;

	cout << "A: " << sizeof(A) << ", B: " << sizeof(B) << ", C: " << sizeof(C) << endl;

	cout << "\n!!! Test Non virtual !!!" << endl;
	CA *pA = (CA*)new CB();
	delete pA;

	cout << "\n!!! Test virtual !!!" << endl;
	VA *pV = (VA*)new VB();
	delete pV;

	cout << "\n!!! const validation !!!" << endl;
	const int cv = 10;
	int av = 20;

	const int *pa = &cv;
	//*pa = 11;   // could not assign to other value;
	pa = &av;  	  // could be reassign
	//*pa = 12;   // could not assign to other value;

	int const *pb = NULL;
	pb = &cv;
	//*pb = 21;   // could not assign to other value;
	pb = &av;     // could be reassign
	//*pb = 22;   // could not assign to other value;

	int * const pc = &av;
	*pc = 31;
	//pc = &cv;   // error, const int* could not be assigned.

	cout << "cv: " << cv << ", av: " << av << endl;
	return 0;
}
