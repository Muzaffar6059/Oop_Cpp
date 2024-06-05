// #include<iostream>
// #include<ctype.h>
// using namespace std;

// int strComp(const char[], const char[]);

// int main(){
//     char str1[50]="HelloW", str2[50]="Hellowt";
//     if(strComp(str1, str2)==0){
//         cout<<"both string are equals"<<endl;
//         }
//     else if(strComp(str1, str2)<0){
//         cout<<"first word is smaller than the second word"<<endl;
//         // cout<<strComp(str1, str2);
//     }
//     else{
//         cout<<"first word is greater than the second word" <<endl;
//         // cout<<strComp(str1, str2);
//     }
//     return 0;
// }


// // compare function without case sensitive 
// int strComp(const char str1[], const char str2[]){
//     int i;
//     for (i = 0; str1[i] && str2[i]; i++)
//     {
//         char c1 = tolower(str1[i]);
//         char c2 = tolower(str2[i]);
//         if(c1 != c2)
//             return c1 - c2;
//     }
//     return 0;    
// }
// // compare function with case sensitive 
// /*
// int strComp(const char str1[], const char str2[]){
//     int i;
//     for (i = 0; str1[i] && str2[i]; i++)
//     {
//         if(str1[i]!=str2[i])
//             return str1[i]-str2[i];
//     }
//     return 0;
// }
// */


#include<iostream>
using namespace std;

int deleteElementFromArray(int arr[], int size, int keyIndex){
    int j=0 ,i=0;
    if(keyIndex >size ){
        cout<< "Index is out of the range: " <<endl;
    for (; i < size; i++, j++)
    {
        if(i == keyIndex){
            j++;
        }
        if(i == size - 1){
            arr[i] = 0;
            break;
        }
        arr[i] = arr[j];
    }
    return size-1;
}

int main(){
    const int n = 5;
    int arr[n]={1,2,3,4,5};

    int keyIndex;
    cout<<"Enter the key index wanna delete: "<<endl;
    cin>>keyIndex;
    cout<<"Array before delete: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i] <<"\t";
    }

    int newSize = deleteElementFromArray(arr,n,keyIndex);

    cout<<"\nArray After delete: "<<endl;
    for (int i = 0; i < newSize; i++)
    {
        cout<<arr[i] <<"\t";
    }
    
    return 0;
}
