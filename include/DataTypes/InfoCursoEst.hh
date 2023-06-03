#ifndef INFO_CURSO_EST
#define INFO_CURSO_EST

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */


class InfoCursoEst
{
private:
    string NombreCurso;
    float Avance;
public:
    // Constructores
    InfoCursoEst(string nomC,float avance);
    // Destructor
    ~InfoCursoEst();
    // Getters
    string getNombreCurso();
    float getAvance();
}; 

#endif