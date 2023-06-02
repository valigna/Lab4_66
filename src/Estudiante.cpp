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

set<string> Estudiante::obtenerCursosNoAprobados(){
    set<string> res;
    for(map<string,Incripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        if(it->second->getCursoAprobado() == false){
            string aux = it->second->darNombreCurso();
            res.insert(aux);
        }
    }
    return res;
}

set<DataEjercicio *> Estudiante::obtenerEjerciciosNoAprobados(string curso){
    for(map<string,Incripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        Curso * aux = it->second->getCurso();
        if(aux->igualCurso(curso)){
            return it->second->obtenerListaEjerciciosNoAprobadosIns();
        }
    }
}

void Estudiante::eliminarLinkE(string nombreCurso){
    this->colInscripciones.erase(nombreCurso); // Se elimina la inscripcion con nombreCurso
}