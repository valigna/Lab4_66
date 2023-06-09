#ifndef INFORMACION_DE_CURSO
#define INFORMACION_DE_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
// DataTypes
#include "DataProfesor.hh"
/* ------------------------------------------------------------------------------------------------------ */

class InformacionDeCurso
{
private:
    string Nombre;
    string Descripcion;
    difficulty Dificultad;
    string Ensenia;  // idioma
    DataProfesor* CreadoPor;
    set<string> Previos;
    int cantLecciones;
    int cantEjercicios;
public:
    // Constructores
    InformacionDeCurso(string name, string desc, difficulty diff, string ens, DataProfesor* prof, set<string> previos, int cLecs, int cEjs);
    // Destructor
    ~InformacionDeCurso();
    // Getters
    string getNombre();
    string getDescripcion();
    difficulty getDificultad();
    set<string> getPrevios();
    string getEnsenia();
    DataProfesor* getCreadoPor();
    int getcantLecciones();
    int getcantEjercicios();
};

#endif