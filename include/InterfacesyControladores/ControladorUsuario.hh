#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// Interfaces
#include "IGestionUsuario.hh"
#include "IGestionNotificaciones.hh"
//
#include "ControladorCurso.hh"
// Conceptos Del Modelo De Dominio
#include "../Usuario.hh"
#include "../Profesor.hh"
// DataTypes
#include "../DataTypes/DataEstudiante.hh"
#include "../DataTypes/DataProfesor.hh"
#include "../DataTypes/InfoCurso.hh"
#include "../DataTypes/InformacionCurso.hh"
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
    // Memoria para el Caso de Uso : [Suscribirse a Notificaciones], [Inscribirse a Curso], [Realizar Ejercicio]
    string nickname;
    // Creo que tambien se va a usar en otros casos de uso, no pasa nada que se repita | Eso si, aclaren en cuales se repitio si es el caso
    // Memoria para el Caso de Uso : [Realizar Ejercicio]
    string nomC;

public:
    // Destructor
    ~ControladorUsuario();

    // Implementacion del Patron de Disenio : Singleton
    static ControladorUsuario* getInstancia();

    // Para el Caso de Uso : [Alta de Usuario]
    void ingresarUsuario(DataUsuario* datos);
    set<string> getIdiomas();
    void ingresarIdiomas(set<string> seleccionados);
    bool confirmarAltaUsuario();

    // Para el Caso de Uso : [Consulta de Usuario]
    set<string> getNicksUsuarios();
    DataUsuario* getDatosUsuario(string nick);

    // Para el Caso de Uso : [Consulta de Curso]
    set<string> obtenerCursos();
    DataConsultaCurso* seleccionarCurso(string curso);  

    // Para el Caso de Uso : [Realizar Ejercicio]
    set<string> getCursosInscriptosNoAporbados(string nickname);
    set<DataEjercicio *> getEjerciciosNoAprobados(string curso); // Aca estaba como DATA, confirmar...
    string getProblema(int ejercicio);
    void resolverEjercicioT(int ejercicio, string sol);
    void resolverEjercicioCP(int ejercicio, set<string> sol);

    // Para el Caso de Uso : [Alta de Curso]
    Usuario* findUsuario(string nickname);

    // Para el caso de uso: [Inscribirse a curso]
    set<InformacionCurso *> getCursosDisponibles(string nickname);
    void inscribirseACurso(string curso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<string> darNicksEstudiantes();
    set<string> darNicksProfesores();
    set<InfoCurso *> darInfoCursos(string nickUsuario);

    // Para el Caso de Uso : [Suscribirse a Notificaciones]
    set<string> idiomasNoSuscritos(string nickname);
    void suscribirse(set<string> idiomas);

    // Para el Caso de Uso : [Consulta de Notificaciones]
    set<DataNotificacion *> obtenerNotificaciones(string nickname);

    // Para el caso de uso: [Eliminar Suscripciones]
    set<string> idiomasSuscritos(string nickname);
    void eliminarSuscripciones(set<string> seleccionados);

};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */

/* ------------------------------------------------------------------------------------------------------ */

#endif