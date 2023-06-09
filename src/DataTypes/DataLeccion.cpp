#include "../../include/DataTypes/DataLeccion.hh"

// Constructores
DataLeccion::DataLeccion(string tema, string obj, set<DataEjercicio *> ejs)
{
    this->Tema = tema;
    this->Objetivo = obj;
    this->Id = 0;
    this->Ejercicios = ejs;
}

DataLeccion::DataLeccion(string tema, string obj, int id, set<DataEjercicio *> ejs)
{
    this->Tema = tema;
    this->Objetivo = obj;
    this->Id = id;
    this->Ejercicios = ejs;
}

// Destructor
DataLeccion::~DataLeccion(){ }

// Getters
string DataLeccion::getTema(){ return this->Tema; }
string DataLeccion::getObjetivo(){ return this->Objetivo; }
int DataLeccion::getId(){ return this->Id; }
set<DataEjercicio *> DataLeccion::getEjercicios(){ return this->Ejercicios; }