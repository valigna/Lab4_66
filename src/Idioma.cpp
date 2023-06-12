#include "../include/Idioma.hh"


// Constructores
Idioma::Idioma(string nombre)
{
    this->Nombre = nombre;
}

//Destructor
Idioma::~Idioma()
{

}
// Getters y Setters
string Idioma::getNombre(){ return this->Nombre; }

// Otros...
void Idioma::cursoEliminado(string nombreCurso){
    for(vector<Suscripcion *>::iterator it = this->colSuscripciones.begin(); it != this->colSuscripciones.end(); ++it){
        (*it)->notificarBaja(nombreCurso);
    }
}


// Para el Caso de Uso : [Suscribirse a Notificaciones]
void Idioma::agregar(Suscripcion* u){
    this->colSuscripciones.push_back(u);    
}





