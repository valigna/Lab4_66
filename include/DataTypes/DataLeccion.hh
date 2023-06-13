#ifndef DATA_LECCION
#define DATA_LECCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataLeccion
{
private:
    string Tema;
    string Objetivo;
    int Id;
    set<DataEjercicio *> Ejercicios;
public:
    // Constructores
    DataLeccion(string tema, string obj, set<DataEjercicio *> ejs);
    DataLeccion(string tema, string obj, int id, set<DataEjercicio *> ejs);
    // Destructor
    ~DataLeccion();
    // Getters
    string getTema();
    string getObjetivo();
    int getId();
    set<DataEjercicio *> getEjercicios();
};
#endif