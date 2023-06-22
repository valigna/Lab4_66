#include "../../include/DataTypes/DataInscripto.hh"
#include "../../include/DataTypes/DataFecha.hh"

// Constructor
DataInscripto::DataInscripto(string nombre, DataFecha* fecha)
{
    this->nombre = nombre;
    this->fecha = fecha;
}

// Destructor
DataInscripto::~DataInscripto(){ }

// Getters
string DataInscripto::getNombre(){
    return this->nombre;
}
DataFecha* DataInscripto::getFecha(){
    return this->fecha;
}