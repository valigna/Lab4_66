#ifndef CONTROLADOR_CURSO
#define CONTROLADOR_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../../include/Utils.hh"
#include "Idioma.hh"
#include "Curso.hh"
/* ------------------------------------------------------------------------------------------------------ */

class ControladorCurso
{
private:
    // Implementacion del Patron de Disenio : Singleton
    static ControladorCurso* instancia;
    ControladorCurso();

    map<string,Idioma *> colIdiomas;
    map<string,Curso *> colCursos;

public:
    // Destructor
    ~ControladorCurso();
    
    // Implementacion del Patron de Disenio : Singleton
    static ControladorCurso* getInstancia();

    // Para el Caso de Uso : [Alta de Usuario]
    Idioma* obtenerIdioma(string nombre);
};

#endif