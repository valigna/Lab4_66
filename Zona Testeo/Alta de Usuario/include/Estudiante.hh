#ifndef ESTUDIANTE
#define ESTUDIANTE

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../../include/Utils.hh"
#include "Usuario.hh"
// DataTypes
#include "../../../include/DataTypes/InfoCursoEst.hh"
#include "../../../include/DataTypes/DataFecha.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Estudiante: public Usuario
{
private:
    string PaisResidencia;
    DataFecha* Nacimiento;
    // PseudoAtributos
    set<Inscripcion *> colInscripciones; 
public:
    // Constructores
    Estudiante(string nick,string name, string pass, string desc, DataEstudiante* est);
    // Destructor

    // Getters y Setters
    string getPaisResidencia();
    DataFecha* getNacimiento();
};

#endif