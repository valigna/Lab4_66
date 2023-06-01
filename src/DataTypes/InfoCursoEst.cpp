#include "../../include/DataTypes/InfoCursoEst.hh"

// Constructores
InfoCursoEst::InfoCursoEst(string NomC,float Avance){
    this->NombreCurso = NomC;
    this->Avance = Avance;
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