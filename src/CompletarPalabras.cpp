#include "../include/CompletarPalabras.hh"

// Constructores
CompletarPalabras::CompletarPalabras(string frase, set<string> solucion)
{
    this->frase = frase;
    this->solucion = solucion;
}

CompletarPalabras::CompletarPalabras(int idEj, DataEjercicio* ejercicio) : Ejercicio(idEj,ejercicio->getDescripcion())
{
    DataCompletarPalabras* cp = (DataCompletarPalabras*) ejercicio;
    this->frase = cp->getFrase();
    this->solucion = cp->getSolucion();
}

// Destructor
CompletarPalabras::~CompletarPalabras(){ }

// Getters y Setters
string CompletarPalabras::getFraseCP(){ return this->frase; }
set<string> CompletarPalabras::getSolucionCP(){ return this->solucion; }

// DataTypes
DataEjercicio* CompletarPalabras::getDataEjercicio()
{
    return (new DataCompletarPalabras(this->getDescripcion(),this->getId(),this->frase,this->solucion));
}

// Para distinguir entre las distintas sub-clases
bool CompletarPalabras::esCompletarPalabras(){ return true; }
bool CompletarPalabras::esTraduccion(){ return false; }

// Para el Caso de Uso : [Realizar Ejercicio]
bool CompletarPalabras::comprobarSolucionCP(set<string> sol){
    bool res = true;
    set<string>::iterator aux = sol.begin();
    for(set<string>::iterator it = this->solucion.begin(); it != this->solucion.end(); ++it){
        if((*it) != (*aux)){
            return false;
        }
        aux++;
    }
    return res;
}