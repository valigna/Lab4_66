#ifndef USUARIO
#define USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "InterfacesyControladores/ControladorCurso.hh"
// Conceptos del Modelo de Dominio
class Curso;
class Notificacion;
#include "InterfacesyControladores/Suscripcion.hh"
// DataTypes
#include "DataTypes/DataEstudiante.hh"
#include "DataTypes/DataProfesor.hh"
#include "DataTypes/InfoCurso.hh"
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
    ~Usuario();
    // Getters y Setters : Tendra sentido definir los setters? Pq una vez creado no se vuelve a modificar...
    string getNickname();
    string getNombre();
    string getPassword();
    string getDescripcion();

    // DataTypes
    virtual DataUsuario* getDataUsuario(); // Prof sin idiomas
    virtual DataUsuario* getDatosUsuario(); // Este no tiene nick y password / Prof con idiomas

    // Auxiliares
    // Por el momento, al tener usuario solo 2 subclases, hacer una funcion para cada uno
    // resulta un tanto inescesario. Pero optamos por esta opcion ya que si en el 'futuro' se agregaran mas clases, los codigos no se verian afectados
    virtual bool esEstudiante() = 0;
    virtual bool esProfesor() = 0;

    // Para el caso de uso : [Realizar Ejercicio]
    //set<string> getCursosNoAprobados();

    // Para el caso de uso : [Suscribirse a notificaciones]
    set<string> darIdiomasNoSuscritos();

    // Para el caso de uso : [Eliminar Curso]
    void notificarBaja(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    virtual set<InfoCurso *> getInfoCursos() = 0;

    // Para el caso de uso: [Eliminar Suscripciones]
    set<string> darIdiomasSuscritos();
};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
#include "Curso.hh"
#include "Notificacion.hh"
/* ------------------------------------------------------------------------------------------------------ */

#endif