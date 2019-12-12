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
	do{
	if (mainMenu() == 1){
		cout <<"Enter Animal Name: ";
		cin >>name;
		txtname = name + ".txt";
		
	}
	else if (mainMenu() == 2){
		cout <<"Enter 1 for Reptile or 2 for Avian: ";
		cin >>choice;
		if(choice == 1){
			class Reptile r1;
		}
		else if (choice == 2){
			class Avian a1;
		}
	}
	else if (mainMenu() == 3){
		char answer;
		do{
		cout <<Sched.front()
			 <<"\n Was this Animal fed? Y/N: ";
		cin >>answer;
		do{ 
			Sched.front();
		}while (answer != 'N');
		Sched.pop();
	}while (!Sched.empty())
	else if (mainMenu() == 4){
		cout <<"Have a good day.";
	}
	}while (mainMenu() != 4);	
	system("PAUSE");
	return 0;
}
