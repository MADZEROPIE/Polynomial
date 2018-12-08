#include "pch.h"
#include <iostream>

class Polynomial
{
public:
	Polynomial();
	Polynomial(int n);
	~Polynomial();
	Polynomial(const Polynomial &other);
	Polynomial& operator = (Polynomial &other);
	Polynomial& operator += (Polynomial &other);
	Polynomial& operator -= (Polynomial & other);
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

Polynomial::Polynomial()
{
	arr = new int[1];
	arr[0] = 0;
	n = 0;
}

Polynomial::Polynomial(int n)
{
	arr = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		arr[i] = 0;
	this->n = n;
}

Polynomial::~Polynomial()
{
	std::cout << "AHDHJKAHJKHADHAUFNAWEGJA";
	//delete[] arr;
}

Polynomial::Polynomial(const Polynomial & other)
{
	this->n = other.n;
	arr = new int[other.n + 1];
	for (int i = 0; i <= n; i++)
		this->arr[i] = other.arr[i];
}

Polynomial & Polynomial::operator=(Polynomial & other)
{
	delete[] this->arr;
	this->n = other.n;
	arr = new int[other.n + 1];
	for (int i = 0; i <= n; i++)
		this->arr[i] = other.arr[i];
	return *this;

}

Polynomial & Polynomial::operator+=(Polynomial & other)
{
	
	Polynomial res(*this);
	int n1 = (this->n >= other.n) ? this->n : other.n;
	delete[] this->arr;
	this->arr = new int[n1 + 1];
	this->n = n1;
	for (int i = 0; i < n + 1; i++) {
		if ((i <= res.n) && (i <= other.n))
			this->arr[i] = res.arr[i] + other.arr[i];
		else {
			if (i > res.n)
				this->arr[i] = other.arr[i];
			else 
				this->arr[i] = res.arr[i];
		}
	}
	return *this;
	
}

Polynomial & Polynomial::operator-=(Polynomial & other)
{
	Polynomial res = (*this);
	//other = other * (-1);
	res += other;
	*this = (res);
	return *this;
}

Polynomial Polynomial::operator+(Polynomial & other)
{
	Polynomial res = (*this);
	Polynomial res2 = (res += other);
	return res2;
}

Polynomial Polynomial::operator-(Polynomial & other)
{
	Polynomial res = (*this);
	res -= other;
	return res;
}

Polynomial Polynomial::operator*(Polynomial & other)
{
	int R = (this->n )*(other.n);
	Polynomial res(R);
	for (unsigned int i = 0; i < this->n + 1; i++)
		for (unsigned int j = 0; j < other.n + 1; j++)
			if (j + i < R) res.arr[i + j] += other.arr[j] * this->arr[i];
	return res;
}

Polynomial Polynomial::operator*(int val)
{
	Polynomial res = (*this);
	if (val) {
		for (int i=0; i <= res.n; i++)
			res.arr[i] *= val;
		return res;
	}
	else {
		delete[] res.arr;
		res.n = 0;
		res.arr = new int[1];
		res.arr[0] = 0;
		return res;
	}
}

int Polynomial::value(int val)
{
	int res = 0;
	for (int i = 0; i <= this->n; i++)
		res += this->arr[i] * pow(val, n-i);
	return res;
}

void Polynomial::print_pol()
{
	for (int i = this->n; i >= 0; i--) {
		if (i&&arr[i])
			std::cout <<"(" <<arr[i] << ")" << "*x^" << i<<" + ";
		else if (!i)
			std::cout <<  arr[i];
	}
	std::cout << "\n";
}

using namespace std;
void Polynomial::set_pol()
{
	cout << "¬ведите степень многочлена: ";
	cin >> n;
	delete[] arr;
	arr = new int[n + 1];
	for (int i = n; i >= 0; i--) {
		cout << "¬ведите коэффициент перед степенью " << i<<":";
		cin >> arr[i];
		//std::cout << "\n";
	}
}
