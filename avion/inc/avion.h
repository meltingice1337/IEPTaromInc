#include <aripi.h>
#include <motoare.h>
#include <corp.h>

#ifndef Avion_H
#define Avion_H

class Avion
{
public:
    Avion(Corp *corp, Motoare *motoare, Aripi *aripi);
    int getId();
    virtual int getNrKm();
    virtual bool eFunctional();

private:
    Corp *corp;
    Motoare *motoare;
    Aripi *aripi;
};
#endif