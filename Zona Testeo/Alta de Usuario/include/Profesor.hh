#ifndef PROFESOR
#define PROFESOR

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../../../include/Utils.hh"
#include "Usuario.hh"
#include "Curso.hh"
// DataTypes
#include "../../../include/DataTypes/InfoCursoProf.hh"
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
    Profesor(string nick,string name, string pass, string desc, DataProfesor* prof,set<string> seleccionados);
    // Destructor

    // Getters y Setters
    string getInstituto();
};

#endif