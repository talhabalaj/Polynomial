#pragma once
class Polynomial
{
private:
	double* coeff;
	int length;
public:
	Polynomial();
	Polynomial(double [], int);
	Polynomial(int);
	Polynomial(const Polynomial&);
	int getDegree();
	double* getCoeffArray();
	char* toString();
	double evaluate(double);
	Polynomial operator+(const Polynomial&);
	Polynomial operator=(const Polynomial&);
	Polynomial operator*(const Polynomial&);
	~Polynomial();
};

