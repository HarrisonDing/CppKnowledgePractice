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
#include "heap_sort.h"

#include "threadusage.hpp"
#include "template_all_function_in_class_inner.hpp"


void testHeapSort() {
	int inta[] = {7, 4,5,1, 8,2,0,9,6,3};
	cout << "\n@@@ Heap sort start..." << endl;
	heap_sort(inta, 10);
	for(int i = 0; i < 10; i ++) {
		cout << " | " << inta[i];
	}
	cout << " | " << endl;
	cout << "@@@ Heap sort done!" << endl;
}

void testConstPoint() {
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
}

void testStdThread() {
	ThreadSample *sample = new ThreadSample(10);
	sample->init();
	while(true) {
		this_thread::sleep_for(chrono::seconds(1));
		if(sample->getTickets() <= 0)
			break;
	}
}

void testTemplate1() {
	Complex c1(1, 2);
	Complex c2(3, 4);

	Complex c3 = c1 + c2;
	cout << c3 << endl;
}
int main() {
	cout << "!!! Test Cpp practise !!!" << endl;

	cout << "A: " << sizeof(A) << ", B: " << sizeof(B) << ", C: " << sizeof(C) << endl;

	cout << "\n!!! Test Non virtual !!!" << endl;
	CA *pA = (CA*)new CB();
	delete pA;

	cout << "\n!!! Test virtual !!!" << endl;
	VA *pV = (VA*)new VB();
	delete pV;

	testConstPoint();

	testHeapSort();

	cout << "\n\nBegin to test standard thread function ..." << endl;
	testStdThread();
	cout << "End to test standard thread function ...\n" << endl;

	cout << "\n\n Begin to test template functions all in class inner ..." << endl;
	testTemplate1();
	cout << "\n End to test template functions all in class inner ..." << endl;

	return 0;
}
