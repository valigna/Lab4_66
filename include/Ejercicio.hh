#ifndef EJERCICIO
#define EJERCICIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"

// DataTypes
#include "DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Ejercicio
{
private: 
    string Descripcion;
    int id;
public:
    // Constructores
    Ejercicio();
    // Destructor
    ~Ejercicio();
    // Getters y Setters
    string getDescripcion();
    int getId();
    // Para distinguir entre las distintas sub-clases
    virtual bool esCompletarPalabras() = 0;
    virtual bool esTraduccion() = 0;

    // Para el Caso de Uso : [Realizar Ejercicio]
    DataEjercicio* obtenerDataEjercicio();
};


#endif