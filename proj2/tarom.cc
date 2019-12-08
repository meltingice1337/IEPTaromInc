#include <componenta.h>
#include <avion.h>
#include <avion_pasageri.h>
#include <avion_marfa.h>
#include <aripi.h>
#include <corp.h>
#include <motoare.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    list<Componenta *> componente = {new Corp(24),
                                     new Corp(45),
                                     new Motoare(123500),
                                     new Aripi(true),
                                     new Aripi(false),
                                     new Motoare(123500)};
    list<Avion *> avioane;

    int choice;
    do
    {

        cout << "\n---------------\n1->Afisare componenta disponibile\n2->Creare avion\n3->Vizualizare avioane\n---------------\n\nAlegere: ";
        cin >> choice;
        if (choice < 0 || choice > 3)
            continue;
        if (choice == 1)
        {
            list<Componenta *>::iterator it;
            int componentaCount[3] = {0, 0, 0};
            printf("\nComponente disponibile: \n");
            for (it = componente.begin(); it != componente.end(); ++it)
            {
                Corp *corpCast = dynamic_cast<Corp *>(*it);
                Aripi *aripiCast = dynamic_cast<Aripi *>(*it);
                Motoare *motoareCast = dynamic_cast<Motoare *>(*it);
                if (corpCast)
                {
                    printf("<Corp, id: %d>\n", corpCast->getId());
                    componentaCount[0]++;
                }
                else if (aripiCast)
                {
                    printf("<Aripi, poate zbura: %s>\n", aripiCast->zboara() ? "DA" : "NU");
                    componentaCount[1]++;
                }
                else if (motoareCast)
                {
                    printf("<Motoare, km: %d>\n", motoareCast->getNrKm());
                    componentaCount[2]++;
                }
            }
            printf("In total sunt pe stoc %d componenta din care: \n", componente.size());
            printf("%d corpuri\n", componentaCount[0]);
            printf("%d seturi aripi\n", componentaCount[1]);
            printf("%d seturi motoare\n", componentaCount[2]);
        }
        else if (choice == 2)
        {
            int tipAvion, corpOption;
            Corp *corp;
            Motoare *motoare;
            Aripi *aripi;
            cout << "Selecteaza tip-ul avionului (1-pasageri, 2-marfa): ";
            cin >> tipAvion;
            list<Componenta *>::iterator it;
            vector<list<Componenta *>::iterator> options;
            // Corp
            printf("Selecteaza un corp pentru avion: \n");
            for (it = componente.begin(); it != componente.end(); ++it)
            {
                Corp *corpCast = dynamic_cast<Corp *>(*it);
                if (corpCast)
                {
                    options.push_back(it);
                    printf("%d. <Corp, id: %d>\n", options.size(), corpCast->getId());
                }
            }
            printf("\nOptiune: ");
            cin >> corpOption;
            corp = dynamic_cast<Corp *>(*(options[corpOption - 1]));
            componente.erase(options[corpOption - 1]);
            // Aripi
            options.clear();
            printf("Selecteaza aripi pentru avion: \n");
            for (it = componente.begin(); it != componente.end(); ++it)
            {
                Aripi *aripiCast = dynamic_cast<Aripi *>(*it);
                if (aripiCast)
                {
                    options.push_back(it);
                    printf("%d. <Aripi, id: %s>\n", options.size(), aripiCast->zboara() ? "DA" : "NU");
                }
            }
            printf("\nOptiune: ");
            cin >> corpOption;
            aripi = dynamic_cast<Aripi *>(*(options[corpOption - 1]));
            componente.erase(options[corpOption - 1]);
            // Motoare
            options.clear();
            printf("Selecteaza motoare pentru avion: \n");
            for (it = componente.begin(); it != componente.end(); ++it)
            {
                Motoare *motoareCast = dynamic_cast<Motoare *>(*it);
                if (motoareCast)
                {
                    options.push_back(it);
                    printf("%d. <Motoare, KM: %d>\n", options.size(), motoareCast->getNrKm());
                }
            }
            printf("\nOptiune: ");
            cin >> corpOption;
            motoare = dynamic_cast<Motoare *>(*(options[corpOption - 1]));
            componente.erase(options[corpOption - 1]);

            if (tipAvion == 1)
            {
                int nrPasageri;
                cout << "Numar pasageri: ";
                cin >> nrPasageri;
                avioane.push_back(new AvionPasageri(corp, motoare, aripi, nrPasageri));
            }
            else
            {
                string culoare;
                cout << "Culoare: ";
                cin >> culoare;
                avioane.push_back(new AvionMarfa(corp, motoare, aripi, culoare));
            }
        }
        else if (choice == 3)
        {
            list<Avion *>::iterator it;
            for (it = avioane.begin(); it != avioane.end(); ++it)
            {
                Avion *a = *it;
                AvionPasageri *aa = dynamic_cast<AvionPasageri *>(a);
                int tipAvion = 0;
                if (!aa)
                    tipAvion = 1;

                printf("Avion de %s, id: %d, Nr KM: %d, disponibilitate: %s", tipAvion == 0 ? "Pasageri" : "Marfa", a->getId(), a->getNrKm(), a->eFunctional() ? "Da" : "Nu");
                if (tipAvion == 0)
                {
                    AvionPasageri *aa = dynamic_cast<AvionPasageri *>(a);
                    cout << ", nr pasageri: " << aa->getNrPasageri();
                }
                else if (tipAvion == 1)
                {
                    AvionMarfa *aa = dynamic_cast<AvionMarfa *>(a);
                    cout << ", culoare: " << aa->getCuloare();
                }
                cout << endl;
            }
        }
    } while (choice != 0);
}