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
    map<int, DataEjercicio *> Ejercicios;
public:
    // Constructores
    DataLeccion(string tema, string obj, map<int, DataEjercicio *> ejs);
    // Destructor
    ~DataLeccion();
    // Getters
    string getTema();
    string getObjetivo();
    map<int, DataEjercicio *> getEjercicios();
};
#endif