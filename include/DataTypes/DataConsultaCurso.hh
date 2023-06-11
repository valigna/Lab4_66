#ifndef DATA_CONSULTA_CURSO
#define DATA_CONSULTA_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes 
#include "DataProfesor.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataConsultaCurso
{
private:
    string Nombre;
    string Descricpion;
    difficulty Dificultad;
    string Idioma;
    string profesor;
    bool habilitado;
public:
    // Constructores
    DataConsultaCurso(string name, string desc, difficulty diff, string idi, string prof, bool habil);
    // Destructor
    ~DataConsultaCurso();
    // Getters
    string getNombre();
    string getDescripcion();
    difficulty getDifificulty();
    string getIdioma();
    string getProfesor();
    bool getHabilitado(); 
};

#endif