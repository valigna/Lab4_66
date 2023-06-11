#ifndef I_GESTION_CURSO
#define I_GESTION_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "../DataTypes/DataCurso.hh"
#include "../DataTypes/DTCurso.hh"
#include "../DataTypes/InformacionCurso.hh"
#include "../DataTypes/InscripcionCurso.hh"
#include "../DataTypes/DataLeccion.hh"
#include "../DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class IGestionCurso
{
public:
    // Operaciones De Sistema De : [Habilitar Curso]
    virtual set<InformacionCurso *> getCursosNoHabilitados() = 0;
    virtual bool habilitarCurso(string seleccionado) = 0;
    //
    virtual set<string> getNicknamesProfesores() = 0;
    virtual void ingresarDataCurso(string profesor, DTCurso* curso) = 0;
    virtual set<string> getIdiomasProfesor() = 0;
    virtual void agregarIdiomaCurso(string idioma) = 0;
    virtual set<string> getNombreCursosHabilitados() = 0;
    virtual void ingresarCursosPrevios(set<string> previos) = 0;
    virtual void ingresarLeccionParaAlta(DataLeccion* leccion) = 0;
    virtual void ingresarEjercicioParaAlta(DataEjercicio* ejercicio) = 0;
    virtual void confirmarAltaCurso() = 0;
    virtual set<string> getNombreCursos() = 0;
    virtual void seleccionarCurso(string nombreCurso) = 0;
    virtual void bajarCurso() = 0;

    virtual ~IGestionCurso();
};

#endif