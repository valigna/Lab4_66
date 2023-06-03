#include "../../include/DataTypes/InfoCursoProf.hh"

// Constructores
InfoCursoProf::InfoCursoProf(string nomC,float prom){
    this->NombreCurso = nomC;
    this->Promedio = prom;
}

// Destructor
InfoCursoProf::~InfoCursoProf(){ }

// Getters
string InfoCursoProf::getNombreCurso(){ return this->NombreCurso;}
float InfoCursoProf::getPromedio(){return this->Promedio;}
