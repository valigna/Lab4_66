#include "../include/Estudiante.hh"

// Constructores

// Destructores


// Getters y Setters


// Otres

set<InfoCursoEst> Estudiante::infCursosInscriptos(){
    set<InfoCursoEst> res;

    for (map<string,Incripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it) {
        string nomC = it->second->darNombreCurso();
        float av = it->second->darAvance();

        InfoCursoEst elem = new InfoCursoEst(nomC,av);
        res.insert(elem);
    }

    return res;
}