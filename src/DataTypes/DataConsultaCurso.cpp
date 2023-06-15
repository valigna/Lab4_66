#include "../../include/DataTypes/DataConsultaCurso.hh"

// Constructores
DataConsultaCurso::DataConsultaCurso(string name, string desc, difficulty diff, string idi, string prof, bool habil)
{
    this->Nombre = name;
    this->Descricpion = desc;
    this->Dificultad = diff;
    this->Idioma = idi;
    this->profesor = prof;
    this->habilitado = habil;
}

// Destructor
DataConsultaCurso::~DataConsultaCurso(){ }

// Getters
string DataConsultaCurso::getNombre(){ 
    return this->Nombre; 
}
string DataConsultaCurso::getDescripcion(){ 
    return this->Descricpion; 
}
difficulty DataConsultaCurso::getDifificulty(){ 
    return this->Dificultad; 
}
string DataConsultaCurso::getIdioma(){ 
    return this->Idioma; 
}
string DataConsultaCurso::getProfesor(){ 
    return this->profesor; 
}
bool DataConsultaCurso::getHabilitado(){ 
    return this->habilitado; 
}