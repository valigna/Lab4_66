#include "../../include/DataTypes/DatosUsuario.hh"

// Constructor
DatosUsuario::DatosUsuario(string name, string desc)
{
    this->Nombre = name;
    this->Descripcion = desc;
}

// Destructor
DatosUsuario::~DatosUsuario(){ }

// Getters
string DatosUsuario::getNombre(){ return this->Nombre; }
string DatosUsuario::getDescripcion(){ return this->Descripcion; }