#include"Movie.h"

int main(){

	string actress[] = { "Ali", "Hassan" };
	Movie movie1, movie2("The Knight", "Animation", 9.0, 2 ,actress), movie3, movie4;
	movie1= movie2;
	cin >> movie3;
	system("cls");
	cout << movie2 << endl << movie4 << endl << movie3 << endl << movie1;

	return 0;
}