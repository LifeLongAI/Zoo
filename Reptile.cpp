#include "Reptile.h"

Reptile::Reptile(){}

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
