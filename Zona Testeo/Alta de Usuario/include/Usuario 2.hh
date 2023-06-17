#ifndef USUARIO
#define USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../../include/Utils.hh"
// DataTypes
#include "../../../include/DataTypes/DataUsuario.hh"
#include "../../../include/DataTypes/DataEstudiante.hh"
#include "../../../include/DataTypes/DataProfesor.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Usuario
{
private:
    string Nickname;
    string Nombre;
    string Password;
    string Descripcion;

public:
    // Constructores
    Usuario(string nick, string name, string con, string desc);
    Usuario(DataUsuario *datos,set<string> seleccionados);
    
    // Destructor

    // Getters y Setters : Tendra sentido definir los setters? Pq una vez creado no se vuelve a modificar...
    string getNickname();
    string getNombre();
    string getPassword();
    string getDescripcion();
};

#endif