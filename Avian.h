#include <string>

#ifndef AVIAN_H
#define AVIAN_H

using namespace std;

class Avian: public Animal
{
public:
    Avian();

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
