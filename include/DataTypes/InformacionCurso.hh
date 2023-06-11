#ifndef INFORMACION_CURSO
#define INFORMACION_CURSO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class InformacionCurso
{
private:
    string Nombre;
    string Descripcion;
    difficulty Dificultad;
    set<string> CursosPrevios;
    string Idioma;
    string Profesor;
    int cantLecciones;
    int cantEjercicios;
    float Promedio;
public:
    // Constructores
    InformacionCurso(string name, string desc, difficulty difi, set<string> previos, string idi, string prof, int cLec, int cEj, float prom);
    InformacionCurso(string name, string desc, difficulty difi, string idi, int cLec, int cEj);
    // Destructor
    ~InformacionCurso();
    // Getters
    string getNombre();
    string getDescripcion();
    difficulty getDificultad();
    set<string> getPrevios();
    string getIdioma();
    string getProfesor();
    int getCantLecciones();
    int getCantEjercicios();
    float getPromedio();
};

#endif