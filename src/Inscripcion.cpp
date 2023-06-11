#include "../include/Inscripcion.hh"

// Constructores

// Destructor
Inscripcion::~Inscripcion(){
    this->e->eliminarLinkE(this->darNombreCurso);
}

// Getters y Setters

void Inscripcion::setCursoAprobado(boolean curso){
    this->CursoAprobado = curso;
}

bool Inscripcion::getCursoAprobado(){
    if(this->CursoAprobado == true){
        return true;
    }
    else{
        return false;
    }
}

Curso* Inscripcion::getCurso(){
    return this->c;
}

// Para el Caso de Uso : [Realizar Ejercicio]
set<DataEjercicio *> Inscripcion::obtenerListaEjerciciosNoAprobadosIns(){
    set<DataEjercicio *> res;
    set<int> aux = this->c->obtenerListaEjerciciosCurso();
    for(set<int>::iterator it = aux.begin(); it != aux.end();++it){
        if(this->noAprobado(aux)){
            DataEjercicio* eje = this->c->buscarEjercicioEnCurso(aux);
            res.insert(eje);
        }
    }
    return res;
}

bool Inscripcion::noAprobado(int ejercicio){
    set<Ejercicio *>::iterator it = this->colEjAprobados().begin();
    bool aux = true;
    while(it != this->colEjAprobados().end() && aux != false){
        if(it->getId() == ejercicio){
            return false;
        }
        it++;
    }
    return aux;
}

void Inscripcion::revisarEjercicioT(int ejercicio, string sol){
    Ejercicio* aux = this->c->buscarEjercicioEnCursoT(ejercicio, sol);
    if(aux != NULL){
        set<Ejercicio *> ejes = this->colEjAprobados;
        ejes.insert(aux);
        Leccion* lec = this->c->comprobarUltimaLeccion(ejercicio);
        if(lec != NULL){
            set<Leccion *> lecs = this->colLecAprobadas;
            lecs.insert(lec);
            if(this->colLecAprobadas()->size() == this->c->colLecciones()->size()){
                this->setCursoAprobado(true);
            }
        }
    }
}

void Inscripcion::revisarEjercicioCP(int ejercicio, set<string> sol){
    Ejercicio* aux = this->c->buscarEjercicioEnCursoCP(ejercicio, sol);
    if(aux != NULL){
        set<Ejercicio *> ejes = this->colEjAprobados;
        ejes.insert(aux);
        Leccion* lec = this->c->comprobarUltimaLeccion(ejercicio);
        if(lec != NULL){
            set<Leccion *> lecs = this->colLecAprobadas;
            lecs.insert(lec);
            if(this->colLecAprobadas()->size() == this->c->colLecciones()->size()){
                this->setCursoAprobado(true);
            }
        }
    }
}

// Para el Caso de Uso : [Consultar Estadisticas]
int Inscripcion::cantEjAprobados(){ return this->colEjAprobados.size(); }

string Inscripcion::darNombreCurso(){ return this->c->getNombre(); }

float Inscripcion::darAvance(){
    float res;

    int aprobados = this->colEjAprobados.size();
    int total = this->c->obtenerTotalEjercicios();

    return ((aprobados/total) * 100);

}

float Inscripcion::darAvance(int cantEj){
    if (cantEj > 0) {
        int cantAprobados = this->colEjAprobados.size();
        return ((cantAprobados/cantEj) * 100);
    } else {
        return 0;
    }
}