#include "../include/Idioma.hh"


// Constructores
Idioma::Idioma(string nombre)
{
    this->Nombre = nombre;
}

//Destructor
Idioma::~Idioma(){ }
// Getters y Setters
string Idioma::getNombre(){ return this->Nombre; }

// Otros...
void Idioma::cursoEliminado(string nombreCurso){
    for(vector<Suscripcion *>::iterator it = this->colSuscripciones.begin(); it != this->colSuscripciones.end(); ++it){
        (*it)->notificarBaja(nombreCurso);
    }
}


// Para el Caso de Uso : [Alta de Curso]
void Idioma::nuevoCurso(Curso* c)
{
    for(vector<Suscripcion *>::iterator it = this->colSuscripciones.begin(); it != this->colSuscripciones.end(); ++it )
    {
        (*it)->notificarAlta(this,c);
    }
}

// Para el Caso de Uso : [Suscribirse a Notificaciones]
void Idioma::agregar(Suscripcion* u){
    this->colSuscripciones.push_back(u);
}

// Para el Caso de Uso : [Eliminar Suscripciones]
void Idioma::eliminarUsuario(Suscripcion *s)
{
    vector<Suscripcion *>::iterator it = this->colSuscripciones.begin();
    while ((it != colSuscripciones.end()) && ((*it) != s))
    {
        ++it;
    }
    if (it != colSuscripciones.end())
    {
        this->colSuscripciones.erase(it);
    }
}