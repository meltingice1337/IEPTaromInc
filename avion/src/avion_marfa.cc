#include <avion_marfa.h>
#include <iostream>
AvionMarfa::AvionMarfa(Corp *corp, Motoare *motoare, Aripi *aripi, std::string culoare)
    : Avion(corp, motoare, aripi, Marfa)
{
    this->culoare = culoare;
    this->tipAvion = Marfa;
}

std::string AvionMarfa::getCuloare()
{
    return this->culoare;
}