#include<iostream>
#include<fstream>
using namespace std;

void addMat(int**, int**, int**, int, int);

int main() {
	fstream infile("D:\\Oop\\matrix.txt",ios::in);
	int row, col, i, j;
	if (infile)
	{
		infile >> row >> col;
		int** m1, ** m2, ** sum;
		m1 = new int*[row];
		m2 = new int*[row];
		sum = new int*[row];
		for ( i = 0; i < row; i++)
		{
			m1[i] = new int[col];
			m2[i] = new int[col];
			sum[i] = new int[col];
		}

		for ( i = 0; i < row; i++)
		{
			for ( j = 0; j < col; j++)
			{
				infile >> m1[i][j];
			}
		}
		for ( i = 0; i < row; i++)
		{
			for ( j = 0; j < col; j++)
			{
				infile >> m2[i][j];
			}
		}
		infile.close();

		addMat(m1, m2, sum, row, col);
		infile.open("D:\\Oop\\matrix.txt", ios::app);

		infile << endl << endl;

		for ( i = 0; i < row; i++)
		{
			for ( j = 0; j < col; j++)
			{
				infile << sum[i][j] << "\t";
			}
			infile << endl;
		}
		infile.close();

		for ( i = 0; i < row; i++)
		{
			delete[] m1[i];
			delete[] m2[i];
			delete[] sum[i];
		}
		delete[] m1;
		delete[] m2;
		delete[] sum;

	}
	else
	{
		cout << "error! file does not open" << endl;
	}


	return 0;
}


void addMat(int**mat, int**mat2, int**sum, int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum[i][j] = mat[i][j] + mat2[i][j];
		}
	}
}