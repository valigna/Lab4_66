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

//
/* DataEjercicio* Ejercicio::obtenerDataEjercicio(){
    string descripcion = this->getDescripcion();
    float id = this->getId();
    DataEjercicio* res = new DataEjercicio(descripcion, id);
    return res;
} */
