#ifndef EJERCICIO
#define EJERCICIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Traduccion.hh"
#include "CompletarPalabras.hh"
// DataTypes
#include "DataTypes/DatosEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Ejercicio
{
private: 
    string Descripcion;
    int id;
public:
    // Constructores

    // Destructor
    virtual ~Ejercicio();
    // Getters y Setters
    string getDescripcion();
    int getId();

    // Para el Caso de Uso : [Realizar Ejercicio]
    bool comprobarEjercicio();
    DatosEjercicio* obtenerDataEjercicio();
};

#endif