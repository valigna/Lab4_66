#include "../../include/DataTypes/DataProfesor.hh"

// Constructores
DataProfesor::DataProfesor(string nick, string name, string con, string desc,string inst): DataUsuario(nick,name,con,desc)
{
    this->Instituto = inst;
}

// Destructor
DataProfesor::~DataProfesor(){ }

// Getters
string DataProfesor::getInstituto(){ return this->Instituto; }