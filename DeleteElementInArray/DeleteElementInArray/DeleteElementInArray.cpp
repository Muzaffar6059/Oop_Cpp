#include<iostream>
using namespace std;

int deleteElementFromArray(int arr[], int size, int keyIndex) {
    int j = 0, i = 0;
    for (; i < size; i++, j++)
    {
        if (i == keyIndex) {
            j++;
        }
        if (i == size - 1) {
            arr[i] = 0;
            break;
        }
        arr[i] = arr[j];
    }
    return size - 1;
}

int main() {
    const int n = 5;
    int arr[n] = { 1,2,3,4,5 };

    int keyIndex;
    cout << "Enter the key index wanna delete: " << endl;
    cin >> keyIndex;
    cout << "Array before delete: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    int newSize = deleteElementFromArray(arr, n, keyIndex);

    cout << "\nArray After delete: " << endl;
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;
}