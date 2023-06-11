#ifndef COMPLETAR_PALABRA
#define COMPLETAR_PALABRA

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos Del Modelo De Dominio
#include "Ejercicio.hh"
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