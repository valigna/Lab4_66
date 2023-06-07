#include "../../include/DataTypes/DataCompletarPalabras.hh"

// Constructores
DataCompletarPalabras::DataCompletarPalabras(string desc, int id, string frase, set<string> sol) : DataEjercicio(desc,id)
{
    this->Frase = frase;
    this->Solucion = sol;
}

// Destructor
DataCompletarPalabras::~DataCompletarPalabras(){ }

// Getters
string DataCompletarPalabras::getFrase(){ return this->Frase; }
set<string> DataCompletarPalabras::getSolucion(){ return this->Solucion; }
