#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
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

char menu();
bool valDate(int, int);
bool marksVal(int);
void insert(Student*, int, int&);
int findData(Student*, int, char[]);
void printData(Student*, int);
void deleteData(Student*, int&);
void printSingleData(const Student&);
void modifyData(Student*, int);
void writeData(Student std[], int);

int main() {

	// Part A of the assignment.
	/*
	const int SIZE = 5;
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
	*/

	const int MAX = 10;
	int currSize, i, j, index;
	Student std[MAX];
	char option;
	bool flag = true;

	fstream file("D:\\Oop\\Assignment_No_1\\trail_B\\trail_B\\Student.dat", ios::binary | ios::in );
	if (!file)
	{
		cout << "Error";
	}
	else
	{
		file.read((char*)&currSize, sizeof(int));
		file.read((char*)&std, sizeof(Student) * currSize);
		file.close();
	}
		cout << "\tStudent Data" << endl;
		cout << "*******************************" << endl;
		cout << "Insert\t\t:\t[I/i]" << endl;
		cout << "Delete\t\t:\t[D/d]" << endl;
		cout << "Modify\t\t:\t[M/m]" << endl;
		cout << "Find\t\t:\t[F/f]" << endl;
		cout << "Print\t\t:\t[P/p]" << endl;
		cout << "Quit\t\t:\t[Q/q]" << endl;
		cout << "Enter Option\t:\t";

		cin >> option;

		while (flag)
		{
			switch (option)
			{
			case 'I':
			case 'i':
				insert(std, MAX, currSize);
				cout << "Data is successfully inserted" << endl;
				option = menu();
				break;
			case 'P':
			case 'p':
				printData(std, currSize);
				cout << endl << endl;
				option = menu();
				break;
			case 'M':
			case 'm':
				modifyData(std, currSize);
				cout << endl << endl;
				option = menu();
				break;
			case 'D':
			case 'd':
				deleteData(std, currSize);
				cout << "\nThe record is Deleted successfully." << endl << endl;
				option = menu();
				break;
			case 'F':
			case 'f':
			{
				char regno[11];
				cout << "\n\nEnter the Reg No to Find:" << endl;
				cin >> regno;
				system("cls");
				int findIndex = findData(std, currSize, regno);
				if (findIndex >= 0)
				{
					printSingleData(std[findIndex]);
				}
				else
				{
					cout << "\n\t\Record does not found..." << endl;
				}
				cout << endl << endl;
				option = menu();
				break;
			}
			case 'Q':
			case 'q':
				writeData(std, currSize);
				flag = false;
				break;
			default:
				cout << "\n\t\tInvalid Option: " << endl;
				Sleep(1000);
				system("cls");
				option = menu();
				break;
			}
		//}
	}

	return 0;
}
char menu() {

	char option;
	cout << "\tStudent Data" << endl;
	cout << "*******************************" << endl;
	cout << "Insert\t\t:\t[I/i]" << endl;
	cout << "Delete\t\t:\t[D/d]" << endl;
	cout << "Modify\t\t:\t[M/m]" << endl;
	cout << "Find\t\t:\t[F/f]" << endl;
	cout << "Print\t\t:\t[P/p]" << endl;
	cout << "Quit\t\t:\t[Q/q]" << endl;
	cout << "Enter Option\t:\t";

	cin >> option;

	return option;
}

void insert(Student* std, int size, int& currentSize) {
	int i, j, index;
	if (currentSize == size)
	{
		cout << "\nThere is No Space to insert a new Record:" << endl;
	}
	else
	{
		cout << "\nEnter the index where to insert between 0 to " << currentSize - 1 << " :" << endl;
		cin >> index;
		while (index<0 || index > currentSize)
		{
			cout << "Invalid index Enter between 0 to " << currentSize - 1 << " :" << endl;
			cin >> index;
		}

		system("cls");
		for (i = size; i > index; i--)
		{
			std[i] = std[i - 1];
		}
		cout << "\ndetail of student " << endl;
		cout << "Enter the registration No: ";
		cin >> std[index].regNo;
		cout << "Enter student name: ";
		cin.ignore();
		cin.getline(std[index].name, 40);
		do
		{
			cout << "Enter the Valid Date of birth: " << endl;
			cout << "Year: ";
			cin >> std[index].dob.year;
			cout << "Month: ";
			cin >> std[index].dob.month;
			cout << "Date: ";
			cin >> std[index].dob.day;

		} while (!valDate(std[index].dob.month, std[index].dob.day));
		cout << "Enter the marks of five Subjects: " << endl;
		for (j = 0; j < 5; j++)
		{
			cout << "Subject " << j + 1 << ": ";
			cin >> std[index].subMarks[j];
			while (!marksVal(std[index].subMarks[j]))
			{
				cout << "Enter the Valid Marks: ";
				cin >> std[index].subMarks[j];
			}
		}
	}
	currentSize++;

	system("cls");
	Sleep(400);

}

