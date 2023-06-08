#ifndef DT_COMPLETAR_PALABRAS
#define DT_COMPLETAR_PALABRAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "DTEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DTCompletarPalabras : public DTEjercicio
{
private:
    string Frase;
    set<string> Solucion;
public:
    // Constructores
    DTCompletarPalabras(string desc, int id, string frase, set<string> sol);
    // Destructor
    ~DTCompletarPalabras();
    // Getters?
};

#endif