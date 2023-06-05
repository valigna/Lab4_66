#include "../include/Estudiante.hh"

// Constructores
Estudiante::Estudiante(string nick,string name, string pass, string desc, DataEstudiante* est) : Usuario(nick,name,pass,desc)
{
    this->PaisResidencia = est->getPaisResidencia();
    this->Nacimiento = est->getNacimiento();
}
// Destructor


// Getters y Setters
string Estudiante::getPaisResidencia(){ return this->PaisResidencia; }
DataFecha* Estudiante::getNacimiento(){ return this->Nacimiento; }

// Para el caso de Uso : [Realizar Ejercicio]

set<string> Estudiante::obtenerCursosNoAprobados(){
    set<string> res;
    for(set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        if(it->getCursoAprobado() == false){
            string aux = it->darNombreCurso();
            res.insert(aux);
        }
    }
    return res;
}

set<DataEjercicio *> Estudiante::obtenerEjerciciosNoAprobados(string curso){
    for(set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        Curso * aux = it->second->getCurso();
        if(aux->igualCurso(curso)){
            return it->second->obtenerListaEjerciciosNoAprobadosIns();
        }
    }
}

void Estudiante::hacerEjercicioT(int ejercicio, string sol){
    for(set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        Curso * aux = it->getCurso();
        if(aux->igualCurso(curso)){
            return it->revisarEjercicioT(ejercicio, sol);
        }
    }
}

// Otres
void Estudiante::eliminarLinkE(string nombreCurso){
    this->colInscripciones.erase(nombreCurso); // Se elimina la inscripcion con nombreCurso
}

// Para el Caso de Uso : [Consultar Estadisticas]
set<InfoCursoEst *> Estudiante::infCursosInscriptos()
{
    set<InfoCursoEst *> res;

    for (set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it) {
        string nomC = it->second->darNombreCurso();
        float av = it->second->darAvance();

        InfoCursoEst elem = new InfoCursoEst(nomC,av);
        res.insert(elem);
    }

    return res;
}