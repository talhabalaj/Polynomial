// PolynomialSovler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Polynomial.h"

using namespace std;

void printPoly(Polynomial& c) {
	double * coeff = c.getCoeffArray();
	int length = c.getDegree() + 1;

	cout << "Coefficients: ";
	for (int i = 0; i < length; i++) cout << coeff[i] << (i == length - 1 ? "" : ", ");
	cout << endl;
	cout << "toString(): " << c.toString() << endl;
	cout << "evaluate(2): " << c.evaluate(2) << endl;
	cout << "getDegree(): " << c.getDegree() << endl;
}

int main()
{
	double r[] = { 2, 2 };
	double s[] = { 2, 2 };
	Polynomial a(r, sizeof r / sizeof r[0]), b(s, sizeof s / sizeof s[0]);
	cout << "--- Polynomial A ---" << endl;
	printPoly(a);
	cout << "--- Polynomial B ---" << endl;
	printPoly(b);
	cout << "--- Polynomial C = A + B ---" << endl;
	Polynomial c(a + b);
	printPoly(c);
	cout << "--- Polynomial C = A * B ---" << endl;
	Polynomial d(a * b);
	printPoly(d);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
