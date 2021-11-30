#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class Videogame
{
    string nombre_usuario;
    vector<Civilizacion> civilizacion;
 
public:
    Videogame();
    void agregarCivilizacion(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    void inicializar(const Civilizacion &c, size_t n);
    void eliminar(const string &nom);
    void ordenarnombre();
    void ordenarub_x();
    void ordenarub_y();
    void ordenarpuntuacion();
    void mostrar();
    void respaldarciv();
    void primero();
    void ultimo();
    void nombre_us();
    Civilizacion* buscar(const Civilizacion &c);

    void mostrarA();

    friend Videogame& operator<<(Videogame &v, const Civilizacion &c)
    {
        v.agregarCivilizacion(c);
        return v;
    }

};

#endif