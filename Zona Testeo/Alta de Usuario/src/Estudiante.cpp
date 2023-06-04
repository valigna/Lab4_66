#include "../include/Estudiante.hh"

// Constructores
Estudiante::Estudiante(string nick,string name, string pass, string desc, DataEstudiante* est) : Usuario(nick,name,pass,desc)
{
    this->PaisResidencia = est->getPaisResidencia();
    this->Nacimiento = est->getNacimiento();
}

// Destructor


// Getters y Setters
string Estudiante::getPaisResidencia(){ return this->PaisResidencia; }
DataFecha* Estudiante::getNacimiento(){ return this->Nacimiento; }