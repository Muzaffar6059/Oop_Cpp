#include "Movie.h"

Movie::Movie() : name(""), genre(""), rating(0.0), actressCounter(0), actress(nullptr) {}

Movie::Movie(const string& name,const string& genre, float rating, int numberOfActress, const string* actress) 
	:name(name),genre(genre), rating(rating), actressCounter(numberOfActress){

	this->actress = new string[actressCounter];
	for (int i = 0; i < actressCounter; i++)
	{
		this->actress[i] = actress[i];
	}
}

Movie::Movie(const Movie& other) {
	name = other.name;
	genre = other.genre;
	rating = other.rating;
	actressCounter = other.actressCounter;
	actress = new string[actressCounter];
	for (int i = 0; i < actressCounter; i++)
	{
		actress[i] = other.actress[i];
	}
	 
}

Movie::~Movie() {
	delete[] actress;
	actress = nullptr;
}
Movie& Movie::operator=(const Movie& other) {
	if (&other != this)
	{
		name = other.name;
		genre = other.genre;
		rating = other.rating;
		actressCounter = other.actressCounter;
		delete [] actress;
		 
		actress = new string[actressCounter];
		for (int i = 0; i < actressCounter; i++)
		{
			actress[i] = other.actress[i];
		}
		return *this;
	}
	
}


ostream& operator<<(ostream& COUT, const Movie& other) {
	COUT << "Name: " << other.name << endl;
	COUT << "Genre: " << other.genre << endl;
	COUT << "Rating: " << other.rating << endl;
	COUT << "Actress: \n";
	for (int i = 0; i < other.actressCounter; i++)
	{
		COUT << other.actress[i];
		if (i != other.actressCounter - 1) {
			COUT << ", ";
		}
	}
		COUT << endl;
		return COUT;
};

	istream& operator>>(istream & CIN, Movie & others) {
		cout << "Enter movie name: ";
		getline(CIN, others.name);

		cout << "Enter genre: ";
		getline(CIN, others.genre);

		cout << "Enter rating: ";
		CIN >> others.rating;

		CIN.ignore();

		cout << "Enter number of actresses: ";
		CIN >> others.actressCounter;

		CIN.ignore();

		others.actress = new string[others.actressCounter];

		for (int i = 0; i < others.actressCounter; ++i) {
			std::cout << "Enter actress name " << (i + 1) << ": ";
			std::getline(CIN, others.actress[i]);
		}

		return CIN;
	};
