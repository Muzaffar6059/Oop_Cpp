#include <iostream>
using namespace std;

int strLen(char arr[]) {
    int i = 0;
    while (arr[i++] != '\0');
    return i;
}
void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;
    while (start< end)
    {
        int temp = arr[end];
        arr[end] = arr[start];
        arr[start] = temp;

        start++;
        end--;
    }
}
void reverseArray(char arr[]) {
    int size = strLen(arr);
    int start = 0, end = size - 2;
    while (start< end)
    {
        char temp = arr[end];
        arr[end] = arr[start];
        arr[start] = temp;

        start++;
        end--;
    }
}


int main()
{
    const int size = 12;
    const int charSize = 100;
    int arr[size] = {1,2,3,4,5,6,7,8,9,10,11,12};

    char charArr[charSize] = "This is";
    cout << "Normal Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    reverseArray(arr, size);
    
    cout << "\nReversed Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << endl << charArr;

    reverseArray(charArr);
    cout << "\n The reverse char array: " << endl;
    cout << endl << endl << charArr;
    return 0;
}