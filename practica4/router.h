#include <iostream>
#include <map>
using namespace std;

class router
{
    //Atributos
private:
    map<char,int> enlaces;
    map<char,int>::iterator iter;

    //Metodos
public:
    router(char nombre){
        enlaces[nombre]=0;
    }
    void agregarEnlace(char nombre, int costo);
    void modificarEnlace(char nombre, int costo);
    void eliminarEnlace(char nombre);
    void mostrarEnlaces();
    friend class net;
};

