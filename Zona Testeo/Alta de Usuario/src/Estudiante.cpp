#include "../include/Estudiante.hh"

// Constructores
Estudiante::Estudiante(DataUsuario* u) : Usuario(u->getNickname(),u->getNombre(),u->getContrasenia(),u->getDescripcion())
{
    DataEstudiante* est = (DataEstudiante*) u;
    this->PaisResidencia = est->getPaisResidencia();
    this->Nacimiento = est->getNacimiento();
}

// Destructor


// Getters y Setters
string Estudiante::getPaisResidencia(){ return this->PaisResidencia; }
DataFecha* Estudiante::getNacimiento(){ return this->Nacimiento; }