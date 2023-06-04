#ifndef ESTUDIANTE
#define ESTUDIANTE

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Usuario.hh"
// DataTypes
#include "DataTypes/InfoCursoEst.hh"
#include "DataTypes/DataFecha.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Estudiante: public Usuario
{
private:
    string PaisResidencia;
    DataFecha* Nacimiento;
    // PseudoAtributos
    set<Inscripcion *> colInscripciones; 
public:
    // Constructores
    Estudiante(string nick,string name, string pass, string desc, DataEstudiante* est);
    // Destructor

    // Getters y Setters
    string getPaisResidencia();
    DataFecha* getNacimiento();
    // Otres
    set<string> obtenerCursosNoAprobados();
    set<DataEjercicio *> obtenerEjerciciosNoAprobados(string curso);
    void eliminarLinkE(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<InfoCursoEst *> infCursosInscriptos();
};

#endif