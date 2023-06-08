#ifndef DT_TRADUCCION
#define DT_TRADUCCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "DTEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DTTraduccion : public DTEjercicio
{
private:
    string Frase;
    string Traduccion;
public:
    // Constructor
    DTTraduccion(string descripcion, int id, string frase, string trad);
    // Destructor
    ~DTTraduccion();
    // Getters
};

#endif