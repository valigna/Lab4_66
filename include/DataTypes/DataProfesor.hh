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
    // Destructor
    ~DataProfesor();
    // Getters
    string getInstituto();
    set<string> getIdiomas();
};

#endif