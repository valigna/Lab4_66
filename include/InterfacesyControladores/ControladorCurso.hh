#ifndef CONTROLADOR_CURSO
#define CONTROLADOR_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "../Idioma.hh"
#include "../Curso.hh"
// Interfaces
#include "IGestionCurso.hh"
#include "IGestionIdiomas.hh"
// DataTypes
#include "../DataTypes/DataTraduccion.hh"
#include "../DataTypes/DataCompletarPalabras.hh"
#include "../DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class ControladorCurso : public IGestionCurso, public IGestionIdiomas
{
private:
    // Implementacion del Patron de Disenio : Singleton
    static ControladorCurso* instancia;
    ControladorCurso();

    map<string,Idioma *> colIdiomas;
    map<string,Curso *> colCursos;
    
    // Para memoria de que caso de uso??
    string nombreCurso;

    //Memoria Para [Alta de Curso]
    DTCurso* Curso;
    string Profesor;
    set<string> previos;
    DataLeccion* Leccion;
    DataEjercicio* Ejercicio;

public:
    // Destructor
    ~ControladorCurso();
    // Getters y Setters
    
    // Implementacion del Patron de Disenio : Singleton
    static ControladorCurso* getInstancia();

    // Otros

    void ingresarDataCurso(string profesor,DTCurso* curso);

    // Para el Caso de Uso : [Alta de Usuario]
    Idioma* obtenerIdioma(string nombre);

    // Para el Caso de Uso : [Alta de idioma]
    bool altaIdioma(string nombre);
    set<string> getIdiomas();

    // Para el Caso de Uso : [Alta de Curso]
    void ingresarDataCurso(string profesor, DTCurso* curso);
    void ingresarCursosPrevios(set<string> previos);
    void ingresarLeccionParaAlta(DataLeccion* leccion);
    void ingresarEjercicioParaAlta(DataEjercicio* ejercicio);

    // Para el Caso de Uso : [Habilitar Curso]
    set<InformacionCurso *> getCursosNoHabilitados();
    bool habilitarCurso(string seleccionado);

    // Para el Caso de Uso : [Consulta de Curso]
    DataCurso* obtenerDataCursoSeleccionado(string curso);
    
    // Para el Caso de Uso : [Realizar Ejercicio]
    string obtenerLetra(string nomC, int ejercicio);

    // Operaciones de: [eliminar curso]
    set<string> getNombreCursos();
    void seleccionarCurso(string nombreCurso);
    void bajarCurso();

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<string> darNombreCursos();
    InformacionCurso* darInformacionCurso(string nombreCurso);

    // Para el Caso de Uso : [Suscribirse a Notificaciones]
    void agregarObservador(Suscripcion *u, set<string> idiomas);

    // Para el caso de uso: [Inscribirse a curso]
    // Obtiene una lista de todos los cursos habilitados, sacandole los inscriptos y los que tengan previas sin aprobar...
    set<InformacionCurso *> darCursosHabilitadosDisponibles(set<string> nombresCursosAprobados, set<string> nombresCursosInscriptos);

    // Sin definir o eliminados ?
    set<string> getNicknamesProfesores();
    void ingresarDataCurso(string profesor, InscripcionCurso* curso);
    set<string> getIdiomasProfesor();
    void agregarIdiomaCurso(string idioma);
    set<string> getNombreCursosHabilitados();
    void ingresarCursosPrevios(set<string> previos);
    void ingresarLeccionParaAlta(DataLeccion* leccion);
    void ingresarEjercicioParaAlta(DataEjercicio* ejercicio);
    void confirmarAltaCurso();
};

#endif