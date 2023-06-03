#include "../../include/DataTypes/InfoCursoEst.hh"

// Constructores
InfoCursoEst::InfoCursoEst(string nomC,float avance){
    this->NombreCurso = nomC;
    this->Avance = avance;
}

// Destructores
InfoCursoEst::~InfoCursoEst(){ }

// Getters
string InfoCursoEst::getNombreCurso(){
    return this->NombreCurso;
}

float InfoCursoEst::getAvance(){
    return this->Avance;
}