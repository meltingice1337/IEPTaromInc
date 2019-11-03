#include <componenta.h>
#ifndef Motoare_H
#define Motoare_H
class Motoare : public Componenta
{
public:
    Motoare(int nr_km);
    int getNrKm();

private:
    int nr_km;
};
#endif