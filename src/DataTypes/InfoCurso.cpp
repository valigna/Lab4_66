#include "../../include/DataTypes/InfoCurso.hh"

// Constructores
InfoCurso::InfoCurso(string nomC,float dato){
    this->NombreCurso = nomC;
    this->Promedio = dato;
}

// Destructor
InfoCurso::~InfoCurso(){ }

// Getters
string InfoCurso::getNombreCurso(){ return this->NombreCurso;}
float InfoCurso::getPromedio(){return this->Promedio;}
