#include <iostream>
#include "net.h"

using namespace std;

int main()
{
    net red;
    char nombre;
    int costo, opcion;
    bool flag=true;

    cout<<"(1) Agregar router"<<endl;
    cout<<"(2) Eliminar router"<<endl;
    cout<<"(3) Mostrar toda la red"<<endl;
    cout<<"(0) Salir"<<endl;


    while (flag) {
        cout<<"\nIngrese opcion: "; cin>>opcion;
        switch (opcion) {

        case 0:
            flag=false;
            break;

        case 1:{
            cout<<"Nombre del router a agregar: "; cin>>nombre;
            red.agregarRouter(nombre);
            red.actualizarRed();
            break;
        }

        case 2:
            cout<<"Nombre del router a eliminar: "; cin>>nombre;
            red.eliminarRouter(nombre);
            break;

        case 3:
            red.mostrarRed();
            break;

        default:
            cout<<"Opcion invalida"<<endl;
            break;
        }

    }


    return 0;
}
