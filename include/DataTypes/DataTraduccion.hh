#ifndef DATA_TRADUCCION
#define DATA_TRADUCCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataTraduccion : public DataEjercicio
{
private:
    string Frase;
    string Traduccion;
public:
    // Constructor
    DataTraduccion(string desc, int id, string frase, string trad);
    // Destructor
    ~DataTraduccion();
    // Getters
    string getFrase();
    string getTraduccion();
};

#endif