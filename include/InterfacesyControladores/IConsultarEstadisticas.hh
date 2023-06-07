#ifndef ICONSULTAR_ESTADISTICAS
#define ICONSULTAR_ESTADISTICAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "../DataTypes/InfoCursoEst.hh"
#include "../DataTypes/InfoCursoProf.hh"
#include "../DataTypes/InformacionCurso.hh"
/* ------------------------------------------------------------------------------------------------------ */

class IConsultarEstadisticas
{
public:
    virtual set<string> getNicksEstudiantes() = 0;
    virtual set<InfoCursoEst *> listarCursosEstudiante(string nickEstudiante) = 0;
    virtual set<string> getNicksProfesores() = 0;
    virtual set<InfoCursoProf *> listarCursosPropuestos(string nickProfesor) = 0;
    virtual set<string> getCursos() = 0;
    virtual set<InformacionCurso *> infoCurso(string nombreCurso) = 0;

    virtual ~IConsultarEstadisticas();
};

#endif