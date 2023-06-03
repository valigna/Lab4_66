#ifndef USUARIO
#define USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "InterfacesyControladores/Suscripcion.hh"
#include "Notificacion.hh"
// DataTypes
#include "DataTypes/DataUsuario.hh"
#include "DataTypes/DataEstudiante.hh"
#include "DataTypes/DataProfesor.hh"
/* ------------------------------------------------------------------------------------------------------ */

// includes...
#include "Utils.hh"



class Usuario : public Suscripcion
{
private:
    string Nickname;
    string Nombre;
    string Password;
    string Descripcion;

    //Colecciones
    vector<Notificacion *> colNotificaciones;

public:
    // Constructores
    Usuario(DataUsuario *datos,set<string> seleccionados);
    // Destructor

    // Getters y Setters

    // Otros
    set<string> getCursosNoAprobados();

    // Para el caso de uso : [Suscribirse a notificaciones]
    set<string> darIdiomasNoSuscritos();

    // Para el caso de uso : [Eliminar Curso]
    void notificarBaja(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    bool esEstudiante();

    // Para el caso de uso: [Eliminar Suscripciones]
    set<string> darIdiomasSuscritos();
};

#endif