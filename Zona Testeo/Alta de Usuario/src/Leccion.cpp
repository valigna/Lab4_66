#include "../include/Leccion.hh"

// Constructores

// Destructor
Leccion::~Leccion(){
    for(set<Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it){
        delete it;
    }
}