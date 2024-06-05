#include "Complex.h"

Complex::Complex(): real(0), img(0){}

Complex::Complex(int r, int i): real(r), img(i){}

Complex::Complex(Complex& other) : real(other.real), img(other.img){}

void Complex::setReal(int r) {
	real = r;
}

void Complex::setImg(int i) {
	img = i;
}

void Complex::setData(int r, int i) {
	real = r;
	img = i;
}

int Complex::getReal() const {
	return real;
}

int Complex::getImg()  const {
	return img;
}

void Complex::getData(int& r, int& i)  const{
	r = real;
	i = img;
}

ostream& operator<<(ostream& COUT, const Complex& complex) {
	COUT << complex.real;
	if (complex.img < 0) {
		COUT << " - " << -complex.img << "i";
	}
	else
		COUT  << " + " << complex.img << "i";

	return COUT;
}

istream& operator>>(istream& IN, Complex& complex) {
	cout << "Enter the real part: \n";
	IN >> complex.real;
	cout << "Enter the img part: \n";
	IN >> complex.img;

	return IN;
}

Complex& Complex:: operator++() {

	++real;
	++img;

	return *this;
}

Complex& Complex:: operator++(int) {

	Complex temp(*this);
	/*++(*this);*/
	++real;
	++img;

	return temp;
}

void Complex:: print() {
	cout <<this->real;
	if (this->img < 0)
		cout << " - " << -this->img << "i" << endl;
	else
		cout << " + " << this->img << "i" << endl;
}