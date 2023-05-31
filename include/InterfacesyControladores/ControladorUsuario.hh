#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO



// includes...
#include "../Usuario.hh"
#include "../Utils.hh"
// ControladorCurso
// DataUsuario


class ControladorUsuario 
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
}


