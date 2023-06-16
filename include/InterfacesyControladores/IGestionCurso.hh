#ifndef I_GESTION_CURSO
#define I_GESTION_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "../DataTypes/DataCurso.hh"
#include "../DataTypes/DTCurso.hh"
#include "../DataTypes/DataConsultaCurso.hh"
#include "../DataTypes/InformacionCurso.hh"
#include "../DataTypes/InscripcionCurso.hh"
#include "../DataTypes/DataLeccion.hh"
#include "../DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class IGestionCurso
{
public:
    // Operaciones Para El Caso de Uso : [Alta de Curso]
    virtual set<string> getNicknamesProfesores() = 0;
    virtual void ingresarDataCurso(string profesor, DTCurso* curso) = 0;
    virtual set<string> getIdiomasProfesor() = 0;
    virtual void agregarIdiomaCurso(string idioma) = 0;
    virtual set<string> getNombreCursosHabilitados() = 0;
    virtual void ingresarCursosPrevios(set<string> previos) = 0;
    virtual void ingresarLeccionParaAlta(string tema, string objetivo) = 0;
    virtual void ingresarEjercicioParaAlta(DataEjercicio* ejercicio) = 0;
    virtual void confirmarLeccion() = 0;
    virtual void confirmarAltaCurso() = 0;
    // Operaciones Para El Caso de Uso : [Agregar Leccion]
    // virtual set<DataCurso *> getCursosNoHabilitados
    virtual void ingresarDatosLeccion(string cursoSeleccionado,string tema, string objetivo) = 0;
    virtual void ingresarEjercicio(DataEjercicio* ejercicio) = 0;
    virtual void altaLeccion() = 0;
    // Operaciones Para El Caso de Uso : [Agregar Ejercicio]
    virtual set<DataLeccion *> getLecciones(string cursoSeleccionado) = 0;
    virtual void agregarEjercicio(int leccionSeleccionada, DataEjercicio* ejercicio) = 0;
    // Operaciones Para El Caso de Uso : [Habilitar Curso]
    virtual set<InformacionCurso *> getCursosNoHabilitados() = 0;
    virtual bool habilitarCurso(string seleccionado) = 0;
    // Operaciones Para El Caso de Uso : [Eliminar Curso]
    virtual set<string> getNombreCursos() = 0;
    virtual void seleccionarCurso(string nombreCurso) = 0;
    virtual void bajarCurso(string nombreCurso) = 0;
    // Operaciones para el Caso de Uso : [Consultar Curso]
    //virtual set<string> getNombresCursos() = 0;
    virtual InscripcionCurso* getCurso(string seleccionado) = 0;
    //
    virtual ~IGestionCurso(){};
};

#endif