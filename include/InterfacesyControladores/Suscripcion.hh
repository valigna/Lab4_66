#ifndef SUSCRIPCION
#define SUSCRIPCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"

class Idioma;
class Curso;
/* ------------------------------------------------------------------------------------------------------ */

class Suscripcion
{
public:
    virtual void notificarBaja(string nombreCurso) = 0;
    virtual void notificarAlta(Idioma *i,Curso *c) = 0;

    virtual ~Suscripcion();
};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "../Idioma.hh"
#include "../Curso.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif