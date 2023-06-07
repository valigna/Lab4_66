#ifndef CURSO
#define CURSO

/*Comentario para la coleccion de lecciones*/
    // El orden de las lecciones queda definido por el orden en el que el usuario las ingresa.
    // Podriamos simplemente agregar cada Leccion al final de una lista, quedando de esta forma con el orden pedido...

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Idioma.hh"

// Como la mayoria de las referencias circulares incluyen a curso, haremos los Forward Declarations en Curso...
class Profesor;
class Inscripcion;
class Leccion;
class Ejercicio;
/* ------------------------------------------------------------------------------------------------------ */

class Curso
{
private:
    string Nombre;
    string Descricpion;
    difficulty Dificultad;
    bool Habilitado;

    // PseudoAtributos...
    Profesor* Profesor;
    Idioma* Idioma;
    list<Leccion *> colLecciones;
    set<Inscripcion *> colInscripciones;
    set<Curso *> colPrevios;

public:
    // Constructores

    // Destructor
    ~Curso();

    // Getters y Setters
    string getNombre();
    string getDescripcion();
    difficulty getDificultad();
    bool getHabilitado();

    void setHabilitado(bool hab);

    // Para el Caso de Uso : [Habilitar Curso]
    bool sePuedeHabilitar();
    // Para el Caso de Uso : [Realizar Ejercicio]
    bool igualCurso(string curso);
    set<DatosEjercicio *> obtenerListaEjerciciosNoAprobadosCurso();
    string buscarLetraEnCurso(int ejercicio);
    Ejercicio* buscarEjercicioEnCursoT(int ejercicio, string sol);
    Ejercicio* buscarEjercicioEnCursoCP(int ejercicio, set<string> sol);
    Leccion* comprobarUltimaLeccion(int ejercicio);

    // Para el Caso de Uso : [Consultar Estadisticas]
    int obtenerTotalEjercicios();
    float darPromedio();
    InformacionCurso* infoCurso();

};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "Profesor.hh"
#include "Inscripcion.hh"
#include "Leccion.hh"
#include "Ejercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif