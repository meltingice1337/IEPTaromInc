#include <avion_marfa.h>
#include <iostream>
AvionMarfa::AvionMarfa(Corp *corp, Motoare *motoare, Aripi *aripi, std::string culoare)
    : Avion(corp, motoare, aripi)
{
    this->culoare = culoare;
}

std::string AvionMarfa::getCuloare()
{
    return this->culoare;
}