#include <iostream>
using namespace std;

class CA {
public:
	CA() {
		cout << "CA is created!" << endl;
	}
	~CA() {
		cout << "CA is deleted!" << endl;
	}
};

class CB : public CA{
public:
	CB() {
		cout << "CB is created!" << endl;
	}
	~CB() {
		cout << "CB is deleted!" << endl;
	}
};
