#include <avion.h>
#include <string>
class AvionMarfa : public Avion
{
public:
    AvionMarfa(Corp *corp, Motoare *motoare, Aripi *aripi, std::string culoare);
    std::string getCuloare();

private:
    std::string culoare;
};