#include <iostream>
#include <string>

using namespace std;

int mainMenu(){
	int choice;
	cout <<"      Main Menu:     \n"
		 <<"=====================\n"
		 <<"1. Animal Information\n"
		 <<"2. Add An Animal     \n"
		 <<"3. Feeding Schedule  \n";
	cin >>choice;
	return choice;
}

int main(int argc, char** argv) {
	string name;
	string txtname;
	if (mainMenu() == 1){
		cout <<"Enter in Animal Name";
		cin >>name;
		txtname = name + ".txt";
		
	}
	return 0;
}
