#include <avion.h>

Avion::Avion(Corp *corp, Motoare *motoare, Aripi *aripi)
{
    this->corp = corp;
    this->motoare = motoare;
    this->aripi = aripi;
    this->disponibilitate = true;
}

int Avion::getId()
{
    return this->corp->getId();
}

int Avion::getNrKm()
{
    return this->motoare->getNrKm();
}

bool Avion::eFunctional()
{
    return this->corp != nullptr && this->motoare != nullptr && this->aripi != nullptr && this->aripi->zboara() && this->disponibilitate;
}

void Avion::setDisponibilitate(bool disponibilitate)
{
    this->disponibilitate = disponibilitate;
}

bool Avion::getDisponibilitate()
{
    return this->disponibilitate;
}