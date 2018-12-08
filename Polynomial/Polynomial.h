#pragma once

class Polynomial
{
public:
	Polynomial();
	Polynomial(int n);
	~Polynomial();
	Polynomial(const Polynomial &other);
	Polynomial& operator = (Polynomial &other);
	Polynomial& operator += (Polynomial &other);
	Polynomial& operator -= (Polynomial &other);
	Polynomial operator + (Polynomial &other);
	Polynomial operator - (Polynomial &other);
	Polynomial operator * (Polynomial &other);
	Polynomial operator *(int val);
	int value(int val);
	void print_pol();
	void set_pol();

private:
	int n;
	int* arr;
};