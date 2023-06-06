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
    // Para el Caso de Uso : [Realizar Ejercicio]
    set<string> obtenerCursosNoAprobados();
    set<DatosEjercicio *> obtenerEjerciciosNoAprobados(string curso);
    void hacerEjercicioT(int ejercicio, string sol);
    void hacerEjercicioCP(int ejercicio, set<string> sol);
    // Otres
    void eliminarLinkE(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<InfoCursoEst *> infCursosInscriptos();
};

#endif