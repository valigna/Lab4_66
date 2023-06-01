#ifndef I_GESTION_CURSO
#define I_GESTION_CURSO

// Includes...
#include "../Utils.hh"

class IGestionCurso
{
public:
    virtual set<string> getNicknamesProfesores() = 0;
    virtual void ingresarDataCurso(string profesor, DTCurso curso) = 0;
    virtual set<string> getIdiomasProfesor() = 0;
    virtual void agregarIdiomaCurso(string idioma) = 0;
    virtual set<string> getNombreCursosHabilitados() = 0;
    virtual void ingresarCursosPrevios(set<string> previos) = 0;
    virtual void ingresarLeccionParaAlta(DTLeccion leccion) = 0;
    virtual void ingresarEjercicioParaAlta(DTEjercicio ejercicio) = 0;
    virtual void confirmarAltaCurso() = 0;
    virtual set<string> getNombreCursos() = 0;
    virtual void seleccionarCurso(string nombreCurso) = 0;
    virtual void bajarCurso() = 0;

    virtual ~IGestionCurso();
}
#endif