#ifndef DT_CURSO
#define DT_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DTCurso
{
private:
    string Nombre;
    string Desc;
    difficulty Dificultad;
public:
    // Constructores
    DTCurso(string Nombre, string Desc, difficulty Dificultad);
    // Destructor
    ~DTCurso();
    // Getters 
    string getNombre();
    string getDescripcion();
    difficulty getDifificulty();
    
};

//push 
#endif