#include "rational.h"
Rational::Rational() :num(1), denum(2)
{
	simplify();
}
Rational::Rational(int n) :num(n), denum(4)
{
	simplify();
}
Rational::Rational(int n, int d) :num(n), denum(d)
{
	simplify();
}
Rational::Rational(const Rational& r) :num(r.num), denum(r.denum)
{
}
void Rational::setnum(int n)
{
	num = n;
	simplify();
}
void Rational::setdenum(int d)
{
	simplify();
	denum = d;
}
void Rational::set(int n, int d)
{
	num = n;
	denum = d;
	simplify();
}
int Rational::getnum()const
{
	return num;
}
int Rational::getdenum()const
{
	return denum;
}
void Rational::simplify()
{
	if (denum < 0)
	{
		denum = -denum;
		num = -num;
	}
	int n = num < 0 ? -num : num;
	int d = denum;
	int r = n % d;
	while (r != 0)
	{
		n = d;
		d = r;
		r = n % d;
	}
	num /= d;
	denum /= d;


}
Rational Rational:: operator+(const Rational& other) {
	int n = num * other.denum + other.num * denum;
	int d = denum * other.denum;
	Rational result(n, d);
	result.simplify();
	return result;
}
