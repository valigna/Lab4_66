#ifndef INFO_CURSO_PROF
#define INFO_CURSO_PROF

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class InfoCursoProf
{
private:
    string NombreCurso;
    float Promedio;
public:
    // Constructores
    InfoCursoProf(string nomC,float prom);
    // Destructor
    ~InfoCursoProf();
    // Getters
    string getNombreCurso();
    float getPromedio();
};

#endif