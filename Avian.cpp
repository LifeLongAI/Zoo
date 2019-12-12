#include "Avian.h"

Avian::Avian(){}

float Avian::getBeakLength()
{
    return beakLength;
}

float Avian::getWingspan()
{
    return wingspan;
}

void Avian::setBeakLength(float bokbok)
{
    beakLength = bokbok;
}

void Avian::setWingspan(float bigArms)
{
    wingspan = bigArms;
}

string Avian::print(){
    string ret = "";
    ret += "Avian\n";
    ret += Animal::print() + "\n";
    ret += to_string(beakLength) + "\n";
    ret += to_string(wingspan);

    return ret;
}
