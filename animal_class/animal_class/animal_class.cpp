#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:
	void setData(string name, int NumOfSpecies);
	void getData() {
		cout << "Animal Name is: " << Name << endl;
		cout << "Current number of Species found:  " << numberOfSpecies << endl;
	}

private:
	string Name;
	int numberOfSpecies=0;
};

void Animal::setData(string name, int NumOfSpecies)
{
	Name = name;
	numberOfSpecies = NumOfSpecies;
}

int main() {

	Animal animal[3];
	animal[0].setData("Tiger", 23);
	animal[1].setData("Browm Bear", 9);
	animal[2].setData("Star Fish", 103);

	for (int i = 0; i < 3; i++)
	{
		cout << "NO " << i + 1 << endl;
		animal[i].getData();
	}

	return 0;
}