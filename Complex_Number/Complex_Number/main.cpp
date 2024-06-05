#include<iostream>
#include"Complex.h"
using namespace std;

int main() {
	Complex c1, c2(2,-1), c3, c4,c5;
	c3.setData(4, -3);
	c4 = c2;

	int real, img;
	c4.getData(real, img);

	cin >> c5;
	cout << c1 << endl << c2 << endl << c3 << endl << ++c5 << endl;
	c4.print();

	return 0;
}
