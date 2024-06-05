#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

struct date {
	int day;
	int month;
	int year;
};

struct Student {
	char regNo[11];
	char name[35];
	date dob;
	int subMarks[5];
};

bool dateVal(int, int);
bool marksVal(int);

int main() {

	const int SIZE = 1;
	Student std[SIZE];
	int i, j;


	ofstream file("Student.dat", ios::binary);
	if (!file)
	{
		cout << "Error";
	}
	else
	{
		cout << "Enter the detail of student: " << endl;
		for (i = 0; i < SIZE; i++)
		{
			cout << "detail of student " << i + 1 << " :" << endl;
			cout << "Enter the registration No: ";
			cin >> std[i].regNo;
			cout << "Enter student name: ";
			cin.ignore();
			cin.getline(std[i].name, 40);
			do
			{
				cout << "Enter the Valid Date of birth: " << endl;
				cout << "Year: ";
				cin >> std[i].dob.year;
				cout << "Month: ";
				cin >> std[i].dob.month;
				cout << "Date: ";
				cin >> std[i].dob.day;

			} while (!dateVal(std[i].dob.month, std[i].dob.day));

			cout << "Enter the marks of five Subjects: " << endl;
			for (j = 0; j < 5; j++)
			{
				cout << "Subject " << j + 1 << ": ";
				cin >> std[i].subMarks[j];
				while (!marksVal(std[i].subMarks[j]))
				{
					cout << "Enter the Valid Marks: ";
					cin >> std[i].subMarks[j];
				}
			}
		}
	}
	file.write((char*)&SIZE, sizeof(int));
	file.write((char*)&std, sizeof(Student) * SIZE);

	file.close();


	/*fstream file("Student.dat", ios::binary | ios::out | ios::in);
	int size;
	file.read((char*)&size, sizeof(int));
	file.read((char*)&std, sizeof(Student) * size);
	file.close();
	cout << "SIZE : " << size << endl;
	cout << "*********STUDENT DETAIL*********" << endl;
	cout << "Reg_No\t\t" << setw(20) << "Student  Name\t\t" << "Date of Birth\t\t" << "Marks in 5 Sub" << endl << endl;
	for (i = 0; i < size; i++)
	{
		cout << left << std[i].regNo << "\t\t" << left << setw(20)
			<< std[i].name << "\t\t" << left << std[i].dob.day << left << "/" << left
			<< std[i].dob.month << "/" << left << std[i].dob.year << " \t\t";
		for (j = 0; j < 5; j++)
		{
			cout << left << std[i].subMarks[j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}

bool marksVal(int marks) {
	if (marks < 0 || marks>100)
		return false;

	return true;
}

bool dateVal(int month, int day) {

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;

}