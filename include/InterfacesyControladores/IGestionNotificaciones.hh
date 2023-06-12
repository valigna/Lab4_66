#ifndef I_GESTION_NOTIFICACIONES
#define I_GESTION_NOTIFICACIONES

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "../DataTypes/DataNotificacion.hh"
/* ------------------------------------------------------------------------------------------------------ */

class IGestionNotificaciones
{
public:
    // Operaciones De Sistema De : [Suscribirse a notificaciones]
    virtual set<string> idiomasNoSuscritos(string nickname) = 0;
    virtual void suscribirse(set<string> idiomas) = 0;
    // Operaciones De Sistema De : [Consulta de Notificaciones]
    virtual set<DataNotificacion *> obtenerNotificaciones(string nickname) = 0;
    // Operaciones De Sistema De : [Eliminar Suscripciones]
    virtual set<string> idiomasSuscritos(string nickname) = 0;
    virtual void eliminarSuscripciones(set<string> seleccionados) = 0;
    //
    virtual ~IGestionNotificaciones(){};
};

#endif