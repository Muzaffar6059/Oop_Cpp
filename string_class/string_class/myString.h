#include <iostream>
using  namespace std;

class MyString {
private:
    char* data;
    int length;

    // insertion operator
    friend ostream& operator<<(ostream&, const MyString&);

    // Extraction operator
    friend istream& operator>>(istream&, MyString&);

public:
    MyString();

    // Conversion constructor from int
    MyString(int num);

    // Convert Constructor with parameter char*
    MyString(const char* );

    // Copy constructor
    MyString(const MyString& );

    // Destructor
    ~MyString();

    // Copy assignment operator
    MyString& operator=(const MyString& );

    // Concatenation operator
    MyString operator+(const MyString& ) const;

    // Indexing operator
    char& operator[](int );
     
    //()operator 
    MyString operator()(int, int) const;

    const char& operator[](int ) const;

    // Equality operator
    bool operator==(const MyString& ) const;

    // Inequality operator
    bool operator!=(const MyString& ) const;

    // Comparison operators
    bool operator<(const MyString& other) const;
    bool operator<=(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator>=(const MyString& other) const;

    int my_strlen(const char*) const;

    void my_strcpy(char* dest, const char* src) const;

    void my_strcat(char* dest, const char* src) const;
};


