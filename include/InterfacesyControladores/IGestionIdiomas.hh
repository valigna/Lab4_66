#ifndef I_GESTION_IDIOMAS
#define I_GESTION_IDIOMAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class IGestionIdiomas
{
    virtual bool altaIdioma(string nombre) = 0;
    virtual set<string> getIdiomas() = 0;

    virtual ~IGestionIdiomas();
};

#endif