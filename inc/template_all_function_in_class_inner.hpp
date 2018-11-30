/*
 * template_all_function_in_class_inner.hpp
 *
 *  Created on: Nov 30, 2018
 *      Author: Harrison.Ding
 */

#ifndef TEMPLATE_ALL_FUNCTION_IN_CLASS_INNER_HPP_
#define TEMPLATE_ALL_FUNCTION_IN_CLASS_INNER_HPP_

#include <iostream>

using namespace std;

template <typename T>
class Complex {
	friend Complex mySub(Complex &c1, Complex &c2) {
		Complex tmp(c1.a - c2.a, c1.b - c2.b);
		return tmp;
	}

	friend ostream& operator<<(ostream &out, Complex &c3) {
		out << "c3.a: " << c3.a << " c3.b: " << c3.b << endl;
		return out;
	}

public:
	Complex(T a, T b) {
		this->a = a;
		this->b = b;
	}

	Complex operator+ (Complex &c2) {
		Complex c3(a+c2.a, b+c2.b);
		return c3;
	}

	void print() {
		cout << "a: " << a << " b: " << b << endl;
	}
private:
	T a;
	T b;
};

/*
ostream& operator<<(ostream &out, Complex &c3) {
	out << "c3.a: " << c3.a << " c3.b: " << c3.b << endl;
	return out;
}
*/

#endif /* TEMPLATE_ALL_FUNCTION_IN_CLASS_INNER_HPP_ */
