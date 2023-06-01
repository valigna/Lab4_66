#ifndef PROFESOR
#define PROFESOR

//includes...

class Profesor : public Usuario
{
private:
    string instituto;

    // PseudoAtributos
    set<Curso *> colCursos;
public:
    // Constructores

    // Destructor

    // Getters y Setters

    // Otres
    set<InfoCursoProf *> darInfoCurso();
}

#endif