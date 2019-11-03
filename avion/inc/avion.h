#include <aripi.h>
#include <motoare.h>
#include <corp.h>

#ifndef Avion_H
#define Avion_H

enum TipAvion
{
    Pasageri = 0,
    Marfa = 1
};

class Avion
{
public:
    Avion(Corp *corp, Motoare *motoare, Aripi *aripi, TipAvion tipAvion);
    int getId();
    virtual int getNrKm();
    virtual bool eFunctional();
    TipAvion tipAvion;

private:
    Corp *corp;
    Motoare *motoare;
    Aripi *aripi;
};
#endif