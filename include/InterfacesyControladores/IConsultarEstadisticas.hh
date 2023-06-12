#ifndef I_CONSULTAR_ESTADISTICAS
#define I_CONSULTAR_ESTADISTICAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "../DataTypes/InfoCurso.hh"
#include "../DataTypes/InformacionCurso.hh"
/* ------------------------------------------------------------------------------------------------------ */

class IConsultarEstadisticas
{
public:
    virtual set<string> getNicksEstudiantes() = 0;
    virtual set<InfoCurso *> listarCursosEstudiante(string nickEstudiante) = 0;
    virtual set<string> getNicksProfesores() = 0;
    virtual set<InfoCurso *> listarCursosPropuestos(string nickProfesor) = 0;
    virtual set<string> getNombresCursos() = 0;
    virtual InformacionCurso* infoCurso(string nombreCurso) = 0;

    virtual ~IConsultarEstadisticas(){};
};

#endif