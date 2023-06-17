#include "../include/ControladorCurso.hh"

// Constructores

// Destructor

// Getters y Setters

// Implementacion del Patron de Disenio : Singleton
ControladorCurso* ControladorCurso::instancia = NULL;
ControladorCurso::ControladorCurso()
{

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
    map<string,Idioma *>::iterator it = this->colIdiomas.find(nombre);
    if (it != this->colIdiomas.end())
    {
        return it->second;
    } else
    {
        return NULL;
    }
}