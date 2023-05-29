#ifndef CONTROLADOR_CURSO
#define CONTROLADOR_CURSO

// includes ...
#include "../Utils.hh"

class ControladorCurso
{
private:
    std::map<string,Idioma *> colIdiomas;

public:
    set<string> darIdiomas();


}