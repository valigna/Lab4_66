#ifndef CONTROLADOR_CURSO
#define CONTROLADOR_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// Interfaces
#include "IGestionCurso.hh"
#include "IGestionIdiomas.hh"
class Suscripcion;
// Conceptos Del Modelo De Dominio
#include "../Idioma.hh"
class Curso;
// DataTypes
#include "../DataTypes/DataTraduccion.hh"
#include "../DataTypes/DataCompletarPalabras.hh"
#include "../DataTypes/DataEjercicio.hh"
#include "../DataTypes/DataConsultaCurso.hh"
/* ------------------------------------------------------------------------------------------------------ */

class ControladorCurso : public IGestionCurso, public IGestionIdiomas
{
private:
    // Implementacion del Patron de Disenio : Singleton
    static ControladorCurso* instancia;
    ControladorCurso();
    // Colecciones
    map<string,Idioma *> colIdiomas;
    map<string,Curso *> colCursos;
    // Para memoria de que caso de uso??
    string nombreCurso;
    //Memoria Para : [Alta de Curso]
    DTCurso* seleccionado;
    string Profesor;
    set<string> previos;
    DataLeccion* Leccion;
    DataEjercicio* Ejercicio;

public:
    // Destructor
    ~ControladorCurso();
    // Implementacion del Patron de Disenio : Singleton
    static ControladorCurso* getInstancia();
    // Getters
    Idioma* darIdiomaEnColeccion(string nombre);
    // Para el Caso de Uso : [Alta de Usuario]
    Idioma* obtenerIdioma(string nombre);
    // Para el Caso de Uso : [Alta de idioma]
    bool altaIdioma(string nombre);
    // Para el Caso de Uso : [Consultar Idiomas]
    set<string> getIdiomas();
    // Para el Caso de Uso : [Alta de Curso]
    set<string> getNicknamesProfesores();
    void ingresarDataCurso(string profesor, DTCurso* curso);
    set<string> getIdiomasProfesor();
    void agregarIdiomaCurso(string idioma);
    set<string> getNombreCursosHabilitados();
    void ingresarCursosPrevios(set<string> previos);
    void ingresarLeccionParaAlta(DataLeccion* leccion);
    void ingresarEjercicioParaAlta(DataEjercicio* ejercicio);
    void confirmarAltaCurso();
    // Para El Caso de Uso : [Agregar Leccion]
    void ingresarDatosLeccion(string cursoSeleccionado,string tema, string objetivo);
    void ingresarEjercicio(DataEjercicio* ejercicio);
    void altaLeccion();
    // Para El Caso de Uso : [Agregar Ejercicio]
    set<DataLeccion *> getLecciones(string cursoSeleccionado);
    void agregarEjercicio(int leccionSeleccionada, DataEjercicio* ejercicio);
    // Para el Caso de Uso : [Habilitar Curso]
    set<InformacionCurso *> getCursosNoHabilitados();
    bool habilitarCurso(string seleccionado);
    // Operaciones Para el Caso de Uso: [Eliminar Curso]
    set<string> getNombreCursos();
    void seleccionarCurso(string nombreCurso);
    void bajarCurso();
    // Para el Caso de Uso : [Consultar Curso]
    InscripcionCurso* getCurso(string seleccionado);
    DataConsultaCurso* obtenerDataCursoSeleccionado(string curso);
    // Para el caso de uso: [Inscribirse a curso]
    set<InscripcionCurso *> getCursosDisponibles(string nickname);
    Curso* encontrarCurso(string curso); // No entiendo el error : (Tenian un atributo llamado Curso, generando un conflicto...)
    void inscribirseACurso(string nickname, string curso);
    // Obtiene una lista de todos los cursos habilitados, sacandole los inscriptos y los que tengan previas sin aprobar...
    set<InformacionCurso *> darCursosHabilitadosDisponibles(set<string> nombresCursosAprobados, set<string> nombresCursosInscriptos);
    // Para el Caso de Uso : [Realizar Ejercicio]
    string obtenerLetra(string nomC, int ejercicio);
    // Para el Caso de Uso : [Consultar Estadisticas]
    set<string> darNombreCursos();
    InformacionCurso* darInformacionCurso(string nombreCurso);
    // Para el Caso de Uso : [Suscribirse a Notificaciones]
    void agregarObservador(Suscripcion *u, set<string> idiomas);
};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "Suscripcion.hh"
#include "../Curso.hh"
/* ------------------------------------------------------------------------------------------------------ */


#endif