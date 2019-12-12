#include "Animal.h"

Animal::Animal()
{

}

string Animal::getFood()
{
    return food;
}

string Animal::getName()
{
    return name;
}

char Animal::getSex()
{
    return sex;
}

float Animal::getWeight()
{
    return weight;
}

void Animal::setFood(string reFood)
{
    food = reFood;
}

void Animal::setName(string mahName)
{
    name = mahName;
}

void Animal::setSex(char sexay)
{
    if(sexay == 'm' || sexay == 'f' || sexay == 'M' || sexay == 'F')
    {
        sex = sexay;
    }
}

void Animal::setWeight(float chonker)
{
    weight = chonker;
}

string Animal::print()
{
    string ret = "";
    ret += name + "\n";
    ret += to_string(weight) + "\n";
    ret += sex + "\n";
    ret += food;
    return ret;
}
