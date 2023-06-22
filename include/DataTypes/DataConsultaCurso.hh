#ifndef DATA_CONSULTA_CURSO
#define DATA_CONSULTA_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes 
#include "DataLeccion.hh"
#include "DataInscripto.hh"
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
    set<DataLeccion *> lecciones;
    set<DataInscripto *> estudiantes;
public:
    // Constructores
    DataConsultaCurso(string name, string desc, difficulty diff, string idi, string prof, bool habil, set<DataLeccion *> lecs, set<DataInscripto *> estus);
    // Destructor
    ~DataConsultaCurso();
    // Getters
    string getNombre();
    string getDescripcion();
    difficulty getDifificulty();
    string getIdioma();
    string getProfesor();
    bool getHabilitado();
    set<DataLeccion *> getLecciones(); 
    set<DataInscripto *> getEstudiantes();
};

#endif