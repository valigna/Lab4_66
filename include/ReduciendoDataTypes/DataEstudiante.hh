#ifndef DATA_ESTUDIANTE
#define DATA_ESTUDIANTE

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "DataUsuario.hh"
#include "DataFecha.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataEstudiante : public DataUsuario
{
private:
    string PaisResidencia;
    DataFecha* Nacimiento;
public:
    // Constructores
    DataEstudiante(string nick, string name, string con, string desc, string pRes, DataFecha* nac);
    // Destructor
    ~DataEstudiante();
    // Getters
    string getPaisResidencia();
    DataFecha* getNacimiento();
};

#endif