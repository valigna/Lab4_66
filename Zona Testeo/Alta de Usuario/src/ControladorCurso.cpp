#include "../include/ControladorCurso.hh"

// Constructores

// Destructor

// Getters y Setters

// Implementacion del Patron de Disenio : Singleton
ControladorCurso* ControladorCurso::instancia = NULL;
ControladorCurso::ControladorCurso()
{
    this->colIdiomas = new map<string,Idioma *>;
    this->colCursos = new map<string,Curso *>;
}

ControladorCurso* ControladorCurso::getInstancia()
{
    if (ControladorCurso::instancia == NULL)
    {
        ControladorCurso::instancia = new ControladorCurso();
    }
    return ControladorCurso::instancia;
}

// Para el Caso de Uso : [Alta de Usuario]
Idioma* ControladorCurso::obtenerIdioma(string nombre)
{
    Idioma* res;
    res = this->colIdiomas.find(nombre);
    if (res != this->colIdiomas.end())
    {
        return res;
    } else
    {
        return NULL;
    }
}