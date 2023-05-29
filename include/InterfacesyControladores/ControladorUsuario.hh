#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

// includes...
// ControladorCurso
// DataUsuario


class ControladorUsuario 
{
private:
    // Simulando Memoria Del Sistema...
    DataUsuario Datos;


public:
    void ingresarUsuario(DataUsuario Datos);
    set<string> getIdiomas();
}