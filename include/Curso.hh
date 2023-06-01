#ifndef CURSO
#define CURSO

// Includes...
#include "Utils.hh"

class Curso
{
private:
    string Nombre;
    string Descricpion;

    // PseudoAtributos...
    Profesor *profesor;
    Idioma *idioma;
    /*Comentario para la coleccion de lecciones*/
    // El orden de las lecciones queda definido por el orden en el que el usuario las ingresa.
    // Podriamos simplemente agregar cada Leccion al final de una lista, quedando de esta forma con el orden pedido...
    list<Leccion *> colLecciones;
    map<string,Inscricpion *> colInscripciones;
    set<Curso *> colPrevios;

public:
    // Constructores

    // Destructor

    // Getters y Setters
    string getNombre();
    // Otres
    int obtenerTotalEjercicios();
    float darPromedio();
    InformacionCurso* infoCurso();

}