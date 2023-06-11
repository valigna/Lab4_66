#include "../../include/DataTypes/DataFecha.hh"

// Constructor
DataFecha::DataFecha(int dia, int mes, int anio)
{
    this->Dia = dia;
    this->Mes = mes;
    this->Anio = anio;
}

// Destructor
DataFecha::~DataFecha(){ }

// Getters
int DataFecha::getDia() { return this->Dia; }
int DataFecha::getMes() { return this->Mes; }
int DataFecha::getAnio() { return this->Anio; }