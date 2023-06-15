// Es el DataTCurso...
#ifndef INSCRIPCION_CURSO 
#define INSCRIPCION_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "DataLeccion.hh"
#include "DataInscripto.hh"
/* ------------------------------------------------------------------------------------------------------ */

class InscripcionCurso
{
private:
    string Nombre;
    string Descripcion;
    difficulty Dificultad;
    string Idioma;
    bool Habilitado;
    set<DataLeccion *> Lecciones;
    set<DataInscripto *> Estudiantes;
public:
    // Constructores
    InscripcionCurso(string name, string desc, difficulty diff, string idi, bool hab, set<DataLeccion *> leccs, set<DataInscripto *> ests);
    // Destructor
    ~InscripcionCurso();
    // Getters
    string getNombre();
    string getDescripcion();
    difficulty getDificultad();
    bool getHabilitado();
    set<DataLeccion *> getLecciones();
    set<DataInscripto *> getEstudiantes();
};

#endif