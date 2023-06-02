#include "../include/Notificacion.hh"


string Notificacion::darIdioma(){
    return this->MiIdioma->getNombre();
}


// Para el caso de uso : [Eliminar Curso]
bool Notificacion::presentaCurso(string nombreCurso){
    return (this->MiCurso->getNombre() == nombreCurso);
}
