#pragma once
#include<iostream>
using namespace std;

class Calculator
{
private:
	int x;
public:
	Calculator();
	Calculator(int);
	Calculator operator+(const Calculator&);
	Calculator operator-(const Calculator&);
	Calculator operator*(const Calculator&);
	Calculator operator/(const Calculator&);
	friend ostream& operator<<(ostream&, const Calculator&);
};

