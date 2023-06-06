#include "../include/Ejercicio.hh"
#include "..include/DataTypes/DatosEjercicio.hh"


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
//No terminada...
bool Ejercicio::comprobarEjercicio(){
    if(){
        return true;
    }
    else{
        return false;
    }
}

//No terminada...
DatosEjercicio* Ejercicio::obtenerDataEjercicio(){
    string descripcion = this->getDescripcion();
    float id = this->getId();
    return DatosEjercicio(descripcion, id);
}
