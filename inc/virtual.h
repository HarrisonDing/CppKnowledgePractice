#include <iostream>
using namespace std;

class VA {
public:
	VA() {
		cout << "VA is created!" << endl;
	}
	virtual ~VA() {
		cout << "VA is deleted!" << endl;
	}
};

class VB : public VA{
public:
	VB() {
		cout << "VB is created!" << endl;
	}
	virtual ~VB() {
		cout << "VB is deleted!" << endl;
	}
};
