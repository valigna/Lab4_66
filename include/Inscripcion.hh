#ifndef INSCRIPCION
#define INSCRIPCION

// Includes...
#include "Utils.hh"

class Inscripcion
{
private:
    Fecha FechaInscripcion;
    bool CursoAprobado;
    
    // PseudoAtributos...
    Estudiante *e;
    Curso *c;
    set<Ejercicio *> colEjAprobados;
    set<Leccion *> colLecAprobadas;
public:
    // Constructores

    // Destructor
    ~Inscripcion();
    // Getters y Setters

    // Otres
    string darNombreCurso();
    float darAvance();
    float darAvance(int cantEj);
    int cantEjAprobados();
    bool getCursoAprobado();
    Curso* getCurso();
    set<DataEjercicio *> obtenerListaEjerciciosNoAprobadosIns();
}
#endif