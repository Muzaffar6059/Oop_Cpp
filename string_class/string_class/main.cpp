#include "MyString.h"
using namespace std;

int main() {
    MyString str1("");
    MyString str2("World");
    MyString str3 = str1 + str2;
    cout << str3 << endl; 

    str3[0] = 'h';
    cout << str3 << std::endl; 

    cout << (str1 == str2) << endl;  // 0 (false)
    cout << (str1 != str2) << endl;  // 1 (true)
    MyString obj("I am Muzaffar Ali Student of BS CS");
    MyString subStr = obj(5, 12);
    cout << subStr << endl;

    return 0;
}

