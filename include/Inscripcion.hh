#ifndef INSCRIPCION
#define INSCRIPCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Leccion.hh"
#include "Ejercicio.hh"
#include "Estudiante.hh"
#include "Curso.hh"
// DataTypes
#include "DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Inscripcion
{
private:
    Fecha FechaInscripcion;
    bool CursoAprobado;
    
    // PseudoAtributos...
    Estudiante *e;
    Curso *c;
    set<Ejercicio *> colEjAprobados;
    set<Leccion *> colLecAprobadas;
public:
    // Constructores

    // Destructor
    ~Inscripcion();
    // Getters y Setters

    // Para el Caso de Uso : [Realizar Ejercicio]
    bool getCursoAprobado();
    Curso* getCurso();
    set<DataEjercicio *> obtenerListaEjerciciosNoAprobadosIns();

    // Para el Caso de Uso : [Consultar Estadisticas]
    string darNombreCurso();
    float darAvance();
    float darAvance(int cantEj);
    int cantEjAprobados();
}
#endif