#include "../include/Leccion.hh"

// Constructores
Leccion::Leccion(DataLeccion* datosLeccion){
    this->Tema = datosLeccion->getTema();
    this->Objetivo = datosLeccion->getObjetivo();
    map<int, DataEjercicio*> ejercicios;
    
/*     for (map<int, DataEjercicio*>::iterator it = datosLeccion->getEjercicios().begin(); it != datosLeccion->getEjercicios().end(); ++it)
    {
        ejercicios.emplace(it->first, it->second);
    } */
/*     for(set<DataEjercicio *>::iterator it = datosLeccion->getEjercicios().begin(); it != datosLeccion->getEjercicios().end(); ++it)
    {
        ejercicios.emplace((*it)->getId(),)
    } */   
}

Leccion::Leccion(string tema, string obj, int id, set<DataEjercicio*> ejs){
    this->Tema = tema;
    this->Objetivo = obj;
    this->Id = id;
    for(set<DataEjercicio *>::iterator it = ejs.begin(); it != ejs.end(); ++it){
        DataEjercicio* ej = (*it);
        if(ej->esCompletarPalabras())
        {
            this->colEjercicios.emplace(ej->getId(),new CompletarPalabras(ej->getId(),ej));
        } else
        {
            this->colEjercicios.emplace(ej->getId(), new Traduccion(ej->getId(), ej));
        }
        
    }
}

/* Ejercicio::Ejercicio(int idEj, string desc)
{
    this->id = idEj;
    this->Descripcion = desc;
} */
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
int Leccion::getId(){
    return this->Id;
}
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
void Leccion::agregarEjercicio(int idEj, DataEjercicio* ejercicio)
{
    if(ejercicio->esTraduccion())
    {
        this->colEjercicios.emplace(idEj,new Traduccion(idEj,ejercicio));
    } else
    {
        this->colEjercicios.emplace(idEj,new CompletarPalabras(idEj,ejercicio));
    }
    
}

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
    return it->second->getDataEjercicio();
}

Ejercicio* Leccion::encontrarEjercicioEnLeccion(int ejercicio){
    map<int,Ejercicio *>::iterator it = this->colEjercicios.find(ejercicio);
    return it->second;
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