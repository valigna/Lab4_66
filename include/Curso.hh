#ifndef CURSO
#define CURSO

/*Comentario para la coleccion de lecciones*/
    // El orden de las lecciones queda definido por el orden en el que el usuario las ingresa.
    // Podriamos simplemente agregar cada Leccion al final de una lista, quedando de esta forma con el orden pedido...

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// DataTypes
#include "DataTypes/DataCurso.hh"
#include "DataTypes/InformacionCurso.hh"
#include "DataTypes/InscripcionCurso.hh"
#include "DataTypes/DTCurso.hh"
#include "DataTypes/DataConsultaCurso.hh"
// Conceptos Del Modelo De Dominio
#include "Leccion.hh"
#include "Ejercicio.hh"
#include "Idioma.hh"
class Profesor;
class Inscripcion;
/* ------------------------------------------------------------------------------------------------------ */

class Curso
{
private:
    string Nombre;
    string Descricpion;
    difficulty Dificultad;
    bool Habilitado;
    // Para llevar registro de los id's
    int idLecciones;
    int idEjercicios;
    // PseudoAtributos...
    Profesor* profesor;
    Idioma* idioma;
    list<Leccion *> colLecciones;
    set<Inscripcion *> colInscripciones;
    set<Curso *> colPrevios;

public:
    // Constructores
    Curso(DTCurso* datosCurso);
    // Destructor
    ~Curso();
    // Getters y Setters
    string getNombre();
    string getDescripcion();
    difficulty getDificultad();
    bool getHabilitado();
    int getIdLecciones();
    int getIdEjercicios();
    //Profesor* getProfesor();
    //Idioma* getIdioma();

    void setHabilitado(bool hab);
    void setIdioma(Idioma* idioma);
    // Implementar en caso de ser necesario...
    // list<Leccion *> getcolLecciones();
    // set<Inscripcion *> getcolInscripciones();
    // set<Curso *> getcolPrevios();
    // Auxiliares
    string getNombreIdioma();
    int obtenerTotalLecciones();


    // DataTypes
    DataCurso* getDataCurso(); // Cambiar 'previos' a un set<string>
    DataConsultaCurso* getDataConsultaCurso();

    InformacionCurso* getInformacionCurso(bool conPromedio);
    InformacionCurso* getDatosCurso();

    InscripcionCurso* getInscripcionCurso(); // Es el DataTCurso...

    DTCurso* getDTCurso();
	
    set<DataLeccion *> darDataLecciones(bool conId);
    // Para el Caso de Uso : [Habilitar Curso]
    bool sePuedeHabilitar();
    
    // Para el Caso de Uso : [Realizar Ejercicio]
    bool igualCurso(string curso);
    set<int> obtenerListaEjerciciosCurso();
    DataEjercicio* buscarEjercicioEnCurso(int ejercicio);
    string buscarLetraEnCurso(int ejercicio);
    Ejercicio* encontrarEjercicioEnCurso(int ejercicio);
    Ejercicio* buscarEjercicioEnCursoT(int ejercicio, string sol);
    Ejercicio* buscarEjercicioEnCursoCP(int ejercicio, set<string> sol);
    Leccion* comprobarUltimaLeccion(int ejercicio);

    // Para el Case de Uso : [Agregar Leccion]
    DataEjercicio* obtenerIdEjercicio(DataEjercicio* ejercicio);
    void agregarLeccion(string tema, string obj, set<DataEjercicio*> ejs);
    // Para el Caso de Uso : [Agregar Ejercicio]
    void agregarEjercicio(int leccionSeleccionada,DataEjercicio* ejercicio);
    
    // Para el Caso de Uso : [Consultar Estadisticas]
    int obtenerTotalEjercicios();
    float darPromedio();
    InformacionCurso* infoCurso();


    // Para el caso de uso: [Inscribirse a curso]
    bool previosAprobados(set<string> nombresCursosAprobados);
    void crearLinkConInsc(Inscripcion *I);

    void agregarLeccion(Leccion* leccion);
    void ingresarPrevia(Curso* curso);
};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "Profesor.hh"
#include "Inscripcion.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif