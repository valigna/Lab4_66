#ifndef EJERCICIO
#define EJERCICIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"

// DataTypes
#include "DataTypes/DataEjercicio.hh"
#include "DataTypes/DataTraduccion.hh"
#include "DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Ejercicio
{
private: 
    string Descripcion;
    int id;
public:
    // Constructores
    /* Ejercicio(); */
    Ejercicio(int idEj, string desc);
    // Destructor
    ~Ejercicio();
    // Getters y Setters
    string getDescripcion();
    int getId();
    // DataTypes
    virtual DataEjercicio* getDataEjercicio() = 0;
    // Para distinguir entre las distintas sub-clases
    virtual bool esCompletarPalabras() = 0;
    virtual bool esTraduccion() = 0;

    // Para el Caso de Uso : [Realizar Ejercicio]
    /* DataEjercicio* obtenerDataEjercicio(); */
};


#endif