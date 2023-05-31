#ifndef CONTROLADOR_CURSO
#define CONTROLADOR_CURSO

// includes ...
#include "../Utils.hh"
#include "../Idioma.hh"
#include "../Curso.hh"

class ControladorCurso
{
private:
    map<string,Idioma *> colIdiomas;
    map<string,Curso *> colCursos;
    string nombreCurso;

public:
    set<string> darIdiomas();
    set<string> getNombreCursos();
    void seleccionarCurso(string nombreCurso);

}

#endif