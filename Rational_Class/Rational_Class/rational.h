#pragma once
#include<iostream>
using namespace std;
class Rational
{
private:
	int num;
	int denum;
public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);
	void setnum(int);
	void setdenum(int);
	void set(int, int);
	int getnum()const;
	int getdenum()const;
	void simplify();
	Rational operator+(const Rational& other);

};
