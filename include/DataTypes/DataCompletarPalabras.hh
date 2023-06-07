#ifndef DATA_COMPLETAR_PALABRAS
#define DATA_COMPLETAR_PALABRAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataCompletarPalabras : public DataEjercicio
{
private:
    string Frase;
    set<string> Solucion;
public:
    // Constructores
    DataCompletarPalabras(string desc, int id, string frase, set<string> sol);
    // Destructor
    ~DataCompletarPalabras();
    // Getters
    string getFrase();
    set<string> getSolucion();
};

#endif