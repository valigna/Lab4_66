#include "../../include/DataTypes/DataCurso.hh"

// Constructores
DataCurso::DataCurso(string name, string desc, difficulty diff, string idi, DataProfesor* prof, set<string> previos, set<DataLeccion *>  leccs)
{
    this->Nombre = name;
    this->Descricpion = desc;
    this->Dificultad = diff;
    this->Idioma = idi;
    this->Creo = prof;
    this->Previos = previos;
    this->Lecciones = leccs;
}

// Destructor
DataCurso::~DataCurso(){ }

// Getters
string DataCurso::getNombre(){ return this->Nombre; }
string DataCurso::getDescripcion(){ return this->Descricpion; }
difficulty DataCurso::getDifificulty(){ return this->Dificultad; }
string DataCurso::getIdioma(){ return this->Idioma; }
DataProfesor* DataCurso::getCreo(){ return this->Creo; }
set<string> DataCurso::getPrevios() {return this->Previos;}
set<DataLeccion *> DataCurso::getLecciones() {return this->Lecciones;}