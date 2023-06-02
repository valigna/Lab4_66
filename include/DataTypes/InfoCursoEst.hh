#ifndef INFOCURSOEST
#define INFOCURSOEST

// Includes...
#include "../Utils.hh"

class InfoCursoEst
{
private:
    string NombreCurso;
    float Avance;
public:
    // Constructores
    InfoCursoEst(string NomC,float Avance);
    // Destructor
    ~InfoCursoEst();
    // Getters
    string getNombreCurso();
    float getAvance();
} 

#endif