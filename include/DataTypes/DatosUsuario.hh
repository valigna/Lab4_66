#ifndef DATOS_USUARIO
#define DATOS_USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DatosUsuario
{
private:
    string Nombre;
    string Descripcion;
public:
    // Constructores
    DatosUsuario(string name,string desc);
    // Destructor
    virtual ~DatosUsuario();
    // Getters
    string getNombre();
    string getDescripcion();
};

#endif