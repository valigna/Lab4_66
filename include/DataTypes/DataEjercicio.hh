#ifndef DATA_EJERCICIO
#define DATA_EJERCICIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataEjercicio
{
private:
    string Descripcion;
    int id;
public:
    // Constructor
    DataEjercicio(string desc,int id);
    // Destructor
    virtual ~DataEjercicio();
    // Getters
    string getDescripcion();
    int getId();
};

#endif