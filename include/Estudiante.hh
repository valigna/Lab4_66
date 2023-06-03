#ifndef ESTUDIANTE
#define ESTUDIANTE

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Usuario.hh"
// DataTypes
#include "DataTypes/InfoCursoEst.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Estudiante: public Usuario
{
private:

    // PseudoAtributos
    set<Inscripcion *> colInscripciones; 
public:
    // Constructores
    Estudiante(string nick,string name, string pass, string desc, DataEstudiante* est);
    // Destructor

    set<string> obtenerCursosNoAprobados();
    set<DataEjercicio *> obtenerEjerciciosNoAprobados(string curso);
    void eliminarLinkE(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<InfoCursoEst *> infCursosInscriptos();
};

#endif