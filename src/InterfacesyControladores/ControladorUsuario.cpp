#include "../../include/InterfacesyControladores/ControladorUsuario.hh"

// Constructores

// Destructor

// Getters y Setters

// Otros

void ControladorUsuario::ingresarUsuario(DataUsuario Datos) {this->Datos = Datos;}

// Set : Unordered set (STL)
set<string> ControladorUsuario::getIdiomas(){
    // Paso 1:
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    // Paso 2:
    set<string> idiomas;
    idiomas = cc->darIdiomas();
    
    return idiomas;
}


set<string> ControladorUsuario::idiomasSuscritos(string nickname){
    return this->colUsuarios[nickname]->getIdiomasSuscritos();
}

set<string> ControladorUsuario::getCursosInscriptosNoAprobados(string nickname){
    return this->colUsuarios[nickname]->getCursosNoAprobados();
}

set<string> ControladorUsuario::darNicksEstudiantes(){
    set<string> res;
    
    // Recorremos la coleccion de Usuarios del Sistema
    for (map<string,Usuario *>::iterator it = this->colUsuarios.begin(); it != this->colUsuarios.end();++it) {
        bool estudiante = it->second->esEstudiante();
        if (estudiante) {res.insert(it->second->getNickname());}
    }
    
    return res;
}

set<InfoCursoEst *> ControladorUsuario::darInfoCursoEst(string nickEstudiante){
    set<InfoCursoEst *> res;
    
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickEstudiante);
    res = it->second->infCursosInscriptos();
    
    return res;
}

set<string> ControladorUsuario::darNicksProfesores(){
    set<string> res;
    
    // Recorremos la coleccion de Usuarios del Sistema
    for (map<string,Usuario *>::iterator it = this->colUsuarios.begin(); it != this->colUsuarios.end();++it) {
        bool profesor = it->second->esProfesor();
        if (profesor) {res.insert(it->second->getNickname());}
    }
    
    return res;
}

set<InfoCursoProf *> ControladorUsuario::darInfoCursoProrf(string nickProfesor){
    set<InfoCursoProf *> res;
    
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickProfesor);
    res = it->second->darInfoCurso();
    
    return res;
}
set<string> ControladorUsuario::getCursosInscriptosNoAporbados(string nickname){
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->obtenerCursosNoAprobados();
}

set<DataEjercicio *> ControladorUsuario::getEjerciciosNoAprobados(string curso){
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->obtenerEjerciciosNoAprobados(string curso);
}

string ControladorUsuario::getProblema(int ejercicio){
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    return cc->obtenerLetra(string nomC, int ejercicio);
}

set<string> ControladorUsuario::idiomasNoSuscritos(string nickname) {
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->darIdiomasNoSuscritos();
}


