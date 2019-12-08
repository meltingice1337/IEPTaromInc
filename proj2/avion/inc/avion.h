#include <aripi.h>
#include <motoare.h>
#include <corp.h>

#ifndef Avion_H
#define Avion_H

class Avion
{
public:
    Avion(Corp *corp, Motoare *motoare, Aripi *aripi);
    virtual int getId();
    virtual int getNrKm();
    virtual bool eFunctional();
    virtual void setDisponibilitate(bool disponibilitate);
    virtual bool getDisponibilitate();

private:
    Corp *corp;
    Motoare *motoare;
    Aripi *aripi;
    bool disponibilitate;
};
#endif