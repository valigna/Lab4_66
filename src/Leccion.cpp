#include "../include/Leccion.hh"

// Constructores

// Destructor
Leccion::~Leccion(){
    for(map<int, Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it){
        //delete it->second;
        bool esTraduccion = it->second->esTraduccion();
        if (esTraduccion)
        {
            Traduccion* t = (Traduccion*) it->second;
            delete t;
        } else
        {
            CompletarPalabras* cp = (CompletarPalabras*) it->second;
            delete cp;
        }
    }
}
// Getters y Setters

// DataTypes
DataLeccion* Leccion::getDataLeccion(bool conId)
{
    DataLeccion* res;
    set<DataEjercicio *> ejercicios;
    for(map<int,Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it)
    {
        ejercicios.insert(it->second->getDataEjercicio());
    }
    if(conId)
    {
        res = new DataLeccion(this->Tema,this->Objetivo,this->Id,ejercicios);
    } else
    {
        res = new DataLeccion(this->Tema,this->Objetivo,ejercicios);
    }
    return res;
}

// Otres

/* int Leccion::cantEjAprobados(){ // No esta en el .hh
    return 0;
    //return this->colEjAprobados->size();
} */

// Para el Caso de Uso : [Agregar Ejercicio]
void agregarEjercicio(DataEjercicio* ejercicio)
{

}// Me olvide de ir pasandole como parametro la nueva id de ejercicio a Asignar...

// Para el Caso de Uso : [Realizar Ejercicio]
set<int> Leccion::listaEjerciciosLeccion(){
    set<int> res;
    for(map<int, Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it){
        int aux = it->second->getId();
        res.insert(aux);
    }
    return res;
}

bool Leccion::ejercicioEnLeccion(int ejercicio){
    bool res = false;
    for(map<int, Ejercicio *>::iterator it = this->colEjercicios.begin(); it != this->colEjercicios.end(); ++it){
        if(it->second->getId() == ejercicio){
            return true;
        }
    }
    return res;
}

DataEjercicio* Leccion::buscarEjercicioEnLeccion(int ejercicio){
    map<int,Ejercicio *>::iterator it = this->colEjercicios.find(ejercicio);
    return it->second->obtenerDataEjercicio();
}

string Leccion::buscarLetraEnLeccion(int ejercicio){
    map<int,Ejercicio *>::iterator it = this->colEjercicios.find(ejercicio);
    return it->second->getDescripcion();
}

Ejercicio* Leccion::buscarEjercicioEnLeccionT(int ejercicio, string sol){
    map<int,Ejercicio *>::iterator it = this->colEjercicios.find(ejercicio);
    Traduccion* tra = dynamic_cast<Traduccion *>(it->second);
    if(tra->comprobarSolucionT(sol)){
        return it->second;
    }
    else{
        return NULL;
    }
}

Ejercicio* Leccion::buscarEjercicioEnLeccionCP(int ejercicio, set<string> sol){
    map<int,Ejercicio *>::iterator it = this->colEjercicios.find(ejercicio);
    CompletarPalabras* cp = dynamic_cast<CompletarPalabras *>(it->second);
    if(cp->comprobarSolucionCP(sol)){
        return it->second;
    }
    else{
        return NULL;
    }
}

// Para el Caso de Uso : [Consultar Estadisticas]
int Leccion::totalEjercicios(){ return this->colEjercicios.size(); }