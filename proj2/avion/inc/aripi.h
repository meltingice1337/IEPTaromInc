#include "componenta.h"
#ifndef Aripi_H
#define Aripi_H
class Aripi : public Componenta
{
public:
    Aripi(bool poateZbura);
    bool zboara();

private:
    bool poateZbura;
};
#endif