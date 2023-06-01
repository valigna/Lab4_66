#include "../include/Curso.hh"

// Constructores

// Destructor

// Getters y Setters
string Curso::getNombre(){return this->Nombre;}

// Otres
int Curso::obtenerTotalEjercicios(){
    int res = 0;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        int t = (*it)->totalEjercicios();
        res += t;
    }
    return res;
}

float Curso::darPromedio(){
    
    float res = 0;
    int cantEj = 0;
    float sumAvance = 0;
    int totalInscriptos = this->colLecciones.size();

    // Itero sobre mis lecciones...
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it) {
        int cEj = (*it)->totalEjercicios();
        cantEj += cEjj;
    }

    // Itero sobre mis inscricpiones...
    for(map<string,Incripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        int cAp = (*it)->cantEjAprobados();
        float avance = (cAp/cantEj) * 100;

        sumAvance += avance;
    }

    res = sumAvance/totalInscriptos;
    return res;

}

InformacionCurso* Curso::infoCurso(){
    string nom = this->getNombre();
    string desc = this->getDescripcion();
    difficulty dificultad = this->getDifficulty();

    // Obtengo los nombres de los cursos previos...
    set<string> nomCursosPrevios;
    for(set<Curso *>::iterator it = this->colPrevios.begin(); it != this->colPrevios.end(); ++it){
        string nomP = (*it)->getNombre();
        nomCursosPrevios.insert(nomP);
    }

    string id = this->idioma->getNombre();
    string prof = this->profesor->getNombre();
    
    int cantLec = this->colLecciones.size();
    int cantEj = 0;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it) {
        cEj = (*it)->totalEjercicios();
        cantEj += cEj;
    }

    // Obtengo el avance del curso...
    float prom = 0;
    float avances = 0;
    int totalInscriptos = this->colInscripciones->size();

    for (map<string,Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end(); ++it) {
        float av = darAvance(cantEj);
        avances += av;
    }

    prom = avances/totalInscriptos;

    // Construyo el DataType...
    InformacionCurso res = new InformacionCurso(nom,desc,dificultad,nomCursosPrevios,id,prof,cantLec,cantEj,prom);

}

bool Curso::igualCurso(string curso){
    if(this->getNombre == curso){
        return true;
    }
    else{
        return false;
    }
}

set<DataEjercicio *> Curso::obtenerListaEjerciciosNoAprobadosCurso(){
    set<DataEjercicio *> res;
    for(map<string,Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        set<DataEjercicio *> aux;
        aux = it->ejerciciosNoAprobadosLeccion();
        res.insert(aux);
    }
    return res;
}

string Curso::buscarLetraEnCurso(int ejercicio){
    for(map<string,Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if(it->buscarLetraEnLeccion(ejercicio) != NULL){
            return it->buscarLetraEnLeccion(ejercicio);
        }
    }
}