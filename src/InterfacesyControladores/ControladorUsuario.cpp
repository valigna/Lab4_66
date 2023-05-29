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