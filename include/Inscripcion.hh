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
    Curso *c;
    set<Ejercicio *> colEjAprobados;
    set<Leccion *> colLecAprobadas;
public:
    string darNombreCurso();
    float darAvance();
    float darAvance(int cantEj);
    int cantEjAprobados();
    string obtenerCursoNoAprobado();
    bool getCursoAprobado();
}

#endif