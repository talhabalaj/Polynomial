#include "Polynomial.h"
#include <iostream>
#include <string>
using namespace std;

Polynomial::Polynomial()
{
	coeff = nullptr;
	length = 0;
}

Polynomial::Polynomial(int length)
{
	this->length = length;
	// Allocating memory
	coeff = new double[length];
	for (int i = 0; i < length; i++) coeff[i] = 0;
}

Polynomial::Polynomial(double a[], int length)
{
	this->length = length; 
	// Allocating memory and copying elements to it
	coeff = new double[length];
	for (int i = 0; i < length; i++) coeff[i] = a[i];

}
Polynomial::Polynomial(const Polynomial& o) {
	this->length = o.length;
	// Allocating memory and copying elements to it
	coeff = new double[length];
	for (int i = 0; i < length; i++) coeff[i] = o.coeff[i];
}
int Polynomial::getDegree() {
	return length - 1;
}
char* Polynomial::toString() {
	string polyString;
	for (int i = length - 1; i >= 0; i--) {
		polyString += to_string((int)coeff[i]) + (i == 0 ? "" : "x^" + to_string(i));
		if (i == 0) {
			continue;
		}
		else {
			polyString += " + ";
		}
	}
	int finalLength = polyString.length();
	char* toReturn = new char[finalLength + 1];
	for (int i = 0; i < finalLength; i++) toReturn[i] = polyString[i];
	toReturn[finalLength] = '\0';
	return toReturn;
}
double Polynomial::evaluate(double x) {
	int sol = 0;
	for (int i = 0; i < length; i++) {
		sol += pow(x, i) * coeff[i];
	}
	return sol;
}

Polynomial Polynomial::operator+(const Polynomial& o) {
	Polynomial temp;
	if (o.length > this->length) {
		// Attributes of greater one
		temp.coeff = new double[o.length];
		temp.length = o.length;
		
		for (int i = 0; i < o.length; i++) {
			temp.coeff[i] = o.coeff[i];
			if (i < this->length) temp.coeff[i] += this->coeff[i];
		}
	}
	else {
		// Attributes of greater one
		temp.coeff = new double[length];
		temp.length = length;

		for (int i = 0; i < length; i++) {
			temp.coeff[i] = coeff[i];
			if (i < o.length) temp.coeff[i] += o.coeff[i];
		}
	}
	return temp;
}
Polynomial Polynomial::operator=(const Polynomial& o) {
	this->coeff = new double[o.length];
	this->length = o.length;
	for (int i = 0; i < o.length; i++) coeff[i] = o.coeff[i];
	return *this;
}

Polynomial::~Polynomial()
{
	delete[] coeff;
}

double* Polynomial::getCoeffArray() {
	return coeff;
}

Polynomial Polynomial::operator*(const Polynomial& o) {
	int resultLength = o.length + length - 1;
	Polynomial result(resultLength);
	for (int i = 0; i < o.length; i++) {
		for (int j = 0; j < length; j++) {
			int Rcoeff = coeff[i] * o.coeff[j];
			int power = i + j;
			result.coeff[power] += Rcoeff;
		}
	}
	return result;
}