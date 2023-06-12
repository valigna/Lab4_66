#include "../../include/DataTypes/DataTraduccion.hh"

// Constructores
DataTraduccion::DataTraduccion(string desc, int id, string frase, string trad) : DataEjercicio(desc,id)
{
    this->Frase = frase;
    this->Traduccion = trad;
}

// Destructor
DataTraduccion::~DataTraduccion(){ }

// Getters
string DataTraduccion::getFrase(){ return this->Frase; }
string DataTraduccion::getTraduccion(){ return this->Traduccion; }

// Para distinguir entre las distintas sub-clases
bool DataTraduccion::esCompletarPalabras(){ return false; }
bool DataTraduccion::esTraduccion(){ return true; }