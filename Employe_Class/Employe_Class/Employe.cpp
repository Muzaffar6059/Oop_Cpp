#include"employe.h"
#include<iostream>

Employe::Employe() : name(""), empId(0), dept("") {
	++counter;
}

Employe::Employe(const string& name, int id, const string& dept) {
	this->name = name;
	this->empId = id;
	this->dept = dept;
	++counter;
}

Employe::Employe(const Employe& other) {
	name = other.name;
	empId = other.empId;
	dept = other.dept;
	++counter;
}

void Employe::setData(string name, int id, string dept) {
	this->name = name;
	this->empId = id;
	this->dept = dept;
}

string Employe::getName() const {
	return name;
}
int Employe::getId() const {
	return empId;
}
string Employe::getDept() const {
	return dept;
}

void Employe::printData() {
	cout << "Name: " << name << endl;
	cout << "ID: " << empId << endl;
	cout << "Dept: " << dept << endl;
}


 int Employe::getTotalEmp() {
	return counter;
}

 int Employe::counter = 0;