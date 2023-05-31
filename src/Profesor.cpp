#include "../include/Profesor.hh"

// Constructores

// Destructor

// Getters y Setters

// Otres
set<InfoCursoProf *> Profesor::darInfoCurso(){
    set<InfoCursoProf *> res; 
    for(set<Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++ it) {
        string nomC = (*it)->getNombre();
        float prom = (*it)->darPromedio();

        InfoCursoProf *elem = new InfoCursoProf(nomC,prom);
        res.insert(elem);
    }
    return res;
}