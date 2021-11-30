#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "Aldeano.h"
#include <list>


#include <iostream>
#include <iomanip>

using namespace std;

class Civilizacion
{
    string nombre;
    int ubicacion_x;
    int ubicacion_y;
    int puntuacion;

public:
    Civilizacion(); 
    Civilizacion(const string &nombre, int ubicacion_x, int ubicacion_y,int puntuacion);
    void setnombre(const string &v);
    string getnombre();
    void setubicacion_x(int v);
    int getubicacion_x();
    void setubicacion_y(int v);
    int getubicacion_y();
    void setpuntuacion(int v);
    int getpuntuacion();

    void setNombrea(const string &nombrea);
    string getNombrea();

    void agregarfinal(const Aldeano &a);
    void agregarinicio(const Aldeano &a);
    void print();

    void eliminarNombrea(const string &nombrea);
    void eliminarsalud(size_t salud);
    void eliminaredad();

    void ordenarNombrea();
    void ordenarEdad();
    void ordenarSalud();

    //void mostrara(const Aldeano &a);
    //void mostrarA();
    //Aldeano* buscarA(const Aldeano &a);

    //void respaldar();
    //void recuperar();


    friend ostream& operator<<(ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(10) << c.nombre;
        out << setw(12) << c.ubicacion_x;
        out << setw(12) << c.ubicacion_y;
        out << setw(12) << c.puntuacion;
        out << endl;
        return out;
    }

    friend istream& operator>>(istream &in, Civilizacion &c)
    {
        cout << "Nombre: ";
        getline(cin, c.nombre);

        cout << "Ubicacion X: ";
        cin >> c.ubicacion_x;

        cout << "Ubicacion Y: ";
        cin >> c.ubicacion_y;

        cout << "Puntuacion: ";
        cin >> c.puntuacion;

        return in;
    }

    bool operator==(const Civilizacion& c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion& c) const
    {
        return nombre == c.nombre;
    }
    bool operator<(const Civilizacion& c)
    {
        return nombre < c.nombre;
    }
    bool operator<(const Civilizacion& c) const
    {
        return nombre < c.nombre;
    }

   private:
   list<Aldeano> aldeano;

};

#endif