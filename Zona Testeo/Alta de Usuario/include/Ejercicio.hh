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
    Ejercicio(string desc, int id);
    // Destructor
    ~Ejercicio(); // Destructor por defecto
    // Getters y Setters
    string getDescripcion();
    int getId();
};

#endif