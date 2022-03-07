#include "net.h"

net::net()
{
}

void net::agregarRouter(char nombre)
{
    router routerTemp(nombre);
    char name;
    int costo;

    iter_red=red.find(nombre);
    if (iter_red != red.end()) { //si ya existe ese nombre
        cout<<"El router de nombre "<<nombre<<" ya existe en la red"<<endl;
    }
    else {
        if (red.size()==0) {//si es el primer router
            red.insert(pair<char,router>(nombre,routerTemp));
            cout<<"Primer router de la red agregado"<<endl;
        }
        else {
            cout<<"\nRealizacion de enlaces"<<endl;
            do {
                cout<<"\nIngrese router para realizar enlace (0 para salir): "; cin>>name;
                if (name !='0') {
                    iter_red=red.find(name);
                    if (name == nombre){
                        cout<<"No puede realizar un enlace con el mismo router"<<endl;
                    }
                    else if (iter_red == red.end()) {
                        cout<<"Ese router no existe"<<endl;
                    }

                    else {
                        cout<<"Ingrese costo del enlace: "; cin>>costo;
                        routerTemp.agregarEnlace(name,costo);//agrego el enlace al router que se esta agregando
                        iter_red=red.find(name);
                        iter_red->second.agregarEnlace(nombre,costo);//actualizo el otro router
                    }
                }

            } while (name != '0');
            red.insert(pair<char,router>(nombre,routerTemp));
        }
    }

}

void net::eliminarRouter(char nombre)
{
    iter_red=red.find(nombre);
    if (iter_red == red.end()) { //si no existe ese nombre
        cout<<"El router de nombre "<<nombre<<" NO existe en la red"<<endl;
    }
    else {
        for (iter_red=red.begin();iter_red!=red.end();iter_red++) {
            iter_red->second.eliminarEnlace(nombre); //eliminar los enlaces en cada router
        }
        iter_red=red.find(nombre);
        red.erase(iter_red); //y luego elimina le router en la red
    }
}

void net::actualizarRed()
{

}

void net::mostrarRed()
{
    cout<<endl<<"  ";
    for (iter_red=red.begin();iter_red!=red.end();iter_red++) {
        cout<<iter_red->first<<" ";
    }
    cout<<endl;
    for (iter_red=red.begin();iter_red!=red.end();iter_red++) {
        cout<<iter_red->first<<" ";
        iter_red->second.mostrarEnlaces();
        cout<<endl;
    }

}
