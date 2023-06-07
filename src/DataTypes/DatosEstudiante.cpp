#include "../../include/DataTypes/DatosEstudiante.hh"

// Constructores
DatosEstudiante::DatosEstudiante(string name,string desc,string pRes, DataFecha* nac) : DatosUsuario(name,desc)
{
    this->PaisResidencia = pRes;
    this->Nacimiento = nac;
}

// Destructor
DatosEstudiante::~DatosEstudiante(){ }

// Getters
string DatosEstudiante::getPaisResidencia(){ return this->PaisResidencia; }
DataFecha* DatosEstudiante::getNacimiento(){ return this->Nacimiento; }