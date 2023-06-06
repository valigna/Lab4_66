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
    // Constructores

    // Destructor
    ~Ejercicio(); // Destructor por defecto
    // Getters y Setters
    getDescripcion();
    getId();

    // Para el Caso de Uso : [Realizar Ejercicio]
    bool comprobarEjercicio();
    DatosEjercicio* obtenerDataEjercicio();
}

#endif