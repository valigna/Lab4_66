#ifndef TRADUCCION
#define TRADUCCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos del Modelo de Dominio
#include "Ejercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Traduccion: public Ejercicio
{
private:
    string frase;
    string solucion;
public:
    // Constructor
    Traduccion(string fra, string sol);
    // Destrcutor?
    // Getters y Setters
    string getFraseT();
    string getSolucionT();
    // Para el Caso de Uso : [Realizar Ejercicio]
    bool comprobarSolucionT(string sol);
};

#endif