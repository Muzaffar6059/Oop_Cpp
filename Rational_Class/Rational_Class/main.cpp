#include"rational.h"
void printRational(const Rational&);
void ReadRational(Rational&);
//Rational operator+(const Rational&, Rational&);
//Rational sum(const Rational&, Rational&);

int main()
{
	Rational r1, r2(6, 8), r3(10, 14);
	//r1.set(6, 24);
	printRational(r1);
	printRational(r2);
	printRational(r3);
	Rational r5 = r1 + r2;
	//Rational r5 = sum(r1, r2);
	cout << "Result is: \n";
	printRational(r5);

	return 0;

}
void printRational(const Rational & r)
{

	cout << r.getnum() << '/' << r.getdenum() << endl;
}
void ReadRational(Rational & r)
{
	int n, d;
	cout << "enter your numerator:" << endl;
	cin >> n;
	do
	{
		cout << "enter non zero denomenator:" << endl;
		cin >> d;

	} while (d == 0);

}
//Rational operator+(const Rational & r1, Rational & r2)
//{
//	//Rational temp;
//	//temp.setnum(((r1.getnum()) * (r2.getdenum())) + ((r2.getnum()) * (r1.getdenum())));
//	//temp.setdenum((r1.getdenum()) * (r2.getdenum()));
//	int d = r1.getdenum() * r2.getdenum();
//	int n = r1.getnum() * r2.getdenum() + r1.getdenum() * r2.getnum();
//	Rational temp.set(n, d);
//	return temp;
//}



