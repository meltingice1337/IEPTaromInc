#include <avion_pasageri.h>

AvionPasageri::AvionPasageri(Corp *corp, Motoare *motoare, Aripi *aripi, int nrPasageri)
    : Avion(corp, motoare, aripi, Pasageri)
{
    this->nrPasageri = nrPasageri;
    this->tipAvion = Pasageri;
}

int AvionPasageri::getNrPasageri()
{
    return this->nrPasageri;
}