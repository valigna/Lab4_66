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
public:
    // Constructores
    DataProfesor(string nick, string name, string con, string desc,string inst);
    // Destructor
    ~DataProfesor();
    // Getters
    string getInstituto();
};

#endif