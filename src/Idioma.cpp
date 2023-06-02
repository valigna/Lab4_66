#include "../include/Idioma.hh"

//Destructor

void Idioma::cursoEliminado(string nombreCurso){
    for(vector<Suscripcion *>::iterator it = this->colSuscripciones.begin(); it != this->colSuscripciones.end(); ++it){
        it->notificarBaja(nombreCurso);
    }
}



// Getters y Setters
string Idioma::getNombre(){
    return this->Nombre;
}

