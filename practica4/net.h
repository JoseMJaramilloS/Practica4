#include <iostream>
#include <map>
#include "router.h"
using namespace std;

class net
{
private:
    map<char,router> red;
    map<char,router>::iterator iter_red;
public:
    net();
    void agregarRouter(char nombre);
    void eliminarRouter(char nombre);
    void actualizarRed();
    void mostrarRed();
};


