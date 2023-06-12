#ifndef COMPLETAR_PALABRAS
#define COMPLETAR_PALABRAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos Del Modelo De Dominio
#include "Ejercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class CompletarPalabras: public Ejercicio
{
private:
    string frase;
    set<string> solucion;
public:
    // Getters y Setters
    string getFraseCP();
    set<string> getSolucionCP();
    // Para distinguir entre las distintas sub-clases
    bool esCompletarPalabras();
    bool esTraduccion();
    // Para el Caso de Uso : [Realizar Ejercicio]
    bool comprobarSolucionCP(set<string> sol);
};

#endif