#ifndef DATOS_PROFESOR
#define DATOS_PROFESOR

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "DatosUsuario.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DatosProfesor : public DatosUsuario
{
private:
    string Instituto;
    set<string> Idiomas;
public:
    // Constructores
    DatosProfesor(string name,string desc,string inst,set<string> especializa);
    // Destructor
    ~DatosProfesor();
    // Getters
    string getInstituto();
    set<string> getIdiomas();
};

#endif