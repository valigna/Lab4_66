#ifndef COMPLETAR_PALABRAS
#define COMPLETAR_PALABRAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos Del Modelo De Dominio
#include "Ejercicio.hh"
#include "DataTypes/DataCompletarPalabras.hh"
/* ------------------------------------------------------------------------------------------------------ */

class CompletarPalabras: public Ejercicio
{
private:
    string frase;
    set<string> solucion;
public:
    // Constructores
    /* CompletarPalabras(string frase, set<string> solucion); */
    CompletarPalabras(int idEj, DataEjercicio* ejercicio);
    // Destructor
    ~CompletarPalabras();
    // Getters y Setters
    string getFraseCP();
    set<string> getSolucionCP();
    // DataTypes
    DataEjercicio* getDataEjercicio();
    // Para distinguir entre las distintas sub-clases
    bool esCompletarPalabras();
    bool esTraduccion();
    // Para el Caso de Uso : [Realizar Ejercicio]
    bool comprobarSolucionCP(set<string> sol);
};

#endif