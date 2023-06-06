#ifndef COMPLETARPALABRA
#define COMPLETARPALABRA

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Ejercicio.hh"
// DataTypes
#include "DataTypes/InfoCursoEst.hh"
#include "DataTypes/DataFecha.hh"
/* ------------------------------------------------------------------------------------------------------ */

class CompletarPalabra: public Ejercicio
{
private:
    string frase;
    set<string> solucion;
public:
    // Getters y Setters
    string getFraseCP();
    string getSolucionCP();
    // Para el Caso de Uso : [Realizar Ejercicio]
    bool comprobarSolucionCP(set<string> sol);
};

#endif