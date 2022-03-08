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
            red.insert(pair<char,router>(nombre,routerTemp));//agrego el router a la red

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
    char rout,pend;//rout: es el router y pend, el nodo que le falta
    unsigned int costo=0,i=1,tam;
    tam=red.size();
    while (i<=red.size()) {
        for (iter_red = red.begin();iter_red != red.end(); iter_red++) {//Recorre la red y el de abajo recorre los enlaces
            for (iter_red2 = red.begin();iter_red2 != red.end(); iter_red2++) {
                (iter_red->second).iter=(iter_red->second).enlaces.find(iter_red2->first);
                cout<<"Router "<<iter_red->first<<" preguntando por enlace a "<<iter_red2->first<<": ";
                if ((iter_red->second).iter == (iter_red->second).enlaces.end()) { //Si el router no esta en la TE
                    cout<<"NO"<<endl;
                    rout=iter_red->first;
                    pend=iter_red2->first;
                }
                else {
                    cout<<"SI"<<endl;
                    (iter_red->second).iter=(iter_red->second).enlaces.find(rout); //busco si este router tiene un enlace para completar el anterior
                    if (iter_red2->first==pend && (iter_red->second).iter!=(iter_red->second).enlaces.end()) {
                        costo=iter_red->second.iter->second;
                        (iter_red->second).iter=(iter_red->second).enlaces.find(pend);
                        costo+=iter_red->second.iter->second;
                        cout<<"Enlazando "<<rout<<" con "<<pend<<" y costo de "<<costo<<endl;
                        iter_red3=red.find(rout);//busco la ubicacion del router
                        iter_red3->second.agregarEnlace(pend,costo);//le agrego el enlace faltante
                        iter_red3=red.find(pend);
                        iter_red3->second.agregarEnlace(rout,costo);//actualizo el otro router
                        rout = pend = '\0';
                        costo=0;
                    }
                }
            }
        }
        cout<<endl;
        i++;
    }
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
