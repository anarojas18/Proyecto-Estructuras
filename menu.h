#include "civilizacion.h"
#include <fstream>
#include <algorithm>

Aldeano capturar()
{
    Aldeano a;
    string nombrea;
    size_t edad;
    string genero;
    size_t salud;
    
    cout << "Nombre:";
    getline(cin,nombrea); 
    a.setNombrea(nombrea);

    cout << "Edad: ";
    cin >> edad;
    a.setEdad(edad); cin.ignore();

    cout << "Genero: ";
    getline (cin, genero);
    a.setGenero(genero);

    cout << "Salud: ";
    cin >> salud; cin.ignore(); //en alguna 
    a.setSalud(salud); 

    return a;
}
void menuagregar(Civilizacion &c)
{
    string op;
    while (true)
    {
        cout << "Agregar aldeano." << endl;
        cout << "1) Agregar al inicio" << endl;
        cout << "2) Agregar al final" << endl;
        cout << "3) Mostrar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op); //cin.ignore();/c

        if(op == "1")
        {
            c.agregarinicio(capturar());
        }
        else if(op == "2")
        {
            Aldeano a = capturar();
            c.agregarfinal(a);
        }
        else if (op == "3")
        {
            c.print();
        }
        
        else if(op == "0")
        {
            break;
        }
    }
}

void menueliminar(Civilizacion &c)
{
    string op;
    while (true)
    {
        cout << "Eliminar aldeano." << endl;
        cout << "1) Eliminar por nombre" << endl;
        cout << "2) Eliminar por salud (mayor a...) " << endl;
        cout << "3) Eliminar por edad" << endl;
        cout << "4) Mostrar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op); //cin.ignore(); /c

        if (op == "1")
        {
            string nombrea;
            cout << "Nombre: ";
            getline(cin, nombrea);

            c.eliminarNombrea(nombrea);
            cout << "Aldeano eliminado" << endl;
        }
        else if(op == "2")
        {
            size_t salud;
            cout << "Eliminar los que tengas salud mayor a ";
            cin >> salud; cin.ignore();

            c.eliminarsalud(salud);
            cout << "Aldeano(s) eliminado(s)" << endl;
        }
        else if (op == "3")
        {
            c.eliminaredad();
            cout << "Aldeano eliminado" <<endl;
        }
        else if (op == "4")
        {
            c.print();
        }
        
        else if (op == "0")
        {
            break;
        }
    }
}

void menuclasificar(Civilizacion &c)
{
    string op;
    while (true)
    {
        cout << "Clasificar aldeano." << endl;
        cout << "1) Ordenar por nombre" << endl;
        cout << "2) Ordenar por edad" << endl;
        cout << "3) Ordenar por salud" << endl;
        cout << "4) Mostrar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op); //cin.ignore(); /c     

        if(op == "1")
        {
            c.ordenarNombrea();
            cout << "Se ordeno por nombre" << endl;
        }
        else if(op == "2")
        {
            c.ordenarEdad();
            cout << "Se ordeno por edad" << endl;
        }
        else if(op == "3")
        {
            c.ordenarSalud();
            cout << "Se ordeno por salud" << endl;
        }
        else if (op == "4")
        {
            c.print();
        }
        
        else if(op == "0")
        {
            break;
        }
    }
} 


/*void modificar(Civilizacion &civ)
{
    Civilizacion c;
    Aldeano a;
    cout << a; cin.ignore();

    Aldeano *ptr = c.buscarA(a);
    if (ptr==nullptr)
    {
        cout << "No encontrado:" << endl;
    }
    else
    {
        int o;
        cout << *ptr << endl;
        cout << "Modificar: " << endl;
        cout << "1) Nombre" << endl;
        cout << "2) Edad" << endl;
        cout << "3) Genero" << endl;
        cout << "4) Salud " << endl;
        cout << "0) Salir" << endl;
        cin >> o; cin.ignore();
        if (o==1)
        {
            string temp;
            cout << endl <<"Nuevo nombre: ";
            getline(cin,temp); 
            ptr->setNombrea(temp);
            cout << endl  << "Nombre actualizado "<< endl;
        }
        else if (o==2) 
        {
            int temp;
            cout << endl << "Nueva edad: ";
            cin >> temp; 
            ptr->setEdad(temp);
            cout << endl << "Edad actualizada " << endl;
        }
        else if (o==3)
        {
            string temp;
            cout << endl << "Nuevo genero: ";
            getline(cin, temp); 
            ptr->setGenero(temp);
            cout << endl << "Genero actualizado " << endl;
        }
        else if(o==4) 
        {
            int temp;
            cout << endl << "Nueva salud: ";
            cin >> temp;
            ptr->setSalud(temp);
            cout << endl << "Salud actualizada " << endl;
        }
        else if (o==0)
        {
            break;
        }
    }                        
}
*/

void menucivilizacion(Civilizacion &c)
{
    while (true)
    {
        Civilizacion c;
        Aldeano a;
        size_t o;
        cout << "Aldeanos: " << endl;
        cout << "1) Agregar aldeano." << endl;
        cout << "2) Eliminar aldeano." << endl;
        cout << "3) Clasificar aldeano." << endl;
        cout << "4) Busca aldeano." << endl;
        cout << "5) Modificar aldeano." << endl;
        cout << "6) Mostrar aldeanos." << endl;
        cout << "0) Salir" << endl;
        cin >> o; cin.ignore();
                    
        if(o == 1)
        { 
            Civilizacion c;
            //agregar
            menuagregar(c);
        }
        else if(o==2)
        {
            //eliminar
            Civilizacion c;
            menueliminar(c);
        
        }
        else if (o==3)
        {  
            //ordenar
            Civilizacion c;
            menuclasificar(c);
        }
        else if(o==4)
        {
            //buscar
           
        }
        else if (o==5)
        {
            //Modificar
           
        }
        else if (o==6)
        {
            //Mostrar
            Civilizacion c;   
            c.print();   
        }
        else if(o == 0)
        {
            break;
        }
    }
}
