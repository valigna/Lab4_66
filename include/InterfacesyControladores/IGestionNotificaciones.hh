#ifndef I_GESTION_NOTIFICACIONES
#define I_GESTION_NOTIFICACIONES

#include "../Utils.hh"

class IGestionNotificaciones
{
public:
    virtual set<string> idiomasNoSuscritos(string nickname) = 0;
    virtual void suscribirse(set<string> idiomas) = 0;
    virtual set<DataNotificacion *> obtenerNotificaciones(string nickname) = 0;
    virtual set<string> idiomasSuscritos(string nickname) = 0;
    virtual void eliminarSuscripciones(set<string> seleccionados) = 0;

    virtual ~IGestionNotificaciones();
}

#endif