void deleteData(Student* std, int& currentSize) {
	cout << "\nEnter the Reg No of the record you want to delete: " << endl;
	char regno[11];
	cin >> regno;

	if (currentSize == 0)
	{
		system("cls");
		Sleep(400);
		cout << "There is no record to delete first insert at least one record." << endl;
		return;

	}
	else if (findData(std, currentSize, regno) < 0)
	{
		system("cls");
		Sleep(400);
		cout << "Record does not exist " << endl;
		return;
	}

	int index = findData(std, currentSize, regno);

	for (int i = index; i < currentSize - 1; i++) {
		std[i] = std[i + 1];
	}

	currentSize--;
	system("cls");
	Sleep(400);
}
void printData(Student* std, int currentSize) {

	system("cls");
	Sleep(400);

	int i, j;
	cout << endl;
	cout << "\t\t\t*********STUDENT DETAIL*********" << endl << endl;
	cout << "Reg_No\t\t" << setw(20) << "Student  Name\t\t" << "Date of Birth\t\t" << "Marks in 5 Sub" << endl;
	for (i = 0; i < currentSize; i++)
	{
		cout << left << std[i].regNo << "\t\t" << left << setw(20)
			<< std[i].name << "\t\t" << left << std[i].dob.day << left << "/" << left
			<< std[i].dob.month << "/" << left << std[i].dob.year << " \t\t";
		for (j = 0; j < 5; j++)
		{
			cout << left << std[i].subMarks[j] << " ";
		}
		cout << endl;
	}
}

void printSingleData(const Student& std) {
	cout << "\nReg_No\t\t" << setw(20) << "Student  Name\t\t" << "Date of Birth\t\t" << "Marks in 5 Sub" << endl;
	int j;
	cout << left << std.regNo << "\t\t" << left << setw(20)
		<< std.name << "\t\t" << left << std.dob.day << left << "/" << left
		<< std.dob.month << "/" << left << std.dob.year << " \t\t";
	for (j = 0; j < 5; j++)
	{
		cout << left << std.subMarks[j] << " ";
	}
	cout << endl;
}

int findData(Student* std, int currentSize, char rNo[]) {

	for (int i = 0; i < currentSize; i++)
	{
		if (strcmp(std[i].regNo, rNo) == 0)
		{
			return i;
		}
	}
	return -1;
}

void modifyData(Student* std, int currentSize) {
	cout << "\nEnter the Reg No of record to modify: " << endl;
	char regno[11];
	cin >> regno;

	if (findData(std, currentSize, regno) < 0)
	{
		system("cls");
		Sleep(400);
		cout << "Record does not exist " << endl;
		return;
	}

	int index = findData(std, currentSize, regno);
	char option;
	system("cls");

	cout << "\tModify Options" << endl;
	cout << "*******************************" << endl;
	cout << "Reg No\t\t:\t[R/r]" << endl;
	cout << "Name\t\t:\t[N/n]" << endl;
	cout << "Date of birth\t:\t[D/d]" << endl;
	cout << "Subjects Marks\t:\t[S/s]" << endl;
	cout << "Enter Option\t:\t";

	cin >> option;

	switch (option)
	{
	case 'R':
	case 'r':
		cout << "\nEnter the new Registration No: " << endl;
		cin >> std[index].regNo;
		break;
	case 'N':
	case 'n':
		cout << "\nEnter the new Name: " << endl;
		cin.ignore();
		cin.getline(std[index].name, 40);
		break;
	case 'D':
	case 'd':
		do
		{
			cout << "\nEnter the new valid Date of birth: " << endl;
			cout << "Year: ";
			cin >> std[index].dob.year;
			cout << "Month: ";
			cin >> std[index].dob.month;
			cout << "Date: ";
			cin >> std[index].dob.day;

		} while (!valDate(std[index].dob.month, std[index].dob.day));
		break;
	case 'S':
	case 's':
		cout << "\nEnter the new Subjects Marks: " << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "Subject " << j + 1 << ": ";
			cin >> std[index].subMarks[j];
			while (!marksVal(std[index].subMarks[j]))
			{
				cout << "Enter the Valid Marks: ";
				cin >> std[index].subMarks[j];
			}
		}
		break;
	default:
		break;
	}
	system("cls");
	Sleep(400);
}

void writeData(Student std[], int currentSize) {
	fstream outfile("D:\\Oop\\Assignment_No_1\\trail_B\\trail_B\\Student.dat", ios::binary | ios::in  | ios::out);
	
	outfile.write((char*)&currentSize, sizeof(int));
	for (int i = 0; i < currentSize; i++)
	{
		outfile.write((char*)&std[i], sizeof(Student));
	}
	//outfile.write((char*)&std, sizeof(Student));
	outfile.close();
}

bool marksVal(int marks) {
	if (marks < 0 || marks>100)
		return false;

	return true;
}

bool valDate(int month, int day) {

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	return true;

}