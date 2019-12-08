#include "aripi.h"

Aripi::Aripi(bool poateZbura)
{
    this->poateZbura = poateZbura;
}

bool Aripi::zboara()
{
    return this->poateZbura;
}