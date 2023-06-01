#ifndef EJERCICIO
#define EJERCICIO

// includes ... (Parece no tener)
#include "Utils.hh"

class Ejercicio
{
private: 
    string:Descripcion;
    int id;
public:
    bool comprobarEjercicio();
    DataEjercicio* obtenerDataEjercicio();
    string getDescripcion();
}

#endif