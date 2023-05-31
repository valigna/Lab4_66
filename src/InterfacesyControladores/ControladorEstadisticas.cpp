#include "../../include/InterfacesyControladores/ControladorEstadisticas.hh"

set<string> ControladorEstadisticas::getNicksEstudiantes(){
    set<string> res;
    
    // Obtengo la instancia de Controlador Usuario y le pido lista la lista de nicks de alumnos...
    ControladorUsuario *cu;
    cu = ControladorUsuario::getInstancia();
    res = cu->darNicksEstudiantes();

    return res;
}

set<InfoCursoEst *> ControladorEstadisticas::listarCursosEstudiante(string nickEstudiante) {
    set<InfoCursoEst> res;

    // Obtengo la instancia de Controlador Usuario
    ControladorUsuario *cu;
    cu = ControladoUsuario::getInstancia();
    
    res = cu->darInfoCursoEst(nickEstudiante);
    return res;
}

set<string> ControladorEstadisticas::getNicksProfesores(){
    set<string> res;

    // Obtengo la instancia de Controlador Usuario y le pido la lista de nicks de profesores...
    ControladorUsuario *cu;
    cu = ControladorUsuario::getInstancia();
    res = cu->darNicksProfesores();

    return res;
}

set<InfoCursoProf *> ControladorEstadisticas::listarCursosPropuestos(string nickProfesor){
    set<InfoCursoProf> res;

    // Obtengo la instancia de Controlador Usuario
    ControladorUsuario *cu;
    cu = ControladorUsuario::getInstancia();
    res = cu->darInfoCursoProf(nickProfesor);
}

set<string> ControladorEstadisticas::getCursos(){
    set<string> res;

    // Obtengo la instancia de Controlador Curso y le pido la lista de nombres de cursos...
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    res = cc->darNombreCursos();

    return res;
}

set<InformacionCurso *> ControladorEstadisticas::infoCurso(string nombreCurso){
    set<InformacionCurso *> res;

    // Obtengo la instancia de Controlador Curso y le delego la operacion...
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    res = cc->darInformacionCurso(nombreCurso);

    return res;
}