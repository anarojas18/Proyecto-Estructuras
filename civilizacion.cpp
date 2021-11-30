#include "civilizacion.h"
#include <fstream>
#include <algorithm>

Civilizacion::Civilizacion()
{

}

Civilizacion::Civilizacion(const string &nombre, int ubicacion_x, int ubicacion_y, int puntuacion)
{
    this->nombre = nombre;
    this->ubicacion_x = ubicacion_x;
    this->ubicacion_y = ubicacion_y;
    this->puntuacion = puntuacion;
}

void Civilizacion::setnombre(const string &v)
{
    nombre = v;
}
string Civilizacion::getnombre()
{
    return nombre;
}

void Civilizacion::setubicacion_x(int v)
{
    ubicacion_x = v;
}
int Civilizacion::getubicacion_x()
{
    return ubicacion_x;
}

void Civilizacion::setubicacion_y(int v)
{
    ubicacion_y = v;
}
int Civilizacion::getubicacion_y()
{
    return ubicacion_y;
}

void Civilizacion::setpuntuacion(int v)
{
    puntuacion = v;
}
int Civilizacion::getpuntuacion()
{
    return puntuacion;
}

//Aldeano
void Civilizacion::agregarfinal(const Aldeano &a)
{
    aldeano.push_back(a);
}

void Civilizacion::agregarinicio(const Aldeano &a)
{
    aldeano.push_front(a);
}

void Civilizacion::print()
{
    cout << left;
    cout << setw(10) << "Nombre: ";
    cout << setw(5) << "Edad: ";
    cout << setw(10) << "Genero: ";
    cout << setw(5) << "Salud: " << endl;

    for (auto it = aldeano.begin(); it != aldeano.end(); it++)
    {
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombrea(const string &nombrea)
{
    for (auto it = aldeano.begin(); it != aldeano.end(); it++)
    {
        Aldeano &a = *it;

        if(nombrea == a.getNombrea())
        {
            aldeano.erase(it);
            break;
        }
    }
}
bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}
void Civilizacion::eliminaredad()
{
    aldeano.remove_if(comparador);
}
void Civilizacion::eliminarsalud(size_t salud)
{
    //pedir x cantidad 
    aldeano.remove_if([salud](const Aldeano &a){return a.getSalud()>=salud;}); 
}
void Civilizacion::ordenarNombrea()
{
    aldeano.sort();
}
bool comparadorEdad(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getEdad() > a2.getEdad();
}
void Civilizacion::ordenarEdad()
{
    aldeano.sort(comparadorEdad);
}

void Civilizacion::ordenarSalud()
{
    aldeano.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud()>a2.getSalud();});
}

/*void Civilizacion::mostrara(const Aldeano &a)
{
    //dejas vacio: mostrara ()
    cout << left;
    cout << setw(10) << "Nombre: ";
    cout << setw(5) << "Edad: ";
    cout << setw(10) << "Genero: ";
    cout << setw(5) << "Salud: " << endl;

    for (auto it = aldeano.begin(); it != aldeano.end(); it++)
    {
        cout << *it << endl;
    }
}*/

/*Aldeano* Civilizacion::buscarA(const Aldeano &a)
{
    auto it = find(aldeano.begin(), aldeano.end(), a);
    if (it == aldeano.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}*/


/*void Civilizacion::respaldar()
{
    ofstream archivo(getNombrea()+ "txt", ios::out);

    for (auto it = aldeano.begin(); it != aldeano.end(); it++)
    {
        Aldeano &aldeano = *it;
        archivo << aldeano.getNombrea() << endl;
        archivo << aldeano.getEdad() << endl;
        archivo << aldeano.getGenero() << endl;
        archivo << aldeano.getSalud() << endl;
    }
    archivo.close();
}
void Civilizacion::recuperar()
{
    ifstream archivo(getNombrea()+ "txt",ios::out);
    //if (archivo.is_open()) checar video vector<personaje>
    string temp;
    int edad;
    int salud;
    Aldeano aldeano;

    while (true);
    {
        getline(archivo, temp);
        if(archivo.eof())
        {
            //break;

        }
        aldeano.setNombrea(temp);

        getline(archivo, temp);
        edad = stoi(temp);
        aldeano.setEdad(edad);

        getline(archivo,temp);
        aldeano.setGenero(temp);

        getline(archivo, temp);
        salud =stoi(temp);
        aldeano.setSalud(salud);

        agregarinicio(aldeano);
    }
    archivo.close();
}*/