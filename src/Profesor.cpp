#include "../include/Profesor.hh"

// Constructores

// Destructor

// Getters y Setters

// Otres
set<InfoCursoProf *> Profesor::darInfoCurso(){
    set<InfoCursoProf *> res; 
    for(map<sting,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it) {
        string nomC = (*it)->first;
        float prom = (*it)->second->darPromedio();

        InfoCursoProf *elem = new InfoCursoProf(nomC,prom);
        res.insert(elem);
    }
    return res;
}

void Profesor::eliminarLinkP(string nombreCurso){
    this->colCursos.erase(nombreCurso);
}