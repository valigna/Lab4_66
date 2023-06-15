#include "../include/Traduccion.hh"

// Constructor
/* Traduccion::Traduccion(string fra, string sol):Ejercicio(){
    this->frase = fra;
    this->solucion = sol;
}  */

Traduccion::Traduccion(int idEj, DataEjercicio* ejercicio) : Ejercicio(idEj,ejercicio->getDescripcion())
{
    DataTraduccion* trad = (DataTraduccion*) ejercicio;
    this->frase = trad->getFrase();
    this->solucion = trad->getTraduccion();
}

// Destructor
Traduccion::~Traduccion(){ }

// Getters y Setters
string Traduccion::getFraseT(){ return this->frase; }
string Traduccion::getSolucionT(){ return this->solucion; }

// DataTypes
DataEjercicio* Traduccion::getDataEjercicio()
{
    return (new DataTraduccion(this->getDescripcion(),this->getId(),this->frase,this->solucion));
}

// Para distinguir entre las distintas sub-clases
bool Traduccion::esCompletarPalabras(){ return false; }
bool Traduccion::esTraduccion(){ return true; }

// Para el Caso de Uso : [Realizar Ejercicio]
bool Traduccion::comprobarSolucionT(string sol){
    if(this->getSolucionT() == sol)
    {
        return true;
    }
    else
    {
        return false;
    }
}