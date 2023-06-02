#ifndef IDIOMA
#define IDIOMA

// includes...
#include "Utils.hh"
#include "InterfacesYControladores/Suscripcion"

class Idioma
{
private:
    // Pseudoatibutos...
    vector<Suscripcion *> colSuscripciones;
    string Nombre;
public:
    // Constructores

    // Destructor

    // Getters y Setters
    string getNombre();
    // Otros
    void cursoEliminado(string nombreCurso);
}

#endif