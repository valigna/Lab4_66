#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO



// includes...
#include "../Usuario.hh"
#include "../Utils.hh"
// ControladorCurso
// DataUsuario


class ControladorUsuario : public IGestionUsuario, public IGestionNotificaciones 
{
private:
    // Simulando Memoria Del Sistema...
    DataUsuario Datos;

    //Colecciones
    map<string,Usuario *> colUsuarios;


public:
    void ingresarUsuario(DataUsuario Datos);
    set<string> getIdiomas();
    set<string> idiomasSuscritos(string nickname);
    set<string> getCursosInscriptosNoAporbados(string nickname);
    set<string> darNicksEstudiantes();
    set<InfoCursoEst *> darInfoCursoEst(string nickEstudiante);
    set<string> darNicksProfesores();
    set<InfoCursoProf *> darInfoCursoProf(string nickProfesor);
    set<DataEjercicio *> getEjerciciosNoAprobados(string curso);
    string getProblema(int ejercicio);
}

#endif
