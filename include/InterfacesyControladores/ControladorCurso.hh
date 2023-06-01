#ifndef CONTROLADOR_CURSO
#define CONTROLADOR_CURSO

// includes ...
#include "../Utils.hh"
#include "../Idioma.hh"
#include "../Curso.hh"

class ControladorCurso : public IGestionCurso
{
private:
    map<string,Idioma *> colIdiomas;
    map<string,Curso *> colCursos;
    string nombreCurso;

public:
    // Constructores

    // Destructor

    // Getters y Setters
    
    // Otros
    void seleccionarCurso(string nombreCurso);
    void bajarCurso();
    set<string> darIdiomas();
    set<string> getNombreCursos();
    set<string> darNombreCursos();
    InformacionCurso darInformacionCurso(string nombreCurso);
    void ingresarDataCurso(string profesor,DTCurso curso);
    string obtenerLetra(nomC string, int ejercicio);
}

#endif