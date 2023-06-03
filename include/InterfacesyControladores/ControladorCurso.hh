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
    set<string> darIdiomas();
    void ingresarDataCurso(string profesor,DTCurso curso);
    string obtenerLetra(nomC string, int ejercicio);

    // Para el Caso de Uso : [Alta de Usuario]
    Idioma* obtenerIdidioma(string nombre);

    // Operaciones de: [eliminar curso]
    set<string> getNombreCursos();
    void seleccionarCurso(string nombreCurso);
    void bajarCurso();

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<string> darNombreCursos();
    InformacionCurso* darInformacionCurso(string nombreCurso);
};

#endif