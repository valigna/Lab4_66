#include "../../include/DataTypes/InformacionCurso.hh"

// Constructores
InformacionCurso::InformacionCurso(string name, string desc, difficulty difi, set<string> previos, string idi, string prof, int cLec, int cEj, float prom){
    this->Nombre = name;
    this->Descripcion = desc;
    this->Dificultad = difi;
    this->CursosPrevios = previos;
    this->Idioma = idi;
    this->Profesor = prof;
    this->cantLecciones = cLec;
    this->cantEjercicios = cEj;
    this->Promedio = prom;
}

InformacionCurso::InformacionCurso(string name, string desc, difficulty difi, string idi, int cLec, int cEj){
    this->Nombre = name;
    this->Descripcion = desc;
    this->Dificultad = difi;
    this->Idioma = idi;
    this->cantLecciones = cLec;
    this->cantEjercicios = cEj;
}

// Destructor
InformacionCurso::~InformacionCurso(){ }

// Getters
string InformacionCurso::getNombre(){ return this->Nombre;}
string InformacionCurso::getDescripcion(){ return this->Descripcion;}
difficulty InformacionCurso::getDificultad(){ return this->Dificultad;}
set<string> InformacionCurso::getPrevios(){ return this->CursosPrevios;}
string InformacionCurso::getIdioma() { return this->Idioma;}
string InformacionCurso::getProfesor() { return this->Profesor;}
int InformacionCurso::getCantLecciones() { return this->cantLecciones;}
int InformacionCurso::getCantEjercicios() {return this->cantEjercicios;}
float InformacionCurso::getPromedio() { return this->Promedio;}