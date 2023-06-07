#ifndef DATA_CURSO
#define DATA_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes 
#include "DataProfesor.hh"
#include "DataLeccion.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataCurso
{
private:
    string Nombre;
    string Descricpion;
    difficulty Dificultad;
    string Idioma;
    DataProfesor* Creo;
    set<string> Previos;
    set<DataLeccion *> Lecciones;
public:
    // Constructores
    DataCurso(string name, string desc, difficulty diff, string idi, DataProfesor* prof, set<string> previos, set<DataLeccion *>  leccs);
    // Destructor
    ~DataCurso();
    // Getters
    string getNombre();
    string getDescripcion();
    difficulty getDifificulty();
    string getIdioma();
    DataProfesor* getCreo();
    set<string> getPrevios();
    set<DataLeccion *> getLecciones();
};

#endif