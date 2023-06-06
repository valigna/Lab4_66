#include "../include/CompletarPalabras.hh"

// Getters y Setters
string CompletarPalabras::getFrase(){
    return this->frase;
}

set<string> CompletarPalabras::getSolucionCP(){
    return this->solucion;
}

// Para el Caso de Uso : [Realizar Ejercicio]
bool CompletarPalabras::comprobarSolucionCP(set<string> sol){
    bool res = true;
    set<string>::iterator aux = sol;
    for(set<string>::iterator it = this->solucion.begin(); it != this->solucion.end(); ++it){
        if(it == aux){
            return false;
        }
        aux++;
    }
    return res;
}