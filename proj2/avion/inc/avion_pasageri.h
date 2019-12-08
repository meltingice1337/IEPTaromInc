#include <avion.h>
class AvionPasageri : public Avion
{
public:
    AvionPasageri(Corp *corp, Motoare *motoare, Aripi *aripi, int nrPasageri);
    int getNrPasageri();

private:
    int nrPasageri;
};