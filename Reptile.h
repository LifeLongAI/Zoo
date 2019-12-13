#include <string>
#include "Animal.h"

#ifndef REPTILE_H
#define REPTILE_H

using namespace std;

class Reptile: public Animal
{
public:
    Reptile();
    Reptile(Animal);

    void setLegs(bool);
    void setVenomous(bool);

    bool hasLegs();
    bool isVenemous();

    string print();

private:
    bool legs;
    bool venomous;
};

#endif // REPTILE_H
