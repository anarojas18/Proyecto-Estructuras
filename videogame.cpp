#include "videogame.h"
#include <fstream>
#include <algorithm>
#include "menu.h"

Videogame::Videogame()
{

}

void Videogame::agregarCivilizacion(const Civilizacion &c)
{
    civilizacion.push_back(c);
}

void Videogame::insertar(const Civilizacion &c, size_t pos)
{
    civilizacion.insert(civilizacion.begin()+pos, c);
}

size_t Videogame::size()
{
    return civilizacion.size();
}

void Videogame::inicializar(const Civilizacion &c, size_t n)
{
    civilizacion = vector<Civilizacion>(n,c);    
}

void Videogame::primero()
{
    if (civilizacion.empty())
    {
        cout << "No hay civilizacion" << endl;
    }
    else
    {
        cout << civilizacion.front() << endl;
    }
}

void Videogame::ultimo()
{
    if (civilizacion.empty())
    {
        cout << "No hay civilizacion" << endl;
    }
    else
    {
        cout << civilizacion.back() << endl;
    }
}

void Videogame::ordenarnombre()
{
    sort(civilizacion.begin(),civilizacion.end());
}
void Videogame::ordenarub_x()
{
    sort(civilizacion.begin(),civilizacion.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getubicacion_x() < c2.getubicacion_x();});
}
void Videogame::ordenarub_y()
{
    sort(civilizacion.begin(),civilizacion.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getubicacion_y() < c2.getubicacion_y();});
}
void Videogame::ordenarpuntuacion()
{
    sort(civilizacion.begin(),civilizacion.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getpuntuacion() > c2.getpuntuacion();});
}
void Videogame::mostrar()
{
    cout << left;
    cout << setw(10) << "Nombre: ";
    cout << setw(12) << "Ubicacion X";
    cout << setw(12) << "Ubicacion Y";
    cout << setw(12) << "Puntuacion" << endl;

    for (size_t i = 0; i < civilizacion.size(); i++)
    {
        Civilizacion &c = civilizacion[i];
        cout << c;
    }
}
void Videogame::mostrarA()
{
    if(civilizacion.empty())
    {
        cout << "No hay seleccion" << endl;
    }
    else 
    {
        for (size_t i = 0; i < civilizacion.size(); i++)
        {
            Civilizacion &c = civilizacion[i];
            cout << i+1 << ") ";
            cout << c.getnombre() << endl;
        }
        cout << "0) Salir " << endl;

        size_t ops;
        cin >> ops; cin.ignore();

        if (ops > civilizacion.size())
        {
            cout << "Opcion incorrecta" << endl;
        }
        else if (ops != 0)
        {
            Civilizacion &c = civilizacion[ops -1];

            menucivilizacion(c);

        }
    }
}
void Videogame::respaldarciv()
{
    ofstream archivo("civilizacion.txt");
    if (archivo.is_open())
    {
        for (size_t i = 0; i < civilizacion.size(); i++)
        {
            Civilizacion &c = civilizacion[i];
            archivo << c.getnombre() << endl;
            archivo << c.getubicacion_x() << endl;
            archivo << c.getubicacion_y() << endl;
            archivo << c.getpuntuacion() << endl;
        }
    }
    archivo.close();
}
Civilizacion* Videogame::buscar(const Civilizacion &c)
{
    auto it = find(civilizacion.begin(), civilizacion.end(), c);
    if (it == civilizacion.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}

void Videogame::eliminar(const string &nom)
{
    size_t pos=0;
    Civilizacion c;

    for (size_t i = 0; i < civilizacion.size(); i++)
    {
        c = civilizacion[i];
        if(nom == c.getnombre())
        {
            break;
        }
        pos++;
    }
    if (pos >= civilizacion.size())
    {
        cout << "No encontrada" << endl;
    }
    else {
        civilizacion.erase(civilizacion.begin()+pos);
        cout << "Civilizacion eliminada" << endl;
    }
}
void Videogame::nombre_us()
{
    string nombre_usuario;
    cout << "Ingrese nombre de usuario: ";
    getline(cin, nombre_usuario);
}
