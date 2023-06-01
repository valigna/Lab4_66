#ifndef I_GESTION_USUARIO
#define I_GESTION_USUARIO

#include "../Utils.hh"

class IGestionUsuario
{
public:
    virtual void ingresarUsuario(DataUsuario datos) = 0;
    virtual set<string> getIdiomas() = 0;
    virtual void ingresarIdiomas(set<string> seleccionados) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual set<string> getCursoInscriptoNoAprobado(string nickname) = 0;
    virtual set<DatosEjercicio> getEjerciciosNoAprobados(string curso) = 0;
    virtual string getProblema(int ejercicio) = 0;
    virtual void resolverEjercicioT(int ejercicio, string sol) = 0;
    virtual void resolverEjercicioCP(int ejercicio, set<string> sol) = 0;

    virtual ~IGestionUsuario();
}

#endif