#include "../../include/InterfacesyControladores/distribuidorInterfaces.hh"

// Constructor
distribuidorInterfaces::distribuidorInterfaces(){ }

// Destructor
distribuidorInterfaces::~distribuidorInterfaces(){ }

// Interfaces que devuelve...

IGestionUsuario* distribuidorInterfaces::getIGestionUsuario()
{
    return ControladorUsuario::getInstancia();
}

IGestionNotificaciones* distribuidorInterfaces::getIGestionNotificaciones()
{
    return ControladorUsuario::getInstancia();
}

IGestionCurso* distribuidorInterfaces::getIGestionCurso()
{
    return ControladorCurso::getInstancia();
}

IGestionIdiomas* distribuidorInterfaces::getIGestionIdiomas()
{
    return ControladorCurso::getInstancia();
}

IConsultarEstadisticas* distribuidorInterfaces::getIConsultarEstadisticas()
{
    return new ControladorEstadisticas();
}