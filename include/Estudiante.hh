#ifndef ESTUDIANTE
#define ESTUDIANTE

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos del Modelo de Dominio;
#include "Usuario.hh"
class Inscripcion;
// DataTypes
#include "DataTypes/DataFecha.hh"
#include "DataTypes/DataEstudiante.hh"
#include "DataTypes/InfoCurso.hh"
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
    // Estudiante(string nick,string name, string pass, string desc, DataEstudiante* est);
    Estudiante(DataUsuario* datos);
    // Destructor
    ~Estudiante();
    // Getters y Setters
    string getPaisResidencia();
    DataFecha* getNacimiento();
    // Implementar en caso de ser necesario...
    // set<Inscripcion *> getcolInscripciones();
    // DataTypes
    DataUsuario* getDataUsuario();
    DataUsuario* getDatosUsuario();
    // Para distinguir entre las distintas sub-clases
    bool esEstudiante();
    bool esProfesor();
    //
    set<string> obtenerCursosAprobados();
    set<string> obtenerCursosInscriptos();
    // Para el Caso de Uso : [Realizar Ejercicio]
    set<string> obtenerCursosNoAprobados();
    set<DataEjercicio *> obtenerEjerciciosNoAprobados(string curso);
    void hacerEjercicioT(string curso, int ejercicio, string sol);
    void hacerEjercicioCP(string curso, int ejercicio, set<string> sol);
    // Otres
    void eliminarLinkE(Inscripcion *I);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<InfoCurso *> getInfoCursos();

    // Para el caso de uso: [Inscribirse a curso]
    set<InformacionCurso *> darCursosDisponibles();
    void realizarInscripcion(string curso);

};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "Inscripcion.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif