#ifndef ESTUDIANTE
#define ESTUDIANTE

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Usuario.hh"
// DataTypes
#include "DataTypes/DataEstudiante.hh"
#include "DataTypes/InfoCursoEst.hh"
#include "DataTypes/DataFecha.hh"

// Forward Declaration
class Inscripcion;
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
    // DataTypes
    DataUsuario* getDataUsuario();
    DataUsuario* getDatosUsuario();
    // Auxiliares
    bool esEstudiante();
    bool esProfesor();
    set<string> obtenerCursosAprobados();
    set<string> obtenerCursosInscriptos();
    // Para el Caso de Uso : [Realizar Ejercicio]
    set<string> obtenerCursosNoAprobados();
    set<DataEjercicio *> obtenerEjerciciosNoAprobados(string curso);
    void hacerEjercicioT(int ejercicio, string sol);
    void hacerEjercicioCP(int ejercicio, set<string> sol);
    // Otres
    void eliminarLinkE(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<InfoCurso *> getInfoCursos();

    // Para el caso de uso: [Inscribirse a curso]
    set<DatosCurso *> darCursosDisponibles();
};

#endif