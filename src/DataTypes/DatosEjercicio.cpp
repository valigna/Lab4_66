#include "../../include/DataTypes/DatosEjercicio.hh"

// Constructores
DatosEjercicio::DatosEjercicio(string descripcionEjercicio,float idEjercicio){
    this->descripcionEjercicio = descripcionEjercicio;
    this->idEjercicio = idEjercicio;
}

// Destructores
DatosEjercicio::~DatosEjercicio(){

}

// Getters y Setters
string DatosEjercicio::getDescripcionEjercicio(){
    return this->descripcionEjercicio;
}

float DatosEjercicio::getIdEjercicio(){
    return this->idEjercicio;
}