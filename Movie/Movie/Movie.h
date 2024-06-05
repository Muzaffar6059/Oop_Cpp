#pragma once
#include<iostream>
#include<string>
using namespace std;


class Movie
{
private:
	string name;
	string genre;
	float rating;
	int actressCounter;
	string* actress;
	
public:
	Movie();
	~Movie();
	Movie(const string&, const string&, float, int, const string*);
	Movie(const Movie&);
	Movie& operator=(const Movie&);
	friend ostream& operator<<(ostream&, const Movie&);
	friend istream& operator>>(istream& CIN, Movie& others);

};

