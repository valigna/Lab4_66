#ifndef PROFESOR
#define PROFESOR

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Usuario.hh"
#include "Curso.hh"
// DataTypes
#include "DataTypes/DataProfesor.hh"
#include "DataTypes/InfoCursoProf.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Profesor : public Usuario
{
private:
    string Instituto;

    // PseudoAtributos
    map<string,Curso *> colCursos; // Se cambia la implementacion de set a map
    map<string,Idioma *> colIdiomas;
public:
    // Constructores
    Profesor(DataUsuario* datos,set<string> seleccionados);
    // Destructor

    // Getters y Setters
    string getInstituto();

    // Para el caso de uso : [Eliminar Curso]
    void eliminarLinkP(string nombreCurso);

    // Para el Caso de Uso : [Consultar Estadisticas]
    set<InfoCursoProf *> darInfoCursos();
};

#endif