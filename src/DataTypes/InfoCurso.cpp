#include "../../include/DataTypes/InfoCurso.hh"

// Constructores
InfoCurso::InfoCurso(string nomC,float dato){
    this->NombreCurso = nomC;
    this->Dato = dato;
}

// Destructor
InfoCurso::~InfoCurso(){ }

// Getters
string InfoCurso::getNombreCurso(){ return this->NombreCurso;}
float InfoCurso::getDato(){return this->Dato;}
