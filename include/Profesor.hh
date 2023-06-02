#ifndef PROFESOR
#define PROFESOR

//includes...

class Profesor : public Usuario
{
private:
    string instituto;

    // PseudoAtributos
    map<string,Curso *> colCursos; // Se cambia la implementacion de set a map
public:
    // Constructores

    // Destructor

    // Getters y Setters

    // Otres
    set<InfoCursoProf *> darInfoCurso();

    // Para el caso de uso : [Eliminar Curso]
    void eliminarLinkP(string nombreCurso);
}

#endif