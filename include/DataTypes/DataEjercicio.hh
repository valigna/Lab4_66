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
    ~DataEjercicio();
    // Getters
    string getDescripcion();
    int getId();
    // Para distinguir entre las distintas sub-clases
    virtual bool esCompletarPalabras() = 0;
    virtual bool esTraduccion() = 0;
};

#endif