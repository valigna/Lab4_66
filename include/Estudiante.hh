#ifndef ESTUDIANTE
#define ESTUDIANTE

// includes....

class Estudiante: public Usuario
{
private:


    // PseudoAtributos
    map<string,Inscripcion *> colInscripciones; // La clave vendria a ser el nombre del curso...
public:
    set<InfoCursoEst> infCursosInscriptos();

}