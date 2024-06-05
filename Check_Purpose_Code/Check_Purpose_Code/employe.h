#pragma once
#include<string>
using namespace std;

class Employe
{
private:
    string name;
    int empId;
    string dept;
    static int counter;

public:
    Employe();
    Employe(const string& ,int ,  const string&);
    Employe(const Employe&);
    void setData(string, int, string);
    string getName() const;
    int getId() const;
    string getDept() const;
    void printData();
    static int getTotalEmp ();

    ~Employe() {};
};



/*
#include <string>

class Employee {
private:
    std::string name;
    int id;
    double salary;

public:
    // Default constructor
    Employee();

    // Parameterized constructor
    Employee(const std::string& name, int id, double salary);

    // Copy constructor
    Employee(const Employee& other);

    // Getters
    std::string getName() const;
    int getId() const;
    double getSalary() const;

    // Setters
    void setName(const std::string& name);
    void setId(int id);
    void setSalary(double salary);
};
*/
