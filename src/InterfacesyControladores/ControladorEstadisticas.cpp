/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../include/InterfacesyControladores/ControladorEstadisticas.hh"
// Dependencias
#include  "../../include/InterfacesyControladores/ControladorUsuario.hh"
#include "../../include/InterfacesyControladores/ControladorCurso.hh"

/* ------------------------------------------------------------------------------------------------------ */

set<string> ControladorEstadisticas::getNicksEstudiantes()
{
    set<string> res;
    
    // Obtengo la instancia de Controlador Usuario y le pido la lista de nicks de alumnos...
    ControladorUsuario* cu = ControladorUsuario::getInstancia();
    res = cu->darNicksEstudiantes();

    return res;
}

set<InfoCurso *> ControladorEstadisticas::listarCursosEstudiante(string nickEstudiante) 
{
    set<InfoCurso *> res;

    // Obtengo la instancia de Controlador Usuario
    ControladorUsuario* cu = ControladorUsuario::getInstancia();
    res = cu->darInfoCursos(nickEstudiante);

    return res;

}

set<string> ControladorEstadisticas::getNicksProfesores(){
    set<string> res;

    // Obtengo la instancia de Controlador Usuario y le pido la lista de nicks de profesores...
    ControladorUsuario *cu = ControladorUsuario::getInstancia();
    res = cu->darNicksProfesores();

    return res;
}

set<InfoCurso *> ControladorEstadisticas::listarCursosPropuestos(string nickProfesor)
{
    set<InfoCurso *> res;

    // Obtengo la instancia de Controlador Usuario
    ControladorUsuario* cu = ControladorUsuario::getInstancia();
    res = cu->darInfoCursos(nickProfesor);

    return res;
}

set<string> ControladorEstadisticas::getNombresCursos(){
    set<string> res;

    // Obtengo la instancia de Controlador Curso y le pido la lista de nombres de cursos...
    ControladorCurso* cc = ControladorCurso::getInstancia();
    res = cc->darNombreCursos();

    return res;
}

InformacionCurso* ControladorEstadisticas::infoCurso(string nombreCurso)
{
    // Obtengo la instancia de Controlador Curso y le delego la operacion...
    ControladorCurso* cc = ControladorCurso::getInstancia();
    InformacionCurso* res = cc->darInformacionCurso(nombreCurso);

    return res;
}