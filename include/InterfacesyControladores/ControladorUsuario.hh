#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "../Usuario.hh"
#include "ControladorCurso.hh"
// DataTypes
#include "../DataTypes/DataUsuario.hh"
#include "../DataTypes/DatosEstudiante.hh"
#include "../DataTypes/DatosProfesor.hh"
#include "../DataTypes/DatosCurso.hh" // FALTA IMPLEMENTAR
/* ------------------------------------------------------------------------------------------------------ */

class ControladorUsuario : public IGestionUsuario, public IGestionNotificaciones 
{
private:
    // Implementacion del Patron de Disenio : Singleton
    static ControladorUsuario* instancia;
    ControladorUsuario();

    //Colecciones
    map<string,Usuario *> colUsuarios;

    // Memoria para el Caso de Uso : [Alta de Usuario]
    DataUsuario* datos;
    set<string> seleccionados;
    // Memoria para el Caso de Uso : [Suscribirse a Notificaciones]
    string nickname;
    // Creo que tambien se va a usar en otros casos de uso, no pasa nada que se repita | Eso si, aclaren en cuales se repitio si es el caso

public:
    // Destructor
    ~ControladorUsuario();

    // Implementacion del Patron de Disenio : Singleton
    static ControladorUsuario* getInstancia();

    // Otros
    set<string> getIdiomas(); // Tambien usado en : {Alta de Usuario}
    
    // Para el Caso de Uso : [Alta de Usuario]
    void ingresarUsuario(DataUsuario* datos);
    void ingresarIdiomas(set<string> seleccionados);
    bool confirmarAltaUsuario();

    // Para el Caso de Uso : [Consulta de Usuario]
    set<string> getNicksUsuarios();
    DatosUsuario* getDatosUsuario(string nick);

    //Para el Caso de Uso : [Realizar Ejercicio]
    set<string> getCursosInscriptosNoAporbados(string nickname);
    set<DatosEjercicio *> getEjerciciosNoAprobados(string curso);
    string getProblema(int ejercicio);
    void resolverEjercicioT(int ejercicio, string sol);
    void resolverEjercicioCP(int ejercicio, set<string> sol);

    // Para el Caso de Uso : [Alta de Curso]
    Usuario findUsuario(string nickname);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<string> darNicksEstudiantes();
    set<InfoCursoEst *> darInfoCursosEst(string nickEstudiante);
    set<string> darNicksProfesores();
    set<InfoCursoProf *> darInfoCursoProf(string nickProfesor);

    // Para el Caso de Uso : [Suscribirse a Notificaciones]
    set<string> idiomasNoSuscritos(string nickname);

    // Para el caso de uso: [Eliminar Suscripciones]
    set<string> idiomasSuscritos(string nickname);

    // Para el caso de uso: [Inscribirse a curso]
    set<DatosCurso> getCursosDisponibles(string nickname);
};

#endif