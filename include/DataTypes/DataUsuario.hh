#ifndef DATA_USUARIO
#define DATA_USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataUsuario
{
private:
    string Nickname;
    string Nombre;
    string Contrasenia;
    string Descripcion;
public:
    // Constructores
    DataUsuario(string nick, string name, string con, string desc);
    // Destructor
    ~DataUsuario();
    // Getters
    string getNickname();
    string getNombre();
    string getContrasenia();
    string getDescripcion();
};

#endif