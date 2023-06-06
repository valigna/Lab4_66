#include "../include/Traduccion.hh"

// Getters y Setters
string Traduccion::getFraseT(){
    return this->frase;
}

string Traduccion::getSolucionT(){
    return this->solucion;
}

// Para el Caso de Uso : [Realizar Ejercicio]
bool Traduccion::comprobarSolucionT(string sol){
    if(this->getSolucionT() == sol){
        return true;
    }
    else{
        return false;
    }
}