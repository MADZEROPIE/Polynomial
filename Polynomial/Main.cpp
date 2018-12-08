#include "pch.h"
#include <iostream>
#include "Polynomial.h"
#include <locale.h>

using namespace std;



int main()
{
	setlocale(LC_CTYPE, "rus");
	Polynomial a(2);
	cout << "Полином a" << endl;
	a.set_pol();
	Polynomial b(4);
	cout << "Полином b" << endl;
	b.set_pol();
	
	a.print_pol();
	b.print_pol();
	//c = a;
	//c.print_pol();
	//b += a;
	//b.print_pol();
	//b -= a;
	//b.print_pol();
	cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
	Polynomial c = a - b;
	(a - b).print_pol();
	cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;
	c = a;
	(a*b).print_pol();
	//c.print_pol();
	//a.print_pol();
	//b.print_pol();
	
	//c.print_pol();
	//c = a - b;
	//c.print_pol();
	//c = a * 2;
	//c.print_pol();

}
