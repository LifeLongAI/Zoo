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
         <<"3. Feeding Schedule  \n"
         <<"4. Exit Program      \n";
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
    int choice, entry;
    string line;
    queue<string> Sched;
    ifstream file;
    file.open("Schedule.txt");
    while (!file.eof())
    {
        getline(file,line);
        Sched.push(line);
    }
    file.close();
    string name;
    string txtname;
    do
    {
        entry = mainMenu();
        if (entry == 1)
        {
            Animal oldAnim = Animal();
            Animal* animPtr;
            Reptile grommash;
            Avian kite;
            string type;

            cout <<"Enter Animal Name: ";
            cin >>name;
            txtname = name + ".txt";

            ifstream animFile;
            animFile.open(txtname);
            getline(animFile, type);

            getline(animFile, line);
            oldAnim.setName(line);
            getline(animFile, line);
            oldAnim.setWeight(stof(line));
            getline(animFile, line);
            oldAnim.setSex((line.at(0)));
            getline(animFile, line);
            oldAnim.setFood(line);

            if(type == "Reptile")
            {
                grommash = Reptile(oldAnim);
                getline(animFile, line);
                grommash.setLegs(stoi(line)==1);
                getline(animFile, line);
                grommash.setVenomous(stoi(line)==1);

                animPtr = &grommash;
            }
            else if (type == "Avian")
            {
                kite = Avian(oldAnim);
                getline(animFile, line);
                kite.setWingspan(stof(line));
                getline(animFile, line);
                kite.setBeakLength(stof(line));

                animPtr = &kite;
            }

            animFile.close();
            cout<<"You have selected:\n"<<animPtr->print()<<endl<<endl;
            char isHungry;
            cout<<"Is "<<animPtr->getName()<<" hungry? (y/n)\n";
            cin>>isHungry;
            if(isHungry == 'y')
            {
                Sched.push(animPtr->getName());
                cout<<animPtr->getName()<<" added to feeding queue.";

                ofstream sked;
                sked.open("Schedule.txt");
                sked<<animPtr->getName();
                sked.close();
            }

            cout<<"\n\n"<<animPtr->getName()<<" currently weighs "<<animPtr->getWeight()<<" lbs."
            <<endl<<"Would you like to change "<<animPtr->getName()<<"'s weight? (y/n)\n";
            char editWeight;
            cin>>editWeight;
            if(editWeight == 'y')
            {
                cout<<"Enter "<<animPtr->getName()<<"'s new weight\n";
                float newWeight;
                cin>>newWeight;
                animPtr->setWeight(newWeight);

                ofstream overwrite;
                overwrite.open(txtname);
                overwrite<<(animPtr->print());
            }

        }
        else if (entry == 2)
        {
            Animal* newAnim;
            Reptile rexxar;
            Avian borb;
            cout <<"Enter 1 for Reptile or 2 for Avian: ";
            cin >>choice;
            if(choice == 1)
            {
                rexxar = makeRep();
                newAnim = &rexxar;
            }
            else if (choice == 2)
            {
                borb = makeBirb();
                newAnim = &borb;
            }

            ofstream saveFile;
            saveFile.open(newAnim->getName()+".txt");
            cout<<"Saving animal to database\n";
            saveFile<<(newAnim->print());
            saveFile.close();
        }
        else if (entry == 3)
        {
            char answer;
            if (!Sched.empty())
            {
                while(!Sched.empty())
                {
                    cout <<Sched.front()
                         <<"\nWas this Animal fed? Y/N: ";
                    cin >>answer;
                    answer = toupper(answer);
                    if (answer == 'Y')
                    {
                        Sched.pop();

                    }
                    else if (answer == 'N')
                    {
                        cout <<"Go feed "<<Sched.front()<<" Now. \n";
                    }
                }
            }
            ofstream delfile;
            delfile.open("Schedule.txt");
            delfile.clear();
            file.close();
        }
        else if (entry == 4)
        {
            cout <<"Have a good day.";
            break;
        }
    }
    while (entry != 4);
    system("PAUSE");
    return 0;

}
