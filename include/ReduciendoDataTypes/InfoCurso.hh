#ifndef INFO_CURSO
#define INFO_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class InfoCurso
{
private:
    string NombreCurso;
    float Promedio;
public:
    // Constructores
    InfoCurso(string nomC,float prom);
    // Destructor
    ~InfoCurso();
    // Getters
    string getNombreCurso();
    float getPromedio();
};

#endif