#ifndef SUSCRIPCION
#define SUSCRIPCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "../Curso.hh"
#include "../Idioma.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Suscripcion
{
public:
    virtual void notificarBaja(string nombreCurso) = 0;
    virtual void notificarAlta(Idioma *i,Curso *c) = 0;

    virtual ~Suscripcion();
};

#endif