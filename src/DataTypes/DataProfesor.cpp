#include "../../include/DataTypes/DataProfesor.hh"

// Constructores
DataProfesor::DataProfesor(string nick, string name, string con, string desc,string inst,set<string> idiomas) : DataUsuario(nick,name,con,desc)
{
    this->Instituto = inst;
    this->Idiomas = idiomas;
}

// Destructor
DataProfesor::~DataProfesor(){ }

// Getters
string DataProfesor::getInstituto(){ return this->Instituto; }
set<string> DataProfesor::getIdiomas(){ return this->Idiomas; }

// Para distinguir entre las distintas sub-clases
bool DataProfesor::esEstudiante(){ return false; }
bool DataProfesor::esProfesor(){ return true; }