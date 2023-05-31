#ifndef USUARIO
#define USUARIO

// includes...
#include "Utils.hh"
#include "Notificacion.hh"


class Usuario
{
private:
    string nickname;
    string nombre;
    string password;
    string descripcion;

    //Colecciones
    vector<Notificacion *> colNotificaciones;

public:
    set<string> getIdiomasSuscritos();
    set<string> getCursosNoAprobados();
    
    // Para distinguir entre las clases que se derivan de Usuario...
    bool esAlumno();
    bool esProfesor();
}
