#ifndef SUSCRIPCION
#define SUSCRIPCION

#include "../Utils.hh"

class Suscripcion
{
public:
    virtual void notificarBaja(string nombreCurso) = 0;
    virtual void notificarAlta(Idioma *i,Curso *c) = 0;

    virtual ~Suscripcion();
}

#endif