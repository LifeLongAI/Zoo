#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "Animal.h"
#include "Avian.h"
#include "Reptile.h"
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
	int choice, entry;
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
	do{
	entry = mainMenu();
	if (entry == 1){
		cout <<"Enter Animal Name: ";
		cin >>name;
		txtname = name + ".txt";
		
	}
	else if (entry == 2){
		cout <<"Enter 1 for Reptile or 2 for Avian: ";
		cin >>choice;
		if(choice == 1){
			class Reptile r1;
		}
		else if (choice == 2){
			class Avian a1;
		}
	}
	else if (entry == 3){
		char answer;
		if (!Sched.empty()){
			for (int i = 0; i <= Sched.size();i++){
			cout <<Sched.front()
				 <<"\nWas this Animal fed? Y/N: ";
			cin >>answer;
			answer = toupper(answer);
		if (answer == 'Y'){
			Sched.pop();
		}
		else if (answer == 'N'){
			cout <<"Go feed "<<Sched.front()<<" Now. \n";
		}
		}
		}
	}	
	else if (entry == 4){
		cout <<"Have a good day.";
		break;
	}
	}while (entry != 4);
	system("PAUSE");
	return 0;

}
