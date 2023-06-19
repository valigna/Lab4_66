#ifndef PROFESOR
#define PROFESOR

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos del Modelo de Dominio
#include "Usuario.hh"
// DataTypes
#include "DataTypes/DataProfesor.hh"
#include "DataTypes/InfoCurso.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Profesor : public Usuario
{
private:
    string Instituto;
    // PseudoAtributos
    map<string,Curso *> colCursos;
    map<string,Idioma *> colIdiomas;
public:
    // Constructores
    Profesor(DataUsuario* datos,set<string> seleccionados);
    // Destructor

    // Getters y Setters
    string getInstituto();

    // DataTypes
    DataProfesor* getDataUsuario();
    DataProfesor* getDatosUsuario();

    // Para distinguir entre las distintas sub-clases
    bool esEstudiante();
    bool esProfesor();

    // Para el caso de uso : [Eliminar Curso]
    void eliminarLinkP(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<InfoCurso *> getInfoCursos();

    void agregarCurso(Curso* curso);
};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */
/* ------------------------------------------------------------------------------------------------------ */

#endif