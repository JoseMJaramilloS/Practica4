#include <iostream>
#include "router.h"

using namespace std;

int main()
{
    router routerA('A');
    router routerB('B');
    routerA.agregarEnlace('B',2);
    routerA.agregarEnlace('C',3);
    routerA.agregarEnlace('D',5);
    routerA.agregarEnlace('D',8);
    routerA.mostrarEnlaces(); cout<<endl;
    routerA.modificarEnlace('B',10);
    routerA.mostrarEnlaces(); cout<<endl;
    routerA.eliminarEnlace('D');
    routerA.mostrarEnlaces(); cout<<endl;

    routerB.mostrarEnlaces(); cout<<endl;

    return 0;
}
