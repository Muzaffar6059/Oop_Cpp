#include "Calculator.h"
using namespace std;

Calculator::Calculator(): x(0){}

Calculator::Calculator(int n): x(n){}

Calculator Calculator:: operator+(const Calculator& other) {
	Calculator temp;
	temp.x = this->x + other.x;

	return temp;
}

Calculator Calculator:: operator-(const Calculator& other) {
	Calculator temp;
	temp.x = this->x - other.x;

	return temp;
}

Calculator Calculator:: operator*(const Calculator& other) {
	Calculator temp;
	temp.x = this->x * other.x;

	return temp;
}

Calculator Calculator:: operator/(const Calculator& other) {
	Calculator temp;
	if (other.x == 0)
	{
		cerr << "Error: Division by zero!" << endl;
	}
	else
	{
		temp.x = this->x / other.x;
	}

	return temp;
}

ostream& operator<<(ostream& COUT, const Calculator& cal) {
	COUT << cal.x;
	return COUT;
}