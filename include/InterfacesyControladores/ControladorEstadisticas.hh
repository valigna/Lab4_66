/*
    Cambios que hice con respecto al Lab3 (Martin Idiart)
        - La operacion getEstudiantes():set(string) pasa a ser getNicksEstudiantes():set(string)

*/

#ifndef CONTROLADOR_ESTADISTICAS
#define CONTROLADOR_ESTADISTICAS

// Includes...
#include "../Utils.hh"
// Creo que me falta el DT InfoCursoEst


class ControladorEstadisticas
{
private:

public:
    set<string> getNicksEstudiantes();
    set<InfoCursoEst *> listarCursosEstudiante(string nickEstudiante);
    set<string> getNicksProfesores();
    set<InfoCursoProf *> listarCursosPropuestos(string nickProfesor);
    set<string> getCursos();
    set<InformacionCurso *> infoCurso(string nombreCurso);
}

#endif