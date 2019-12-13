#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include "Animal.h"
#include "Avian.h"
#include "Reptile.h"

using namespace std;

int mainMenu()
{
    int choice;
    cout <<"      Main Menu:     \n"
         <<"=====================\n"
         <<"1. Animal Information\n"
         <<"2. Add An Animal     \n"
         <<"3. Feeding Schedule  \n";
    cin >>choice;
    return choice;
}

Animal makeAnimal()
{
    Animal shark = Animal();

    string name;
    cout<<"Enter the animal's name\n";
    getline(cin, name);
    while(name.length()==0)
        getline(cin, name);
    shark.setName(name);

    float weight;
    cout<<"Enter the animal's weight in pounds\n";
    cin>>weight;
    shark.setWeight(weight);

    char sex;
    cout<<"Enter the animal's sex as 'm' or 'f'\n";
    cin>>sex;
    shark.setSex(sex);

    string food;
    cout<<"Enter the animal's preferred food\n";
    getline(cin, food);
    while(food.length()==0)
        getline(cin, food);
    shark.setFood(food);

    return shark;
}

Reptile makeRep()
{
    Reptile lizard = Reptile(makeAnimal());

    char hasLegs;
    cout<<"Does the animal have legs? (y/n)\n";
    cin>>hasLegs;
    lizard.setLegs(hasLegs == 'y');

    char isVenomous;
    cout<<"Is the animal venomous? (y/n)\n";
    cin>>isVenomous;
    lizard.setVenomous(isVenomous == 'y');

    return lizard;
}

Avian makeBirb()
{
    Avian birb = Avian(makeAnimal());

    float longArms;
    cout<<"Enter the animal's wingspan\n";
    cin>>longArms;
    birb.setWingspan(longArms);

    float cockadoodledoo;
    cout<<"Enter the animal's beak length\n";
    cin>>cockadoodledoo;
    birb.setBeakLength(cockadoodledoo);

    return birb;
}

int main(int argc, char** argv)
{
    int choice;
    string line;
    queue<string> Sched;

    ifstream file;
    file.open("Schedule.txt");

    while (!file.eof())
    {
        getline(file,line);
        Sched.push(line);
    }


    string name;
    string txtname;
    do
    {
        if (mainMenu() == 1)
        {
            cout <<"Enter Animal Name: ";
            cin >>name;
            txtname = name + ".txt";

        }
        else if (mainMenu() == 2)
        {
            Animal* newAnim;
            cout <<"Enter 1 for Reptile or 2 for Avian: ";
            cin >>choice;
            if(choice == 1)
            {
                Reptile rexxar = makeRep();
                newAnim = &rexxar;
            }
            else if (choice == 2)
            {
                Avian borb = makeBirb();
                newAnim = &borb;
            }

            ofstream saveFile(newAnim->getName()+".txt");
            saveFile<<newAnim->print();
        }
        else if (mainMenu() == 3)
        {
            char answer;
            do
            {
                cout <<Sched.front()
                     <<"\n Was this Animal fed? Y/N: ";
                cin >>answer;

                do
                {
                    Sched.front();
                }
                while (answer != 'N');

                Sched.pop();
            }
            while (!Sched.empty());
        }
        else if (mainMenu() == 4)
        {
            cout <<"Have a good day.";
        }
    }
    while (mainMenu() != 4);
    system("PAUSE");
    return 0;

}
