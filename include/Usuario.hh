#ifndef USUARIO
#define USUARIO

// includes...
#include "Utils.hh"
#include "Notificacion.hh"
#include "InterfacesyControladores/Suscripcion.hh"

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

    // Destructor

    // Getters y Setters

    // Otros
    set<string> darIdiomasSuscritos();
    set<string> getCursosNoAprobados();
    
    // Para distinguir entre las clases que se derivan de Usuario...
    bool esEstudiante();
    bool esProfesor();

    // Para el caso de uso : [Suscribirse a notificaciones]
    set<string> darIdiomasNoSuscritos();
}

#endif