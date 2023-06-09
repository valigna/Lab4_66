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

DatosEjercicio* Ejercicio::obtenerDataEjercicio(){
    string descripcion = this->getDescripcion();
    float id = this->getId();
    DatosEjercicio* res = new DatosEjercicio(descripcion, id);
    return res;
}
