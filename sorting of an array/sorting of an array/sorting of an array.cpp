#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // swaping 
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int binarySearch(int arr[], int size, int target) {
    int start = 0, end = size - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid]>target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size - 1; i++)
    {
        if (target == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    const int size = 6;
    int arr[size] = { 2,1,5,34,45,3 };

    selectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    //int result = binarySearch(arr, size, 34);
    int result = linearSearch(arr, size, 34);
    if (result<0)
    {
        cout << "\nThe Target element does not found: " << endl;
    }
    else
    {
        cout << "\nThe target element is found at the index : " << result << endl;
    }

    return 0;
}