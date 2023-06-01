#ifndef NOTIFICACION
#define NOTIFICACION

// includes...
#include "Utils.hh"
#include "Idioma.hh"

class Notificacion
{
private:
    // PseudoAtributos...
    Idioma* MiIdioma;
    Curso* MiCurso;
public:
    string darIdioma();
}

#endif