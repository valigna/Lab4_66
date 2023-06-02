#ifndef NOTIFICACION
#define NOTIFICACION

// includes...
#include "Utils.hh"
#include "Idioma.hh"
#include "Curso.hh"

class Notificacion
{
private:
    // PseudoAtributos...
    Idioma* MiIdioma;
    Curso* MiCurso;
public:
    // Constructores

    // Destructor
    ~Notificacion(); // Se usa el destructor por defecto, no?
    // Getters y Setters

    // Otros
    string darIdioma();


    // Para el caso de uso : [Eliminar Curso]
    bool presentaCurso(string nombreCurso);
}

#endif