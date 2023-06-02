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

// Otres
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
DataEjercicio* Ejercicio::obtenerDataEjercicio(){
    string descripcion = this->getDescripcion();
    float id = this->getId();
    return DatosEjercicio(descripcion, id);
}

string Ejercicio:getDescripcion(){
    return this->Descripcion;
}