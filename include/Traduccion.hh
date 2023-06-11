#ifndef TRADUCCION
#define TRADUCCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Ejercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Traduccion: public Ejercicio
{
private:
    string frase;
    string solucion;
public:
    // Getters y Setters
    string getFraseT();
    string getSolucionT();
    // Para el Caso de Uso : [Realizar Ejercicio]
    bool comprobarSolucionT(string sol);
};

#endif