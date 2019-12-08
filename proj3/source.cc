#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

class Punct
{
public:
    int x, y;
    Punct(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

template <typename T>
T calculeazaDistanta(Punct *p1, Punct *p2)
{
    return sqrt(pow(p2->y - p1->y, 2) + pow(p2->x - p1->x, 2));
}

class Figura
{
public:
    int laturi;
    vector<Punct *> puncte;
    Figura(vector<Punct *> puncte, int laturi)
    {
        this->laturi = laturi;
        this->puncte = puncte;
    }
    double calcPerimetru()
    {
        double total = 0;
        for (size_t i = 1; i < puncte.size(); i++)
        {
            total += calculeazaDistanta<double>(puncte[i - 1], puncte[i]);
        }
        total += calculeazaDistanta<double>(puncte[puncte.size() - 1], puncte[0]);
        return total;
    }

    string toString()
    {
        stringstream ss;
        ss << "Punctele: ";
        for (Punct *p : puncte)
        {
            ss << "(" << p->x << ", " << p->y << ") ";
        }
        ss << "Perimetru = " << calcPerimetru();
        return ss.str();
    }
};

template <typename T>
T calculeazaPanta(Figura *f)
{
    Punct *p1 = f->puncte[0];
    Punct *p2 = f->puncte[0];
    return (p2->y - p1->y) / (p2->x - p1->x);
}

class Patrat : public Figura
{
public:
    Patrat(vector<Punct *> puncte) : Figura(puncte, 4)
    {
    }
};

class Triunghi : public Figura
{
public:
    Triunghi(vector<Punct *> puncte) : Figura(puncte, 3)
    {
    }
};

class Dreptunghi : public Figura
{
public:
    Dreptunghi(vector<Punct *> puncte) : Figura(puncte, 4)
    {
    }
};

class Cerc
{
public:
    Punct *origine;
    int raza;
    bool existaPeCerc(Figura *f)
    {
        for (Punct *p : f->puncte)
        {
            const bool isOnCircle = calculeazaDistanta<int>(p, origine) <= pow(raza, 2);
            if (!isOnCircle)
                return false;
        }
        return true;
    }
    static Cerc *inst;
    static Cerc *create(Punct *origine, int raza)
    {
        if (!Cerc::inst)
        {
            Cerc::inst = new Cerc(origine, raza);
            return Cerc::inst;
        }

        throw "Cannot have more than one circle";
    }

protected:
    Cerc(Punct *origine, int raza)
    {
        this->origine = origine;
        this->raza = raza;
    }
};

Cerc *Cerc::inst = 0;

int main()
{
    int choice = 0;

    vector<Punct *> puncte = {
        new Punct(0, 0),
        new Punct(0, 1),
        new Punct(1, 1),
        new Punct(1, 0),
        new Punct(4, 5),
        new Punct(2, 4),
    };
    vector<Figura *> figuri = {
        new Patrat({puncte[0], puncte[1], puncte[2], puncte[3]}),
    };
    do
    {
        cout << "\n1 - Adauga punct" << endl;
        cout << "2 - Modifica punct" << endl;
        cout << "3 - Adaugarea figura geometrica" << endl;
        cout << "4 - Panta dreapta" << endl;
        cout << "5 - Creare cerc" << endl;
        cout << "6 - Figura pe cerc" << endl;
        cout << "0 - Iesire" << endl;
        cin >> choice;
        if (choice == 0)
        {
            return 0;
        }
        else if (choice == 1)
        {
            int x, y;
            cout << "X = ";
            cin >> x;
            cout << "Y = ";
            cin >> y;
            puncte.push_back(new Punct(x, y));
        }
        else if (choice == 2)
        {
            cout << "Alege punctul pe care il modifici: \n";
            for (size_t i = 0; i < puncte.size(); i++)
            {
                printf("%d - (%d, %d)\n", i, puncte[i]->x, puncte[i]->y);
            }
            int nrPunct = 0;
            cin >> nrPunct;
            cout << "nou X = ";
            int x, y;
            cin >> x;
            cout << "nou Y = ";
            cin >> y;
            puncte[nrPunct]->x = x;
            puncte[nrPunct]->y = y;
        }
        else if (choice == 3)
        {
            cout << "1 - Patrat" << endl;
            cout << "2 - Triunghi" << endl;
            cout << "3 - Patrat" << endl;
            int tip = 0;
            cin >> tip;
            if (tip < 1 || tip > 3)
                continue;

            cout << "Puncte disponibile:" << endl;
            for (size_t i = 0; i < puncte.size(); i++)
            {
                printf("%d - (%d, %d)\n", i, puncte[i]->x, puncte[i]->y);
            }
            int nrPuncte = tip == 2 ? 3 : 4;
            printf("Alege %d puncte\n\n", nrPuncte);
            vector<Punct *> puncteFigura;
            for (int i = 0; i < nrPuncte; i++)
            {
                int nrPunct;
                printf("Punctul %d: ", i + 1);
                cin >> nrPunct;
                puncteFigura.push_back(puncte[i]);
            }
            if (tip == 1)
                figuri.push_back(new Patrat(puncteFigura));
            else if (tip == 2)
                figuri.push_back(new Triunghi(puncteFigura));
            else if (tip == 3)
                figuri.push_back(new Dreptunghi(puncteFigura));
        }
        else if (choice == 4)
        {
            printf("Selecteaza figura la care sa calculezi panta: \n");
            for (size_t i = 0; i < figuri.size(); i++)
            {
                printf("Figura %d - %s \n", i, figuri[i]->toString().c_str());
            }
            int figura;
            printf("Alege figura: ");
            cin >> figura;
            cout << "Panta: " << calculeazaPanta<double>(figuri[figura]);
        }
        else if (choice == 5)
        {
            cout << "Alege punctul de origine al cercului: \n";
            for (size_t i = 0; i < puncte.size(); i++)
            {
                printf("%d - (%d, %d)\n", i, puncte[i]->x, puncte[i]->y);
            }
            int nrPunct, raza;
            cin >> nrPunct;
            printf("Raza cercului = ");
            cin >> raza;
            try
            {
                Cerc::create(puncte[nrPunct], raza);
            }
            catch (const char *msg)
            {
                printf("Nu s-a putut crea cercul deoarece: < %s >", msg);
            }
        }
        else if (choice == 6)
        {
            if (!Cerc::inst)
            {
                printf("! Creaza intai un cerc !");
                continue;
            }
            printf("Selecteaza figura care vrei sa o verifici ca este pe cerc: \n");
            for (size_t i = 0; i < figuri.size(); i++)
            {
                printf("Figura %d\n - %s", i, figuri[i]->toString().c_str());
            }
            printf("Alege figura: ");
            int figura;
            cin >> figura;
            printf("Figura %d %s este pe cerc", figura, Cerc::inst->existaPeCerc(figuri[figura]) ? "" : "NU");
        }
    } while (choice >= 1 && choice <= 6);
    return 0;
}
