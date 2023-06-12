#include "../include/Traduccion.hh"

// Constructor
Traduccion::Traduccion(string fra, string sol):Ejercicio(){
    this->frase = fra;
    this->solucion = sol;
} 
// Destructor

// Getters y Setters
string Traduccion::getFraseT(){
    return this->frase;
}

string Traduccion::getSolucionT(){
    return this->solucion;
}

// Para distinguir entre las distintas sub-clases
bool Traduccion::esCompletarPalabras(){ return false; }
bool Traduccion::esTraduccion(){ return true; }

// Para el Caso de Uso : [Realizar Ejercicio]
bool Traduccion::comprobarSolucionT(string sol){
    if(this->getSolucionT() == sol){
        return true;
    }
    else{
        return false;
    }
}