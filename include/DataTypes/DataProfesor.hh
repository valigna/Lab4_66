#ifndef DATA_PROFESOR
#define DATA_PROFESOR

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "DataUsuario.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataProfesor : public DataUsuario
{
private:
    string Instituto;
    set<string> Idiomas;
public:
    // Constructores
    DataProfesor(string nick, string name, string con, string desc,string inst,set<string> idiomas);
    DataProfesor(string nick, string name, string con, string desc,string inst); // Para la creacion de 'Datos Profesor'
    // Destructor
    ~DataProfesor();
    // Getters
    string getInstituto();
    set<string> getIdiomas();
    // Para distinguir entre las distintas sub-clases
    bool esEstudiante();
    bool esProfesor();
};

#endif