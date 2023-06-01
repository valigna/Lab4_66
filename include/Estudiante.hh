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
    set<string> obtenerCursosNoAprobados();
    set<DataEjercicio *> obtenerEjerciciosNoAprobados(string curso);

}

#endif