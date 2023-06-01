#include "../include/Usuario.hh"

// Constructores


// Destructor


// Getters y Setters
string Usuario::getNickname() {
    return this->Nickname;
}

// Otres...


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

// Estas dos funciones podrian quedar como una sola, al ser un Usuario Estudiante O Profesor; Pero por las dudas lo dejo asi por el momento...
bool Usuario::esEstudiante(){
    Estudiante* aux = dynamic_cast<Estudiante *>(&this);
    if (aux != NULL) {
        return true;
    } else {
        return false;
    }
}

bool Usuario::esProfesor(){
    Profesor* aux = dynamic_cast<Profesor *>(&this);
    if (aux != NULL) {
        return true;
    } else {
        return false;
    }
}