#include "Aldeano.h"

void Aldeano::setNombrea(const string &nombrea)
{
    this->nombrea = nombrea;
}
string Aldeano::getNombrea() const
{
    return nombrea;
}

void Aldeano::setEdad(size_t edad)
{
    this->edad = edad;
}
size_t Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setGenero(const string &genero)
{
    this->genero = genero;
}
string Aldeano::getGenero()
{
    return genero;
}

void Aldeano::setSalud(size_t salud)
{
    this->salud = salud;
}
size_t Aldeano::getSalud() const
{
    return salud;
}