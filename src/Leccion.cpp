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

// Para el Caso de Uso : [Realizar Ejercicio]
set<DatosEjercicio *> Leccion::ejerciciosNoAprobadosLeccion(){
    set<DatosEjercicio *> res;
    for(set<Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it){
        if(it->comprobarEjercicio() == false){
            DatosEjercicio* aux;
            aux = it->obtenerDataEjercicio();
            res.insert(aux);
        }
    }
    return res;
}

bool Leccion::ejercicioEnLeccion(int ejercicio){
    bool res = false;
    for(set<Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it){
        if(it->getId() == ejercicio){
            return true;
        }
    }
    return res;
}

string Leccion::buscarLetraEnLeccion(int ejercicio){
    map<int,Ejercicio *>::iterator it = this->colEjercicios->find(ejercicio);
    return it->second->getDescripcion();
}

Ejercicio* Leccion::buscarEjercicioEnLeccionT(int ejercicio, string sol){
    map<int,Traduccion *>::iterator it = this->colEjerciciosT->find(ejercicio);
    if(it->second->comprobarSolucionT(sol)){
        return it->second;
    }
    else{
        return NULL;
    }
}

Ejercicio* Leccion::buscarEjercicioEnLeccionCP(int ejercicio, set<string> sol){
    map<int,CompletarPalabra *>::iterator it = this->colEjerciciosT->find(ejercicio);
    if(it->second->comprobarSolucionCP(sol)){
        return it->second;
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