#pragma once
#include<iostream>
#include<string>
using namespace std;

class Complex
{
private:
	int real, img;
public:
	Complex();
	Complex(int, int);
	Complex(Complex&);
	void setReal(int);
	void setImg(int);
	void setData(int, int);
	int getReal() const;
	int getImg() const;
	void getData(int&, int&) const;
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream& COUT, Complex& complex);
	Complex& operator++();
	Complex& operator++(int);
	void print();

};

