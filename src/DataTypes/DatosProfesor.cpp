#include "../../include/DataTypes/DatosProfesor.hh"

// Constructores
DatosProfesor::DatosProfesor(string name,string desc,string inst,set<string> especializa) : DatosUsuario(name,desc)
{
    this->Instituto = inst;
    this->Idiomas = especializa;
}

// Destructor
DatosProfesor::~DatosProfesor(){ }

// Getters
string DatosProfesor::getInstituto(){ return this->Instituto; }
set<string> DatosProfesor::getIdiomas(){ return this->Idiomas; }
