#include "../include/Profesor.hh"
#include "../include/ControladorCurso.hh"

// Constructores
Profesor::Profesor(string nick,string name, string pass, string desc, DataProfesor* prof,set<string> seleccionados) : Usuario(nick,name,pass,desc)
{
    this->colCursos = new map<string,Curso *>();
    this->colIdiomas = new map<string,Idioma *>();
    this->Instituto = prof->getInstituto();
    
    // Obtengo la instancia de ControladorCurso para recorrer su coleccion de idiomas.
    ControladorCurso* cc;
    for(set<string>::iterator it = seleccionados.begin(); it != seleccionados.end(); ++it)
    {
        Idioma* i = cc->obtenerIdioma();
        if(i != NULL) this->colIdiomas.insert(i->getNombre(),i);
    }

}
// Destructor

// Getters y Setters
string Profesor::getInstituto(){ return this->Instituto; }