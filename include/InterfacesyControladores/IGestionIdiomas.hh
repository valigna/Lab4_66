#ifndef I_GESTION_IDIOMAS
#define I_GESTION_IDIOMAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class IGestionIdiomas
{
public:
    // Operaciones Para El Caso de Uso : [Alta de Idioma]
    virtual bool altaIdioma(string nombre) = 0;
    // Operaciones Para El Caso de Uso : [Consultar Idiomas]
    virtual set<string> getIdiomas() = 0;
    //
    virtual ~IGestionIdiomas(){};
};

#endif