#include "../../include/DataTypes/DataNotificacion.hh"

// Constructores
DataNotificacion::DataNotificacion(string idi,string nomC)
{
    this->Idioma = idi;
    this->NombreCurso = nomC;
}

// Destructor
DataNotificacion::~DataNotificacion(){ }

// Getters
string DataNotificacion::getIdioma(){ return this->Idioma; }
string DataNotificacion::getNombreCurso(){ return this->NombreCurso; }

