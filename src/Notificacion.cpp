#include "../include/Notificacion.hh"

// Constructor
Notificacion::Notificacion(Idioma* i,Curso* c)
{
    this->MiIdioma = i;
    this->MiCurso = c;
}

// Destructor
Notificacion::~Notificacion(){ }

// Para el caso de uso : [Eliminar Curso]
bool Notificacion::presentaCurso(string nombreCurso){
    return (this->MiCurso->getNombre() == nombreCurso);
}

DataNotificacion* Notificacion::darData()
{
    DataNotificacion* res = new DataNotificacion(this->MiIdioma->getNombre(), this->MiCurso->getNombre());
    return res;
}
// Para el caso de uso: [Eliminar Suscripciones]
string Notificacion::darIdioma(){
    return this->MiIdioma->getNombre();
}