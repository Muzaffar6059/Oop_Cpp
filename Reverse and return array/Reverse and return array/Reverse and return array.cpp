#include<iostream>
using namespace std;

int *reverseArr(int *ptr, int length){
	int* revArr = new int[length];
	for (int i = 0; i < length; ++i) {
		revArr[i] = ptr[length - 1 - i];
	}
	return revArr;

}


int main() {

	int length;
	cout << "Enter the length of array: " << endl;
	cin >> length;

	int* ptr = new int[length];

	cout << "Enter the elements of the array: " << endl;
	for (int i = 0; i < length; i++)
	{
		cin >> ptr[i];
	}
	
	int* ptr2 = reverseArr(ptr, length);

	for (int i = 0; i < length; i++)
	{
		cout << *(ptr2+i) << " ";
	}


	delete[] ptr;

	return 0;
}