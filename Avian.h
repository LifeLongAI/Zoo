#include <string>
#include "Animal.h"

#ifndef AVIAN_H
#define AVIAN_H

using namespace std;

class Avian :public Animal{
public:
    Avian();
    Avian(Animal);

    void setWingspan(float);
    void setBeakLength(float);

    float getWingspan();
    float getBeakLength();

    string print();

private:

    float wingspan;
    float beakLength;
};

#endif // AVIAN_H
