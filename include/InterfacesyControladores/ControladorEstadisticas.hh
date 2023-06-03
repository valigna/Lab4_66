/*
    Cambios que hice con respecto al Lab3 (Martin Idiart)
        - La operacion getEstudiantes():set(string) pasa a ser getNicksEstudiantes():set(string)
        - IDEM con getProfesores
        - La operacion getCursos():set(string) pasa a ser getNombresCursos():set(string)

        Todos estos cambios se hicieron para que los nombres de las operaciones dejen en claro que es lo que se retrona
*/

#ifndef CONTROLADOR_ESTADISTICAS
#define CONTROLADOR_ESTADISTICAS

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "IConsultarEstadisticas.hh"
// DataTypes
#include "../DataTypes/InfoCursoEst.hh"
#include "../DataTypes/InfoCursoProf.hh"
#include "../DataTypes/InformacionCurso.hh"
/* ------------------------------------------------------------------------------------------------------ */

class ControladorEstadisticas : public IConsultarEstadisticas
{
public:
    set<string> getNicksEstudiantes();
    set<InfoCursoEst *> listarCursosEstudiante(string nickEstudiante);
    set<string> getNicksProfesores();
    set<InfoCursoProf *> listarCursosPropuestos(string nickProfesor);
    set<string> getNombresCursos();
    set<InformacionCurso *> infoCurso(string nombreCurso);
};

#endif