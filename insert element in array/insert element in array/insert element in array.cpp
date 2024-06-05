#include<iostream>
using namespace std;

void readData(int arr[], int size) {
	cout << "Enter the element of an array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

void displayData(int arr[], int size) {
	cout << "Element of An Array: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}

void insert(int arr[], int& size, int index) {
	int i;
	for ( i = size; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}
	cout << "Enter the new value: " << endl;
	cin >> arr[index];
	size++;
}

void deleteElement(int arr[], int& size, int index) {
	for (int i = index; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}
	size--;
}

int main() {
	const int SIZE = 8;
	int arr[SIZE];

	int count, index;

	do
	{
		cout << "Enter The size of an array within the range of 1-" << SIZE << ": " << endl;
		cin >> count;
	} while (count<=0 || count > SIZE);

	readData(arr, count);

	do
	{
		cout << "Enter index of new inserting Element in range of 0-" << (count - 1) << ":" << endl;
		cin >> index;
	} while (index <0 ||index > count-1);

	if (count < SIZE)
	{
		insert(arr, count, index);
		displayData(arr, count);
	}
	else
	{
		cout << "The Array is Already Full: " << endl;
	}

	do
	{
		cout << "\nEnter the index of Deleting element 0-" << count - 1 << endl;
		cin >> index;
	} while (index<0 || index>count);

	deleteElement(arr, count, index);
	displayData(arr, count);


	return  0;
}