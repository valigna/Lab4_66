#include "../include/Notificacion.hh"


// Para el caso de uso: [Eliminar Suscripciones]
string Notificacion::darIdioma(){
    return this->MiIdioma->getNombre();
}


// Para el caso de uso : [Eliminar Curso]
bool Notificacion::presentaCurso(string nombreCurso){
    return (this->MiCurso->getNombre() == nombreCurso);
}
