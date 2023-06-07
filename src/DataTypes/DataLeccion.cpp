#include "../../include/DataTypes/DataLeccion.hh"

// Constructores
DataLeccion::DataLeccion(string tema, string obj, set<DataEjercicio *> ejs)
{
    this->Tema = tema;
    this->Objetivo = obj;
    this->Ejercicios = ejs;
}

// Destructor
DataLeccion::~DataLeccion(){ }

// Getters
string DataLeccion::getTema(){ return this->Tema; }
string DataLeccion::getObjetivo(){ return this->Objetivo; }
set<DataEjercicio *> DataLeccion::getEjercicios(){ return this->Ejercicios; }