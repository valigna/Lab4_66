#ifndef USUARIO
#define USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "InterfacesyControladores/Suscripcion.hh"
#include "InterfacesyControladores/ControladorCurso.hh"
#include "Notificacion.hh"
// DataTypes
#include "DataTypes/DataUsuario.hh"
#include "DataTypes/DataEstudiante.hh"
#include "DataTypes/DataProfesor.hh"
/* ------------------------------------------------------------------------------------------------------ */

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
    Usuario(string nick, string name, string con, string desc);
    // Usuario(DataUsuario *datos,set<string> seleccionados);
    
    // Destructor
    virtual ~Usuario() = 0;
    // Getters y Setters : Tendra sentido definir los setters? Pq una vez creado no se vuelve a modificar...
    string getNickname();
    string getNombre();
    string getPassword();
    string getDescripcion();

    // Para el caso de uso : [Realizar Ejercicio]
    //set<string> getCursosNoAprobados();

    // Para el caso de uso : [Suscribirse a notificaciones]
    set<string> darIdiomasNoSuscritos();

    // Para el caso de uso : [Eliminar Curso]
    void notificarBaja(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    bool esEstudiante();
    // Pasar esto a virtual...

    // Para el caso de uso: [Eliminar Suscripciones]
    set<string> darIdiomasSuscritos();
};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "Inscripcion.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif