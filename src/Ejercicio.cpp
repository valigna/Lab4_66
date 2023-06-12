#include "../include/Ejercicio.hh"


// Constructores
/* Ejercicio::Ejercicio(string desc, int id){
    this->Descripcion = desc;
    this->id = id;
} */

// Destructor 

// Getters y Setters
string Ejercicio::getDescripcion(){
    return this->Descripcion;
}

int Ejercicio::getId(){
    return this->getId();
}

// Para el Caso de Uso : [Realizar Ejercicio]

/* DataEjercicio* Ejercicio::obtenerDataEjercicio(){
    string descripcion = this->getDescripcion();
    float id = this->getId();
    DataEjercicio* res = new DataEjercicio(descripcion, id);
    return res;
} */

DataEjercicio* Ejercicio::obtenerDataEjercicio()
{
    return NULL;
}