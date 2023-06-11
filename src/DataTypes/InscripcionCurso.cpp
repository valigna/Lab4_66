#include "../../include/DataTypes/InscripcionCurso.hh"

InscripcionCurso::InscripcionCurso(string name, string desc, difficulty diff, string idi, bool hab, set<DataLeccion *> leccs, set<DataInscripto *> ests)
{
    this->Nombre = name;
    this->Descripcion = desc;
    this->Dificultad = diff;
    this->Idioma = idi;
    this->Habilitado = hab;
    this->Lecciones = leccs;
    this->Estudiantes = ests;

}

// Destructor
InscripcionCurso::~InscripcionCurso(){ }

// Getters
string InscripcionCurso::getNombre(){ return this->Nombre; }
string InscripcionCurso::getDescripcion(){ return this->Descripcion; }
difficulty InscripcionCurso::getDificultad(){ return this->Dificultad; }
bool InscripcionCurso::getHabilitado(){ return this->Habilitado; }
set<DataLeccion *> InscripcionCurso::getLecciones(){ return this->Lecciones; }
set<DataInscripto *> InscripcionCurso::getEstudiantes(){ return this->Estudiantes; }