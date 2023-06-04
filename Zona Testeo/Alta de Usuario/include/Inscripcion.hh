#ifndef INSCRIPCION
#define INSCRIPCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../../include/Utils.hh"
#include "Leccion.hh"
#include "Ejercicio.hh"
#include "Estudiante.hh"
#include "Curso.hh"
// DataTypes
#include "../../../include/DataTypes/DataEjercicio.hh"
#include "../../../include/DataTypes/DataFecha.hh"
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
    set<Leccion *> colLecAprobadas;
public:
    // Constructores

    // Destructor
    ~Inscripcion();
    // Getters y Setters
};
#endif