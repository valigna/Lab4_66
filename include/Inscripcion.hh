#ifndef INSCRIPCION
#define INSCRIPCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos del Modelo de Dominio
#include "Leccion.hh"
#include "Ejercicio.hh"
class Curso;
class Estudiante;
// DataTypes
#include "DataTypes/DataFecha.hh"
#include "DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Inscripcion
{
private:
    DataFecha* FechaInscripcion;
    bool CursoAprobado;
    // PseudoAtributos... 
    Estudiante *e;
    Curso *c;
    set<Ejercicio *> colEjAprobados;
    set<Leccion *> colLecAprobadas; // Cpz nos conviene cambiar a list...
public:
    // Constructores
    Inscripcion(Estudiante *est, string curso);
    // Destructor
    ~Inscripcion();

    // Getters y Setters
    DataFecha* getFechaInscripcion();
    bool getCursoAprobado();
    Curso* getCurso();
    int getUltimaLeccion();
    void setCursoAprobado(bool curso);

    // Funciones Auxiliares
    bool aproboLeccion(Leccion* lec);

    // Para el Caso de Uso : [Realizar Ejercicio]
    set<DataEjercicio *> obtenerListaEjerciciosNoAprobadosIns();
    bool noAprobado(int curso);
    bool revisarEjercicioT(int ejercicio, string sol);
    bool revisarEjercicioCP(int ejercicio, set<string> sol);

    // Para el Caso de Uso : [Consultar Estadisticas]
    string darNombreCurso();
    float darAvance();
    float darAvance(int cantEj);
    int cantEjAprobados();
};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "Estudiante.hh"
#include "Curso.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif