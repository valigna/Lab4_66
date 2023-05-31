#ifndef I_CONTROLADOR_ESTADISTICAS
#define I_CONTROLADOR_ESTADISTICAS

// Includes...
#include "../Utils.hh"

class IControladorEstadisticas
{
public:
    virtual set<string> getNicksEstudiantes() = 0;
    virtual set<InfoCursoEst *> listarCursosEstudiante(string nickEstudiante) = 0;
    virtual set<string> getNicksProfesores() = 0;
    virtual set<InfoCursoProf *> listarCursosPropuestos(string nickProfesor) = 0;
    virtual set<string> getCursos() = 0;
    virtual set<InformacionCurso *> infoCurso(string nombreCurso) = 0;

    virtual ~IControladorEstadisticas();
}

#endif