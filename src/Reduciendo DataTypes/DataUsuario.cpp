#include "../../include/DataTypes/DataUsuario.hh"

// Constructores
DataUsuario::DataUsuario(string nick, string name, string con, string desc)
{
    this->Nickname = nick;
    this->Nombre = name;
    this->Contrasenia = con;
    this->Descripcion = desc;
}

// Destructor
DataUsuario::~DataUsuario(){ }

// Getters
string DataUsuario::getNickname(){ return this->Nickname; }
string DataUsuario::getNombre(){ return this->Nombre; }
string DataUsuario::getContrasenia(){ return this->Contrasenia; }
string DataUsuario::getDescripcion(){ return this->Descripcion; }