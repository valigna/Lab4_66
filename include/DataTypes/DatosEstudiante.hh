#ifndef DATOS_ESTUDIANTE
#define DATOS_ESTUDIANTE

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "DatosUsuario.hh"
#include "DataFecha.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DatosEstudiante : public DatosUsuario
{
private:
    string PaisResidencia;
    DataFecha* Nacimiento;
public:
    // Constructores
    DatosEstudiante(string name, string desc, string pRes, DataFecha* nac);
    // Destructor
    ~DatosEstudiante();
    // Getters
    string getPaisResidencia();
    DataFecha* getNacimiento();
};

#endif