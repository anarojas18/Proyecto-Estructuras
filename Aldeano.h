#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano
{

    public:
    Aldeano(){}
    Aldeano(const string &nombrea, size_t edad, const string &genero, size_t salud)
    : nombrea(nombrea), edad(edad), genero(genero), salud(salud){}
    
    void setNombrea(const string &nombrea);
    string getNombrea() const;

    void setEdad(size_t edad);
    size_t getEdad() const;

    void setGenero(const string &genero);
    string getGenero();

    void setSalud(size_t salud);
    size_t getSalud() const;

    friend ostream& operator<<(ostream &out, const Aldeano &a)
    {
       out << left;
       out << setw(10) << a.nombrea;
       out << setw(5) << a.edad;
       out << setw(10) << a.genero;
       out << setw(5) << a.salud;

       return out;
    }

    friend istream& operator>>(istream &in, Aldeano &a)
    {
        cout << "Nombre: ";
        getline(cin, a.nombrea);

        cout << "Edad: ";
        cin >> a.edad;

        cout << "Genero: ";
        getline(cin, a.genero);

        cout <<"Salud: ";
        cin >> a.salud;

        return in;
    }

    bool operator<(const Aldeano &a) const
    {
        return nombrea < a.getNombrea();
    }

    /*bool operator<(const Aldeano &a) 
    {
        return nombrea < a.getNombrea();
    }

    bool operator==(const Aldeano &a)const 
    {
        return nombrea == a.nombrea;
    }

    bool operator==(const Aldeano &a) 
    {
        return nombrea == a.nombrea;
    }*/
    
    private:
    string nombrea;
    size_t edad;
    string genero;
    size_t salud;
};
#endif


