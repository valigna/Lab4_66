#ifndef DATOS_EJERCICIO
#define DATOS_EJERCICIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DatosEjercicio
{
private:
    string Descripcion;
    int Id;
public:
    // Constructor
    DatosEjercicio(string desc, int id);
    // Destructor
    ~DatosEjercicio();
    // Getters
    string getDescripcion();
    int getId();
};

#endif