#include<iostream>
using namespace std;

void readData(int arr[], int size) {
    cout << "Enter the array:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}
void displayData(int arr[], int size) {
    cout << "Array:";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

void deleteArray(int arr[], int& size, int index) {
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}
int main() {
    const int SIZE = 20;
    int arr[SIZE];
    int count, index;
    do {
        cout << "Enter the value in range 1-20:";
        cin >> count;
    } while (count <= 0 || count > 20);
    readData(arr, count);
    do {
        cout << "Enter index (to delete) range 0-" << count - 1 << endl;
        cin >> index;
    } while (index<0 || index>count);
    deleteArray(arr, count, index);
    displayData(arr, count);
}