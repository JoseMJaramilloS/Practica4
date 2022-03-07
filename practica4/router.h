#include <iostream>
#include <map>
using namespace std;

class router
{
private:
    map<char,int> enlaces;
    map<char,int>::iterator iter;
public:
    router(char nombre){//constructor
        enlaces[nombre]=0;
    }

    void agregarEnlace(char nombre, int costo);
    void modificarEnlace(char nombre, int costo);
    void eliminarEnlace(char nombre);
    void mostrarEnlaces();

};

