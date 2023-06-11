#ifndef INFO_CURSO
#define INFO_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class InfoCurso
{
private:
    string NombreCurso;
    float Dato;
public:
    // Constructores
    InfoCurso(string nomC,float dato);
    // Destructor
    ~InfoCurso();
    // Getters
    string getNombreCurso();
    float getDato();
};

#endif