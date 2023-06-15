#include "../../include/DataTypes/DTCurso.hh"

// Constructores
DTCurso::DTCurso(string Nombre, string Desc, difficulty Dificultad)
{
    this->Nombre = Nombre;
    this->Desc = Desc;
    this->Dificultad = Dificultad;
}

// Destructor
DTCurso::~DTCurso(){ }

// Getters
string DTCurso::getNombre(){ return this->Nombre; }
string DTCurso::getDescripcion(){ return this->Desc; }
difficulty DTCurso::getDifificulty(){ return this->Dificultad; }