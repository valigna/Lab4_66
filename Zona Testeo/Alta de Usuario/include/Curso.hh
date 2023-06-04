#ifndef CURSO
#define CURSO

/*Comentario para la coleccion de lecciones*/
    // El orden de las lecciones queda definido por el orden en el que el usuario las ingresa.
    // Podriamos simplemente agregar cada Leccion al final de una lista, quedando de esta forma con el orden pedido...

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../../include/Utils.hh"
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

    // PseudoAtributos...
    Profesor *profesor;
    Idioma *idioma;
    list<Leccion *> colLecciones;
    set<Inscripcion *> colInscripciones;
    set<Curso *> colPrevios;

public:
    // Constructores

    // Getters y Setters
    string getNombre();

};

/* ---------------------------------------- Forward Declarations ---------------------------------------- */
#include "Profesor.hh"
#include "Inscripcion.hh"
#include "Leccion.hh"
#include "Ejercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif