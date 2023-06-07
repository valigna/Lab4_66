#ifndef CONTROLADOR_CURSO
#define CONTROLADOR_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "../Idioma.hh"
#include "../Curso.hh"
// DataTypes
#include "../DataTypes/DataTraduccion.hh"
#include "../DataTypes/DataCompletarPalabras.hh"
/* ------------------------------------------------------------------------------------------------------ */

class ControladorCurso : public IGestionCurso, public IGestionIdiomas
{
private:
    // Implementacion del Patron de Disenio : Singleton
    static ControladorCurso* instancia;
    ControladorCurso();

    map<string,Idioma *> colIdiomas;
    map<string,Curso *> colCursos;
    
    // Para memoria de que caso de uso??
    string nombreCurso;

public:
    // Destructor
    ~ControladorCurso();
    // Getters y Setters
    
    // Implementacion del Patron de Disenio : Singleton
    static ControladorCurso* getInstancia();

    // Otros

    void ingresarDataCurso(string profesor,DTCurso curso);

    // Para el Caso de Uso : [Alta de Usuario]
    Idioma* obtenerIdioma(string nombre);

    // Para el Caso de Uso : [Alta de idioma]
    bool altaIdioma(string nombre);
    set<string> getIdiomas();

    // Para el Caso de Uso : [Habilitar Curso]
    set<InformacionDeCurso *> getCursosNoHabilitados();
    bool habilitarCurso(string seleccionado);

    //Para el Caso de Uso : [Realizar Ejercicio]
    string obtenerLetra(nomC string, int ejercicio);

    // Operaciones de: [eliminar curso]
    set<string> getNombreCursos();
    void seleccionarCurso(string nombreCurso);
    void bajarCurso();

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<string> darNombreCursos();
    InformacionCurso* darInformacionCurso(string nombreCurso);

};

#endif