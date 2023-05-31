#include "../include/Usuario.hh"

set<string> Usuario::getIdiomasSuscritos(){
    set<string> res;
    for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it) {
        string idioma = it->darIdioma();
        res.insert(idioma);
    }
    return res;
}

set<string> Usuario::getCursosNoAprobados(){
    for(vector<Inscripcion *>::iterator it = this->colInscripcion.begin(); it != this->colInscripcion.end(); it++){
        if(verificarEstado(it)){
            string curso = it->
        }
    }
}


bool Usuario::esAlumno(){
    Estudiante* dummy = dynamic_cast<
}