#ifndef EJERCICIO
#define EJERCICIO

// includes
#include "../../../include/Utils.hh"

class Ejercicio
{
private: 
    string Descripcion;
    int id;
public:
    // Constructores

    // Destructor
    ~Ejercicio(); // Destructor por defecto
    // Getters y Setters
    string getDescripcion();
    int getId();
};

#endif