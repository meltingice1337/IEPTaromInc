#include <motoare.h>

Motoare::Motoare(int nr_km)
{
    this->nr_km = nr_km;
}

int Motoare::getNrKm()
{
    return this->nr_km;
}