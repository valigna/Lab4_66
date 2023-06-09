#include "../include/Ejercicio.hh"


// Constructores

// Destructor 

// Getters y Setters
string getDescripcion(){
    return this->descripcion;
}

float getId(){
    return this->getId();
}

// Para el Caso de Uso : [Realizar Ejercicio]

DataEjercicio* Ejercicio::obtenerDataEjercicio(){
    string descripcion = this->getDescripcion();
    float id = this->getId();
    DataEjercicio* res = new DataEjercicio(descripcion, id);
    return res;
}
