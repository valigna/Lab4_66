#include "../include/Ejercicio.hh"

// Constructores

// Destructor
Ejercicio::~Ejercicio(){ }
// Getters y Setters
string Ejercicio::getDescripcion(){
    return this->Descripcion;
}

int Ejercicio::getId(){
    return this->id;
}