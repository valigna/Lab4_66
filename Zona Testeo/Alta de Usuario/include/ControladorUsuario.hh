#ifndef CONTROLADOR_USUARIO
#define CONTROLADOR_USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../../include/Utils.hh"
#include "Usuario.hh"
#include "ControladorCurso.hh"
// DataTypes
#include "../../../include/DataTypes/DataUsuario.hh"
/* ------------------------------------------------------------------------------------------------------ */

class ControladorUsuario
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

public:
    // Constructores

    // Destructor
    ~ControladorUsuario();
    // Getters y Setters

    // Implementacion del Patron de Disenio : Singleton
    static ControladorUsuario* getInstancia();

    // Otros
    set<string> getIdiomas(); // Tambien usado en : {Alta de Usuario}
    // Para el Caso de Uso : [Alta de Usuario]
    void ingresarUsuario(DataUsuario *datos);
    void ingresarIdiomas(set<string> seleccionados);
    bool confirmarAltaUsuario();
};

#endif