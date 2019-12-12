#include <iostream>
#include <string>
#include <queue>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
	int choice;
	string line;
	queue<string> Sched;
	ifstream file;
	file.open("Schedule.txt");
	while (!file.eof()){
		getline(file,line);
		Sched.push(line);
	}
	string name;
	string txtname;
	if (mainMenu() == 1){
		cout <<"Enter Animal Name: ";
		cin >>name;
		txtname = name + ".txt";
		
	}
	else if (mainMenu()0 == 2){
		cout <<"Enter 1 for Reptile or 2 for Avian: ";
		cin >>choice;
		if(choice == 1){
			class Reptile r1;
		}
		else if (choice == 2){
			class Avian a1;
		}
	}
	
	system("PAUSE");
	return 0;
}
