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
    cout<<"(2) Mostrar toda la red"<<endl;
    cout<<"(0) Salir"<<endl;


    while (flag) {
        cout<<"\nIngrese opcion: "; cin>>opcion;
        switch (opcion) {

        case 0:
            flag=false;
            break;

        case 1:{
            cout<<"Nombre del router: "; cin>>nombre;
            red.agregarRouter(nombre);
            break;
        }
        case 2:
            red.mostrarRed();
            break;
        }

    }


    return 0;
}
