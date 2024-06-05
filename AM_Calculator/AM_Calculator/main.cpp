#include<iostream>
#include"Calculator.h"

int main() {

	Calculator num1(10), num2(20), result;
	result = num1 + num2;

	cout << "Sum = " << result << endl;

	result = num1 - num2;

	cout << "Diff = " << result << endl;

	result = num2 * num1;
	
	cout << "Product = " << result << endl;
	
	result = num2 / num1;

	cout << "Division = " << result << endl;
	
	return 0;
}