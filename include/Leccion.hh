#ifndef LECCION
#define LECCION

// Includes...
#include "Utils.hh"

class Leccion
{
private:

    // PseudoAtributos...
    set<Ejercicio *> colEjercicios;

public:
    // Constructores

    // Destructor
    ~Leccion();
    // Getters y Setters

    // Otres
    int totalEjercicios();
    set<DataEjercicio *> ejerciciosNoAprobadosLeccion();
    string buscarLetraEnLeccion(int ejercicio);

}

#endif