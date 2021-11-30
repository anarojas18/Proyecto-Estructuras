#include <iostream>
#include "videogame.h"
#include <vector>
#include <algorithm>
#include "civilizacion.h"
#include "Aldeano.h"

using namespace std;

int main()
{   
    vector<Civilizacion> civilizacion;
    Videogame v;
    int opc;
    
    v.nombre_us();
    while (true)
    {
        cout << "1) Agregar civilizacion: " << endl;
        cout << "2) Insertar (n,p): " << endl;
        cout << "3) Inicializar: " << endl;
        cout << "4) Primera Civilizacion: " << endl;
        cout << "5) Ultima Civilizacion: " << endl;
        cout << "6) Ordenar por nombre: " << endl;
        cout << "7) Ordenar por ubicacion en x: " << endl;
        cout << "8) Ordenar por ubicacion en y: " << endl;
        cout << "9) Ordenar por puntuacion: " << endl;
        cout << "10) Eliminar civilizacion: " << endl;
        cout << "11) Buscar civilizacion: " << endl;
        cout << "12) Total de civilizaciones: " << endl;
        cout << "13) Modificar: " << endl;
        cout << "14) Mostrar: " << endl;
        //cout << "15) Respaldar" << endl;
        cout << "0) Salir: " << endl;
        cin>>opc;
        cin.ignore();

        if(opc==1){

            Civilizacion c;
            cin >> c;   cin.ignore();

            v.agregarCivilizacion(c);
            
        }
        else if(opc==2)
        {
            Civilizacion c;
            cin >> c;
            size_t pos;
            cout << "Ingrese posicion: ";
            cin >> pos; cin.ignore();

            if(pos >= v.size()){
                cout <<"Posicion no valida" << endl;
            }
            else
            {
                v.insertar(c, pos);
            }
        }
        else if (opc==3)
        {
            Civilizacion c;
            cin>> c;

            size_t n;
            cout << "n: ";
            cin >> n; cin.ignore();
            v.inicializar(c,n);
        }
        else if(opc==4)
        {
            v.primero();
        }
        else if(opc==5)
        {
           v.ultimo();
        }
          else if(opc==6)
        {
            v.ordenarnombre();
        }
        else if(opc==7)
        {
            v.ordenarub_x();
        }
        else if(opc==8)
        {
            v.ordenarub_y();
        }
        else if(opc==9)
        {
            v.ordenarpuntuacion();
        }
        else if(opc==10)
        {   string nom;
            size_t pos;
            Civilizacion c;
            cin >> c;
            
            cout << "Ingrese nombre: ";
            cin >> nom; cin.ignore();

              v.eliminar(nom);
            
        }
        else if(opc==13)
        {
            Civilizacion c;
            cin >> c; cin.ignore();
            
            Civilizacion *ptr = v.buscar(c);
            if (ptr==nullptr)
            {
                cout << "No encontrado:" << endl;
            }
            else
            {
                int op;
                cout << *ptr << endl;
                cout << "Modificar: " << endl;
                cout << "1) Nombre" << endl;
                cout << "2) Posicion en x" << endl;
                cout << "3) Posicion en y" << endl;
                cout << "4) Puntuacion: " << endl;
                cin >> op; cin.ignore();
                if (op==1)
                {
                    string temp;
                    cout << endl <<"Nuevo nombre: ";
                    getline(cin,temp); 
                    ptr->setnombre(temp);
                    cout << endl  << "Nombre actualizado "<< endl;
                }
                else if (op==2) 
                {
                    int temp;
                    cout << endl << "Nueva ubicacion en x: ";
                    cin >> temp; 
                    ptr->setubicacion_x(temp);
                    cout << endl << "Ubicacion actualizada " << endl;
                    
                }
                else if (op==3)
                {
                    int temp;
                    cout << endl << "Nueva ubicacion en y: ";
                    cin >> temp; 
                    ptr->setubicacion_y(temp);
                    cout << endl << "Ubicacion actualizada " << endl;
                }
                else if(op==4) 
                {
                    int temp;
                    cout << endl << "Nueva puntuacion: ";
                    cin >> temp;
                    ptr->setpuntuacion(temp);
                    cout << endl << "Puntuacion actualizada " << endl;

                }
                
            }
        }
        else if(opc==11)
        {
              
            v.mostrarA();
                                    
        }
        else if(opc==12)
        {
            cout << "Total: "<< v.size() << endl;             
        }
        else if (opc==14)
        {
            v.mostrar();
        }
        else if (opc==0)
        {
               break;
        } 
    }
    return 0;
}
