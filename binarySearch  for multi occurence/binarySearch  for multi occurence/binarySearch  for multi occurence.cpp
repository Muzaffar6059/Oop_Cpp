#include<iostream>
using namespace std;

void binarySearch(int arr[], int size, int target) {
	int start = 0, end = size - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == target)
		{
			cout << "the target value is present at the index: " << mid;

			int another = mid;
			while (arr[another] == arr[another - 1]) {
				cout << " " << --another;
			}
			while (arr[mid] == arr[mid + 1]) {
				cout << " " << ++mid;
			}
			break;
		}
		if (arr[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
}

int main() {
	const int size = 9;
	int arr[size] = { 1,2,3,4,4,5,6,6,6 };
	binarySearch(arr, size, 4);
	cout << endl;
	binarySearch(arr, size, 6);
	return 0;
}