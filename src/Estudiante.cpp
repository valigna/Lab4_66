#include "../include/Estudiante.hh"

// Constructores
/* Estudiante::Estudiante(string nick,string name, string pass, string desc, DataEstudiante* est) : Usuario(nick,name,pass,desc)
{
    this->PaisResidencia = est->getPaisResidencia();
    this->Nacimiento = est->getNacimiento();
} */ // Por ahora decidi no borrarlo, seguramente lo saque para la version final (M.I)

Estudiante::Estudiante(DataUsuario* datos) : Usuario(datos->getNickname(),datos->getNombre(),datos->getContrasenia(),datos->getDescripcion())
{
    DataEstudiante* est = (DataEstudiante*) datos;
    this->PaisResidencia = est->getPaisResidencia();
    this->Nacimiento = est->getNacimiento();
}
// Destructor


// Getters y Setters
string Estudiante::getPaisResidencia(){ return this->PaisResidencia; }
DataFecha* Estudiante::getNacimiento(){ return this->Nacimiento; }

//Auxiliares
set<string> Estudiante::obtenerCursosAprobados(){
    set<string> res;
    for (set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it) {
        if (it->getCursoAprobado()){
            res.insert(it->darNombrCurso());
        }
    }
    return res;
}

set<string> Estudiante::obtenerCursosInscriptos(){
    set<string> res;
    for (set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it) {
        res.insert(it->darNombrCurso());
    }
    return res;
}
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

set<DatosEjercicio *> Estudiante::obtenerEjerciciosNoAprobados(string curso){
    for(set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        Curso * aux = it->getCurso();
        if(aux->igualCurso(curso)){
            return it->obtenerListaEjerciciosNoAprobadosIns();
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

void Estudiante::hacerEjercicioCP(int ejercicio, set<string> sol){
    for(set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        Curso * aux = it->getCurso();
        if(aux->igualCurso(curso)){
            return it->revisarEjercicioCP(ejercicio, sol);
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

// Para el caso de uso: [Inscribirse a curso]
set<DatosCurso *> Estudiante::darCursosDisponibles();{
    set<DatosCurso *> res;
    set<string> nombresCursosDisponibles;
    set<string> nombresCursosAprobados = this->obtenerCursosAprobados();
    set<string> nombresCursosInscriptos = this->obtenerCursosInscriptos();
    //Obtener instancia de controladorCurso
    //Obtener lista de todos los cursos habilitados, sacarle los inscriptos y los que tengan previas sin aprobar
    //con todos esos nombres, encontrar los cursos y armar los datatypes en la lista
    return res;
}