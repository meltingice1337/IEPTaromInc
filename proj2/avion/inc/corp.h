#include <componenta.h>
#ifndef Corp_H
#define Corp_H
class Corp : public Componenta
{
public:
    Corp(int id);
    int getId();

private:
    int id;
};
#endif