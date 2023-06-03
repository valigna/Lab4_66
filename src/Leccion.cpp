#include "../include/Leccion.hh"

// Constructores

// Destructor
Leccion::~Leccion(){
    for(set<Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it){
        delete it;
    }
}
// Getters y Setters

// Otres

int Leccion::cantEjAprobados(){
    return this->colEjAprobados->size();
}

set<DataEjercicio *> Leccion::ejerciciosNoAprobadosLeccion(){
    set<DataEjercicio *> res;
    for(set<Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it){
        if(it->comprobarEjercicio() == false){
            DataEjercicio* aux;
            aux = it->obtenerDataEjercicio();
            res.insert(aux);
        }
    }
    return res;
}

string Leccion::buscarLetraEnLeccion(int ejercicio){
    map<int,Ejercicio *>::iterator it = this->colEjercicios->find(ejercicio);
    if(it != NULL){
        return it->gotDescripcion();
    }
    else{
        return NULL;
    }
}

// Para el Caso de Uso : [Consultar Estadisticas]
int Leccion::totalEjercicios()
{
    return this->colEjercicios->size();
}