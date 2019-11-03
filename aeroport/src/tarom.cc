#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <avion.h>
#include <avion_marfa.h>
#include <avion_pasageri.h>

using namespace std;

int main()
{
    list<Avion *> avioane;
    avioane.push_back(new AvionMarfa(new Corp(23), new Motoare(4444), new Aripi(true), "osu"));
    int choice;
    do
    {
        cout << "\n---------------\n1->vizualizare avioane\n 2->adaugare avion marfa\n 3->adaugare avion pasageri\n 4->stergere avion, dupa id\n 5->disponibilitate avion\n 6->indisponibilizare avion\n 0->iesire\n\nAlegere: ";
        cin >> choice;
        if (choice < 0 || choice > 6)
            continue;
        if (choice == 1)
        {
            list<Avion *>::iterator it;
            for (it = avioane.begin(); it != avioane.end(); ++it)
            {
                Avion *a = *it;
                printf("Avion de %s, id: %d, nrKm: %d, disponibilitate: %s", a->tipAvion == Pasageri ? "Pasageri" : "Marfa", a->getId(), a->getNrKm(), a->eFunctional() ? "Da" : "Nu");
                if (a->tipAvion == Pasageri)
                {
                    AvionPasageri *aa = dynamic_cast<AvionPasageri *>(a);
                    cout << ", nr pasageri: " << aa->getNrPasageri();
                }
                else if (a->tipAvion == Marfa)
                {
                    AvionMarfa *aa = dynamic_cast<AvionMarfa *>(a);
                    cout << ", culoare: " << aa->getCuloare();
                }
                cout << endl;
            }
        }
        else if (choice == 2)
        {
            int nr_km, id, zboara;
            string culoare;
            cout << "Id: ";
            cin >> id;
            cout << "nr_km: ";
            cin >> nr_km;
            cout << "zboara(0/1): ";
            cin >> zboara;
            cout << "culoare: ";
            cin >> culoare;
            avioane.push_back(new AvionMarfa(new Corp(id), new Motoare(nr_km), new Aripi(zboara), culoare));
        }
        else if (choice == 3)
        {
            int nr_km, id, zboara, nr_pasageri;
            cout << "Id: ";
            cin >> id;
            cout << "nr_km: ";
            cin >> nr_km;
            cout << "zboara(0/1): ";
            cin >> zboara;
            cout << "nr_pasageri: ";
            cin >> nr_pasageri;
            avioane.push_back(new AvionPasageri(new Corp(id), new Motoare(nr_km), new Aripi(zboara), nr_pasageri));
        }
        else if (choice == 4)
        {
            int id;
            list<Avion *>::iterator it;
            cout << "Sterge avion cu id: ";
            cin >> id;
            bool found = false;
            for (it = avioane.begin(); it != avioane.end(); ++it)
            {
                if ((*it)->getId() == id)
                {
                    it = avioane.erase(it);
                    found = true;
                    break;
                }
            }
            if (found)
                cout << "-->Am sters avionul cu id-ul " << id << endl;
            else
                cout << "-->Nu am gasit avionul cu id-ul " << id << endl;
        }
    } while (choice != 0);
}