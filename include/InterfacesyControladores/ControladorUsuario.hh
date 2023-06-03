#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "../Usuario.hh"
#include "ControladorCurso.hh"
#include "../DataTypes/DataUsuario.hh"

/* ------------------------------------------------------------------------------------------------------ */

class ControladorUsuario : public IGestionUsuario, public IGestionNotificaciones 
{
private:
    // Simulando Memoria Del Sistema...
    string nickname

    //Colecciones
    map<string,Usuario *> colUsuarios;

    // Memoria para el Caso de Uso : [Alta de Usuario]
    DataUsuario* datos;
    set<string> seleccionados;

public:
    // Constructores

    // Destructor

    // Getters y Setters

    // Otros
    set<string> getIdiomas(); // Tambien usado en : {Alta de Usuario}
    set<string> getCursosInscriptosNoAporbados(string nickname);
    set<DataEjercicio *> getEjerciciosNoAprobados(string curso);
    string getProblema(int ejercicio);

    // Para el Caso de Uso : [Alta de Usuario]
    void ingresarUsuario(DataUsuario *datos);
    void ingresarIdiomas(set<string> seleccionados);
    bool confirmarAltaUsuario();
    // Para el Caso de Uso : [Consultar Estadisticas]
    set<string> darNicksEstudiantes();
    set<InfoCursoEst *> darInfoCursosEst(string nickEstudiante);
    set<string> darNicksProfesores();
    set<InfoCursoProf *> darInfoCursoProf(string nickProfesor);

    // Para el Caso de Uso : [Suscribirse a Notificaciones]
    set<string> idiomasNoSuscritos(string nickname);

    // Para el caso de uso: [Eliminar Suscripciones]
    set<string> idiomasSuscritos(string nickname);
}

#endif