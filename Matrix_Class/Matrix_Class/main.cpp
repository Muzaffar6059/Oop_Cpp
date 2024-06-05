#include "Matrix.h"

using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns for the matrices: ";
    cin >> rows >> cols;

    Matrix m1(rows, cols);
    cout << "Enter the elements of the first matrix:" << endl;
    cin >> m1;

    Matrix m2(rows, cols);
    cout << "Enter the elements of the second matrix:" << endl;
    cin >> m2;

    Matrix m3 = m1 + m2;
    Matrix m4 = m1 - m2;
    cout << "Sum of Matrix 1 and Matrix 2 (m3):" << endl << m3;
    cout << "Difference of Matrix 1 and Matrix 2 (m4):" << endl << m4;

    m1 += m2;
    cout << "Matrix 1 after += operator: \n" << m1;

    m1 -= m2;
    cout << "Matrix 1 after -= operator:\n" << m1;
    
    m1 *= m2;
    cout << "Matrix 1 after *= operator\n" << m1;

 

    bool isEqual = (m1 == m2);
    bool isNotEqual = (m1 != m2);

    cout << "Matrix 1 " << (isEqual ? "is equal to" : "is not equal to") << " Matrix 2\n";
    cout << "Matrix 1 " << (isNotEqual ? "is not equal to" : "is equal to") << " Matrix 2\n";

    return 0;
}
