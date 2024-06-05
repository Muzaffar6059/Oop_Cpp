#include "MyString.h"

MyString::MyString() : data(nullptr), length(0) {}

// Conversion constructor with int parameter
MyString::MyString(int num) {
    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    int temp = num;
    length = 0;
    do {
        length++;
        temp /= 10;
    } while (temp != 0);

    if (isNegative) {
        length++;
    }

    data = new char[length + 1];

    data[length] = '\0';

    for (int i = length - 1; i < length; --i) {
        data[i] = (num % 10) + '0';
        num /= 10;
    }

    // Add negative sign for negative numbers
    if (isNegative) {
        data[0] = '-';
    }
}

// convert Constructor with parameter char*
MyString::MyString(const char* str) {
    if (str) {
        length = my_strlen(str);
        data = new char[length + 1];
        my_strcpy(data, str);
    }
    else {
        data = nullptr;
        length = 0;
    }
}

// Copy constructor
MyString::MyString(const MyString& other) {
    length = other.length;
    if (length) {
        data = new char[length + 1];
        my_strcpy(data, other.data);
    }
    else {
        data = nullptr;
    }
    cout << "Copy constructor is called" << endl;

}

// Destructor
MyString::~MyString() {
    delete[] data;
}

// Copy assignment operator
MyString& MyString::operator=(const MyString& other) {
    if (this == &other) return *this;

    delete[] data;
    length = other.length;
    if (length) {
        data = new char[length + 1];
        my_strcpy(data, other.data);
    }
    else {
        data = nullptr;
    }
    return *this;
}

// Concatenation operator
MyString MyString::operator+(const MyString& other) const {
    int newLength = length + other.length;
    char* newData = new char[newLength + 1];

    if (data) {
        my_strcpy(newData, data);
    }
    if (other.data) {
        my_strcat(newData, other.data);
    }

    MyString newString(newData);
    delete[] newData;
    return newString;
}

// Indexing operator
char& MyString::operator[](int index) {
    if (index >= length) {
        MyString temp("");
        return temp[0];
    }
    return data[index];
}

MyString MyString::operator()(int start, int leng) const {
    if (start >= length) {
        MyString temp("");
        return temp;
    }

    //length of the substring
    int substrLen = leng;
    if (start + leng > length) {
        substrLen = length - start;
    }

    char* substring = new char[substrLen + 1];

    for (int i = 0; i < substrLen; ++i) {
        substring[i] = data[start + i];
    }
    substring[substrLen] = '\0';

    MyString result(substring);
    delete[] substring;

    return result;
}

// Insertion operator
istream& operator>>(istream& CIN, MyString& str) {
    char temp[1000];
    CIN >> temp;

    str = MyString(temp);
    return CIN;
}

// Exrtraction operator
ostream& operator<<(ostream& COUT, const MyString& str) {
    if (str.data) {
        COUT << str.data;
    }
    return COUT;
}

// Equality operator
bool MyString::operator==(const MyString& other) const {
    if (length != other.length) return false;
    for (int i = 0; i < length; ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

// Inequality operator
bool MyString::operator!=(const MyString& other) const {
    return !(*this == other);
}

bool MyString::operator<(const MyString& other) const {
    for (int i = 0; data[i] != '\0' || other.data[i] != '\0'; ++i) {
        char char1 = data[i];
        char char2 = other.data[i];

        // Convert characters to lowercase for comparison
        if (char1 >= 'A' && char1 <= 'Z') {
            char1 += 32;
        }
        if (char2 >= 'A' && char2 <= 'Z') {
            char2 += 32;
        }

        if (char1 != char2) {
            return char1 < char2;
        }

        if (data[i] == '\0' && other.data[i] != '\0') {
            return true;
        }
    }
    return false;
}

bool MyString::operator<=(const MyString& other) const {
    return !(*this > other);
}

bool MyString::operator>(const MyString& other) const {
    for (int i = 0; data[i] != '\0' || other.data[i] != '\0'; ++i) {
        char char1 = data[i];
        char char2 = other.data[i];

        // Convert characters to lowercase for comparison
        if (char1 >= 'A' && char1 <= 'Z') {
            char1 += 32;
        }
        if (char2 >= 'A' && char2 <= 'Z') {
            char2 += 32;
        }

        if (char1 != char2) {
            return char1 > char2;
        }

        if (data[i] != '\0' && other.data[i] == '\0') {
            return true;
        }
    }
    return false;
}


bool MyString::operator>=(const MyString& other) const {
    return !(*this < other);
}

// Manual implementation of strlen
int MyString::my_strlen(const char* str) const {
    int len = 0;
    while (str[len] != '\0') {
        ++len;
    }
    return len;
}

// Manual implementation of strcpy
void MyString::my_strcpy(char* dest, const char* src) const {
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}

// Manual implementation of strcat
void MyString::my_strcat(char* dest, const char* src) const {
    while (*dest != '\0') {
        ++dest;
    }
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
}