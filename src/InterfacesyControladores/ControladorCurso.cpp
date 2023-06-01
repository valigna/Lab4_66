#include "../../include/InterfacesyControladores/ControladorCurso.hh"

//(no se si es op de sistema o no)
set<string> darIdiomas(){
    for (auto& x: this->colIdiomas) {
        // 
    }
}

//Operaciones de sistema
set<string> ControladorCurso::getNombreCursos(){
    set<string> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it) {
        res.insert(it->first);
    }
    return res;
}

void ControladorCurso::seleccionarCurso(string nombreCurso){
    this->nombreCurso = nombreCurso;
}

set<string> ControladorCurso::darNombreCursos(){
    set<string> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end();++it) {
        string nomC = (*it)->getNombre();
        res.insert(nomC);
    }
    return res;
}

//no deberia ser ControladorCurso::dar...
InformacionCurso Curso::darInformacionCurso(string nombreCurso){
    map<string,Curso *>::iterator it = this->colCursos.find(nombreCurso);
    InformacionCurso res = it->second->infoCurso();
}

void ControladorCurso::bajarCurso(){
    Curso C = this->colCursos[this->nombreCurso];
    this->colCursos.erase(this->nombreCurso); // Se saca el curso de la coleccion

    //Se deberia llamar al destructor directamente o primero hacer todo y que el destructor solo borre el curso en si??
}

string ControladorCurso::obtenerLetra(string nomC, int ejercicio){
    map<string,Curso *>::iterator it = this->colCursos.find(nomC);
    return it->buscarLetraEnCurso(int ejercicio);
}





