#ifndef DISTRIBUIDOR_INTERFACES
#define DISTRIBUIDOR_INTERFACES

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"

// Controladores
#include "ControladorUsuario.hh"
#include "ControladorCurso.hh"
#include "ControladorEstadisticas.hh"
// Interfaces
#include "IGestionUsuario.hh"
#include "IGestionNotificaciones.hh"
#include "IGestionCurso.hh"
#include "IGestionIdiomas.hh"
#include "IConsultarEstadisticas.hh"
/* ------------------------------------------------------------------------------------------------------ */

class distribuidorInterfaces
{
public:
    // Constructor
    distribuidorInterfaces();
    // Destructor
    ~distribuidorInterfaces();
    // Interfaces que devuelve...
    IGestionUsuario* getIGestionUsuario();
    IGestionNotificaciones* getIGestionNotificaciones();
    IGestionCurso* getIGestionCurso();
    IGestionIdiomas* getIGestionIdiomas();
    IConsultarEstadisticas* getIConsultarEstadisticas();
};

#endif