#ifndef CURSO
#define CURSO

/*Comentario para la coleccion de lecciones*/
    // El orden de las lecciones queda definido por el orden en el que el usuario las ingresa.
    // Podriamos simplemente agregar cada Leccion al final de una lista, quedando de esta forma con el orden pedido...

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../../include/Utils.hh"
#include "Idioma.hh"
#include "Profesor.hh"
#include "Leccion.hh"
#include "Inscripcion.hh"
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

#endif