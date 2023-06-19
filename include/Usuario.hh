#ifndef USUARIO
#define USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
class ControladorCurso;
#include "InterfacesyControladores/Suscripcion.hh"
// Conceptos del Modelo de Dominio
class Notificacion;
// DataTypes
#include "DataTypes/DataEstudiante.hh"
#include "DataTypes/DataProfesor.hh"
#include "DataTypes/InfoCurso.hh"
#include "DataTypes/DataNotificacion.hh"
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
    set<string> idiomasSuscritos;

public:
    // Constructores
    Usuario(string nick, string name, string con, string desc);
    // Usuario(DataUsuario *datos,set<string> seleccionados);
    
    // Destructor
    ~Usuario();
    // Getters y Setters : Tendra sentido definir los setters? Pq una vez creado no se vuelve a modificar...
    string getNickname();
    string getNombre();
    string getPassword();
    string getDescripcion();

    // DataTypes
    virtual DataUsuario* getDataUsuario() = 0; // Prof sin idiomas
    virtual DataUsuario* getDatosUsuario() = 0; // Este no tiene nick y password / Prof con idiomas

    // Para distinguir entre las distintas sub-clases
    virtual bool esEstudiante() = 0;
    virtual bool esProfesor() = 0;
    // Por el momento, al tener usuario solo 2 subclases, hacer una funcion para cada uno
    // resulta un tanto inescesario. Pero optamos por esta opcion ya que si en el 'futuro' se agregaran mas clases, los codigos no se verian afectados

    // Para el Caso de Uso : [Alta de Curso]
    void notificarAlta(Idioma *i,Curso *c);
    
    // Para el caso de uso : [Suscribirse a notificaciones]
    set<string> darIdiomasNoSuscritos();
    void agregarIdiomasSuscrito(set<string> idiomas);

    // Para el caso de uso : [Eliminar Curso]
    void notificarBaja(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    virtual set<InfoCurso *> getInfoCursos() = 0;

    set<DataNotificacion *> darNotificaciones();

    // Para el caso de uso: [Eliminar Suscripciones]
    set<string> darIdiomasSuscritos();
    void eliminarSuscripciones(set<string> seleccionados);

};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "InterfacesyControladores/ControladorCurso.hh"
#include "Notificacion.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif