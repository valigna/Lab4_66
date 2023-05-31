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




