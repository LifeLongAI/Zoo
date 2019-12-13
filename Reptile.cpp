#include "Reptile.h"

Reptile::Reptile():Animal()
{
    legs = false;
    venomous = false;
}

Reptile::Reptile(Animal fred)
{
    setFood(fred.getFood());
    setName(fred.getName());
    setWeight(fred.getWeight());
    setSex(fred.getSex());
}

bool Reptile::hasLegs()
{
    return legs;
}

bool Reptile::isVenemous()
{
    return venomous;
}

void Reptile::setLegs(bool strut)
{
    legs = strut;
}

void Reptile::setVenomous(bool notPoisonous)
{
    venomous = notPoisonous;
}

string Reptile::print()
{
    string ret = "";
    ret += "Reptile\n";
    ret += Animal::print() + "\n";
    ret += to_string(legs) + "\n";
    ret += to_string(venomous);

    return ret;
}
