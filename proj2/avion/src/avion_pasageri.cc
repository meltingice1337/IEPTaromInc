#include <avion_pasageri.h>

AvionPasageri::AvionPasageri(Corp *corp, Motoare *motoare, Aripi *aripi, int nrPasageri)
    : Avion(corp, motoare, aripi)
{
    this->nrPasageri = nrPasageri;
}

int AvionPasageri::getNrPasageri()
{
    return this->nrPasageri;
}