#ifndef CONTROLADOR_CURSO
#define CONTROLADOR_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// Interfaces
#include "IGestionCurso.hh"
#include "IGestionIdiomas.hh"
class Suscripcion;
class ControladorUsuario;
// Conceptos Del Modelo De Dominio
#include "../Idioma.hh"
//#include "../Ejercicio.hh"
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
    //Memoria Para : [Alta de Curso]
    int idLeccion;
    int idEjercicio;
    DTCurso* seleccionado;
    string nickProfesor;
    string idiomaCurso;
    set<string> previos;
    string temaLeccion;
    string objLeccion;
    list<DataLeccion*> Lecciones;

    // Memoria para : [Agregar Leccion]
    set<DataEjercicio*> Ejs;
    
    // Memoria Para : [Agregar Ejercicio] (tambien usado en agregar Leccion)
    string nombreCurso;

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
    void ingresarLeccionParaAlta(string tema, string objetivo);
    void ingresarEjercicioParaAlta(DataEjercicio* ejercicio);
    void confirmarLeccion();
    void confirmarAltaCurso();
    // Para El Caso de Uso : [Agregar Leccion]
    void ingresarDatosLeccion(string cursoSeleccionado,string tema, string objetivo);
    void ingresarEjercicio(DataEjercicio* ejercicio);
    void altaLeccion();
    // Para El Caso de Uso : [Agregar Ejercicio]
    list<DataLeccion *> getLecciones(string cursoSeleccionado);
    void agregarEjercicio(int leccionSeleccionada, DataEjercicio* ejercicio);
    // Para el Caso de Uso : [Habilitar Curso]
    set<InformacionCurso *> getCursosNoHabilitados();
    bool habilitarCurso(string seleccionado);
    // Operaciones Para el Caso de Uso: [Eliminar Curso]
    set<string> getNombreCursos();
    void seleccionarCurso(string nombreCurso);
    void bajarCurso(string nombreCurso);
    // Para el Caso de Uso : [Consultar Curso]
    InscripcionCurso* getCurso(string seleccionado);
    DataConsultaCurso* obtenerDataCursoSeleccionado(string curso);
    // Para el caso de uso: [Inscribirse a curso]
    Curso* encontrarCurso(string curso);
    set<InformacionCurso *> darCursosHabilitadosDisponibles(set<string> nombresCursosAprobados, set<string> nombresCursosInscriptos);
    // Para el Caso de Uso : [Realizar Ejercicio]
    string obtenerLetra(string nomC, int ejercicio);
    DataEjercicio* encontrarEjercicio(string nomC, int ejercicio);
    // Para el Caso de Uso : [Consultar Estadisticas]
    set<string> darNombreCursos();
    InformacionCurso* darInformacionCurso(string nombreCurso);
    // Para el Caso de Uso : [Suscribirse a Notificaciones]
    void agregarObservador(Suscripcion *u, set<string> idiomas);
    // Para el Caso de Uso : [Eliminar Suscripciones]
    void quitarObservador(Suscripcion *s, set<string> seleccionados);
};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "Suscripcion.hh"
#include "../Curso.hh"
#include "ControladorUsuario.hh"
/* ------------------------------------------------------------------------------------------------------ */


#endif