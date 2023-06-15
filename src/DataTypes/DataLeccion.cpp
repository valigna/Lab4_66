#include "../../include/DataTypes/DataLeccion.hh"

// Constructores
DataLeccion::DataLeccion(string tema, string obj, map<int, DataEjercicio *> ejs)
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
map<int, DataEjercicio *> DataLeccion::getEjercicios(){ return this->Ejercicios; }