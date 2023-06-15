#include "../../include/DataTypes/DataEstudiante.hh"

// Constructores
DataEstudiante::DataEstudiante(string nick, string name, string con, string desc, string pRes, DataFecha* nac): DataUsuario(nick,name,con,desc)
{
    this->PaisResidencia = pRes;
    this->Nacimiento = nac;
}

// Destructor
DataEstudiante::~DataEstudiante()
{
    delete this->Nacimiento;
}

// Getters
string DataEstudiante::getPaisResidencia(){ return this->PaisResidencia; }
DataFecha* DataEstudiante::getNacimiento(){ return this->Nacimiento; }

// Para distinguir entre las distintas sub-clases
bool DataEstudiante::esEstudiante(){ return true; }
bool DataEstudiante::esProfesor(){ return false; }