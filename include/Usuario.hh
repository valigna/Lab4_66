#ifndef USUARIO
#define USUARIO

// includes...
#include "Utils.hh"
#include "Notificacion.hh"


class Usuario
{
private:
    string Nickname;
    string Nombre;
    string Password;
    string Descripcion;

    //Colecciones
    vector<Notificacion *> colNotificaciones;

public:
    set<string> getIdiomasSuscritos();
    set<string> getCursosNoAprobados();
    
    // Para distinguir entre las clases que se derivan de Usuario...
    bool esEstudiante();
    bool esProfesor();
}

#endif