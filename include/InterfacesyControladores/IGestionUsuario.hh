#ifndef I_GESTION_USUARIO
#define I_GESTION_USUARIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// Data Types
#include "../DataTypes/DataUsuario.hh"
#include "../DataTypes/DatosEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class IGestionUsuario
{
public:
    // Para el Caso de Uso : [Alta de Usuario]
    virtual void ingresarUsuario(DataUsuario* datos) = 0;
    virtual set<string> getIdiomas() = 0;
    virtual void ingresarIdiomas(set<string> seleccionados) = 0;
    virtual bool confirmarAltaUsuario() = 0;
    // Para el Caso de Uso : [Consulta de Usuario]
    virtual set<string> getNicksUsuarios() = 0;
    virtual DataUsuario* getDatosUsuario(string nick) = 0;
    // Para el Caso de Uso : [Realizar Ejercicio]
    virtual set<string> getCursosInscriptosNoAporbados(string nickname) = 0;
    virtual set<DatosEjercicio *> getEjerciciosNoAprobados(string curso) = 0;
    virtual string getProblema(int ejercicio) = 0;
    virtual void resolverEjercicioT(int ejercicio, string sol) = 0;
    virtual void resolverEjercicioCP(int ejercicio, set<string> sol) = 0;

    virtual ~IGestionUsuario();
};

#endif