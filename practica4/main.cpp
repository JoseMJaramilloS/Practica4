#include <iostream>
#include "net.h"

using namespace std;

int main()
{
    net red,red_original;
    char nombre, origen, destino;
    int opcion;
    bool flag=true;

    cout<<"(1) Agregar router"<<endl;
    cout<<"(2) Eliminar router"<<endl;
    cout<<"(3) Mostrar toda la red"<<endl;
    cout<<"(4) Calcular costo y ruta"<<endl;
    cout<<"(0) Salir"<<endl;


    while (flag) {
        cout<<"\nIngrese opcion: "; cin>>opcion;
        switch (opcion) {

        case 0:
            flag=false;
            break;

        case 1:{
            cout<<"Nombre del router a agregar: "; cin>>nombre;
            red_original.agregarRouter(nombre);//red sin enlaces indirectos
            red=red_original;//red con enlaces indirectos
            red.actualizarRed();
            break;
        }

        case 2:
            cout<<"Nombre del router a eliminar: "; cin>>nombre;
            red.eliminarRouter(nombre);
            red.actualizarRed();//ESTO NO SE HA PROBADO AUN
            red_original.eliminarRouter(nombre);
            break;

        case 3:
            red.mostrarRed();
            cout<<endl;
            red_original.mostrarRed();
            break;

        case 4:
            cout<<"Ingrese router origen: "; cin>>origen;
            cout<<"Ingrese router destino: "; cin>>destino;
            red_original.hallarCamino(origen,destino);
            break;

        default:
            cout<<"Opcion invalida"<<endl;
            break;
        }

    }


    return 0;
}
