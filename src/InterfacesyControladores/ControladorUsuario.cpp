#include "../../include/InterfacesyControladores/ControladorUsuario.hh"

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

set<string> ControladorUsuario::darNicksAlumnos(){
    set<string> res;
    
    // Recorremos la coleccion de Usuarios del Sistema
    for (map<string,Usuario *>::iterator it = this->colUsuarios.begin(); it != this->colUsuarios.end();++it) {
        bool alumno = it->second->esAlumno();
    }
    

}


/*
  // show content:
  for (std::map<string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
*/