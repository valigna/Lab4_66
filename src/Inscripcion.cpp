#include "../include/Inscripcion.hh"

// Constructores

// Destructor
Inscripcion::~Inscripcion(){
    this->e->eliminarLinkE(this->darNombreCurso);
}

// Getters y Setters

// 
bool Inscripcion::getCursoAprobado(){
    if(this->CursoAprobado == true){
        return true;
    }
    else{
        return false;
    }
}

Curso* getCurso(){
    return this->c;
}

set<DataEjercicio *> obtenerListaEjerciciosNoAprobadosIns(){
    return this->c->obtenerListaEjerciciosNoAprobadosCurso();
}

// Para el Caso de Uso : [Consultar Estadisticas]
int Inscripcion::cantEjAprobados()
{
    return this->colEjAprobados.size();
}

string Inscripcion::darNombreCurso()
{
    return this->c->getNombre();
}

float Inscripcion::darAvance(){
    float res;

    int aprobados = this->colEjAprobados->size();
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