#include "../../include/DataTypes/DatosEjercicio.hh"

// Constructores
DatosEjercicio::DatosEjercicio(string desc, int id)
{
    this->Descripcion = desc;
    this->Id = id;
}

// Destructor
DatosEjercicio::~DatosEjercicio(){ }

// Getters
string DatosEjercicio::getDescripcion(){ return this->Descripcion; }
int DatosEjercicio::getId(){ return this->Id; }