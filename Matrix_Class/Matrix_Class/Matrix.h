#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

    void allocateMemory();
    void deallocateMemory();

public:
    // Constructors
    Matrix();
   
    // parameterized Constructor
    Matrix(int r, int c);
    
    //Copy Constructor
    Matrix(const Matrix& other);
    
    //Destructor
    ~Matrix();

    // Operator overloads
    Matrix operator+(const Matrix& other) const;

    Matrix operator-(const Matrix& other) const;

    Matrix operator*(const Matrix& other) const;

    Matrix& operator=(const Matrix& other);

    Matrix& operator+=(const Matrix& other);

    Matrix& operator-=(const Matrix& other);

    Matrix& operator*=(const Matrix& other);

    bool operator==(const Matrix& other) const;

    bool operator!=(const Matrix& other) const;

    void print() const;

    //insertion and extraction
    friend ostream& operator<<(ostream& , const Matrix& );
    friend istream& operator>>(istream& , Matrix& );

};



