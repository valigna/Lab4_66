#include "../../include/DataTypes/InformacionDeCurso.hh"

// Constructores
InformacionDeCurso::InformacionDeCurso(string name, string desc, difficulty diff, string ens, DataProfesor* prof, set<string> previos, int cLecs, int cEjs)
{
    this->Nombre = name;
    this->Descripcion = desc;
    this->Dificultad = diff;
    this->Ensenia = ens;
    this->CreadoPor = prof;
    this->Previos = previos;
    this->cantLecciones = cLecs;
    this->cantEjercicios = cEjs;
}

// Destructores
InformacionDeCurso::~InformacionDeCurso(){ }

// Getters
string InformacionDeCurso::getNombre(){ return this->Nombre; }
string InformacionDeCurso::getDescripcion(){ return this->Descripcion; }
difficulty InformacionDeCurso::getDificultad(){ return this->Dificultad; }
string InformacionDeCurso::getEnsenia() { return this->Ensenia; }
DataProfesor* InformacionDeCurso::getCreadoPor(){ return this->CreadoPor; }
set<string> InformacionDeCurso::getPrevios(){ return this->Previos; }
int InformacionDeCurso::getcantLecciones(){ return this->cantLecciones; }
int InformacionDeCurso::getcantEjercicios(){ return this->cantEjercicios; }