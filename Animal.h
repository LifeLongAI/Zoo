#include <string>

#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;

class Animal
{
public:
    Animal();

    void setFood(string);
    void setSex(char);
    void setWeight(float);
    void setName(string);

    string getFood();
    char getSex();
    float getWeight();
    string getName();

    virtual string print();

private:
    string food;
    char sex;
    float weight;
    string name;

};

#endif // ANIMAL_H
