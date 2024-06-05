#include<iostream>
using namespace std;

class Money
{
private:
	int rupees, paisa;
public:
	Money() : rupees(0), paisa(0) {}
	Money(int, int);
	Money(const Money&);
	Money operator+(Money&);
	Money operator-(Money&);
	friend ostream& operator<<(ostream&, const Money&);
	friend istream& operator>>(istream&, Money&);
	//int compare(const Money&
	Money simplify(int, int);

	~Money();


};

Money:: Money( int r, int p)
{

	if (r < 0 && p < 0)
	{
		rupees = -r;
		paisa = -p;
	}
	else if (r<0 && p>0)
	{
		rupees = -r;
		paisa = p;
	}
	else if (p<0 && r>0)
	{
		paisa = -p;
		rupees = r;
	}
	else 
	{
		rupees = r;
		paisa = p;
	}
}

Money::Money(const Money& other) {
	paisa = other.paisa;
	rupees = other.rupees;
}

Money Money:: operator+( Money& other) {
	Money temp;
	temp.paisa = paisa + other.paisa;
	while (temp.paisa >= 100)
	{
		temp.paisa = temp.paisa - 100;
		temp.rupees++;
	}
	temp.rupees = rupees + other.rupees;

	return temp;
}

Money Money:: operator-(Money& other) {
	Money temp;
	if (other.rupees < 0 )
	{
		cout << "The Account Balance is zero " << endl;
		exit(0);
	}
	else if (other.rupees > rupees)
	{
		cout << "The transition is greater than balance" << endl;
		exit(0);
	}
	else
	{
		temp.paisa = paisa - other.paisa;
		temp.rupees = rupees - other.rupees;
		
		return temp;
	}
}

Money::~Money()
{
}

Money Money::simplify(int r, int p) {
	while (p>=100)
	{
		p = p - 100;
		r++;
	}
	return Money(r, p);
}

ostream& operator<<(ostream& COUT, const Money& other) {
	COUT << other.rupees << "." << other.paisa;
	return COUT;
}

istream& operator>>(istream& IN,Money& other) {
	cout << "Enter pasia: " << endl;
	IN >> other.paisa;
	cout << "Enter Rupees: " << endl;
	IN >> other.rupees;

	return IN;
}


int main() {

	Money m1(-12, 15), m2(1, 200), result;

	result = m1 + m2;

	cout << "The Sum is: " << result << endl;

	//result = m1 + m2;
	//
	//cout << "The diff is: " << result << endl;
	
	
	
	return 0;
}