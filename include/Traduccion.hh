#ifndef TRADUCCION
#define TRADUCCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos del Modelo de Dominio
#include "Ejercicio.hh"
#include "DataTypes/DataTraduccion.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Traduccion: public Ejercicio
{
private:
    string frase;
    string solucion;
public:
    // Constructor
    Traduccion(string fra, string sol);
    // Destrcutor
    ~Traduccion();
    // Getters y Setters
    string getFraseT();
    string getSolucionT();
    // DataTypes
    DataEjercicio* getDataEjercicio();
    // Para distinguir entre las distintas sub-clases
    bool esCompletarPalabras();
    bool esTraduccion();
    // Para el Caso de Uso : [Realizar Ejercicio]
    bool comprobarSolucionT(string sol);
};

#endif