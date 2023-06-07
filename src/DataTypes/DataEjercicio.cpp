#include "../../include/DataTypes/DataEjercicio.hh"

// Constructores
DataEjercicio::DataEjercicio(string desc,int id)
{
    this->Descripcion = desc;
    this->id = id;
}

// Destructor
DataEjercicio::~DataEjercicio(){ }

// Getters
string DataEjercicio::getDescripcion(){ return this->Descripcion; }
int DataEjercicio::getId(){ return this->id; }