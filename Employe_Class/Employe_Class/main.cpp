#include<iostream>
#include"employe.h"

int main() {

	Employe emp1, emp2("Muzaffar Ali", 7, "Computer Sceince"), emp3, emp4;
	emp3.setData("Sajid Ali", 23, "BBA");
	emp4 = emp2;
	emp1.printData();
	cout << endl;
	emp2.printData();
	cout << endl;
	emp3.printData();
	cout << endl;
	emp4.printData();

	cout << endl;
	cout << "Total employees: " << Employe::getTotalEmp() << endl;

	return 0;
}