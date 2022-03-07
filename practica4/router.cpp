#include "router.h"

void router::agregarEnlace(char nombre, int costo)
{
    iter=enlaces.find(nombre);
    if (iter != enlaces.end()) { //si ya existe ese nombre
        cout<<"El enlace a "<<nombre<<" ya existe con un costo "<<enlaces[nombre]<<endl;
    }
    else {
        enlaces[nombre]=costo;
    }
}

void router::modificarEnlace(char nombre, int costo)
{
    enlaces[nombre]=costo;
}

void router::eliminarEnlace(char nombre)
{
    iter=enlaces.find(nombre);
    enlaces.erase(iter);
}

void router::mostrarEnlaces()
{
    for (iter=enlaces.begin();iter!=enlaces.end();iter++) {
        cout<<iter->first<<": "<<iter->second<<endl;
    }
}
