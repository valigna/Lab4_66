#include "../include/Inscripcion.hh"

// Constructores

// Destructor

// Getters y Setters

// Otres
string Inscripcion::darNombreCurso(){
    return this->c->getNombre();
}

float Inscripcion::darAvance(){
    float res;

    int aprobados = this->colEjAprobados->size();
    int total = this->c->obtenerTotalEjercicios();

    return ((aprobados/total) * 100);

}

float Inscricpion::darAvance(int cantEj){
    if (cantEj > 0) {
        int cantAprobados = this->colEjAprobados.size();
        return ((cantAprobados/cantEj) * 100);
    } else {
        return 0;
    }
}