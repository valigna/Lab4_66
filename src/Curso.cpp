#include "../include/Curso.hh"

// Constructores

// Destructor
Curso::~Curso() {
    this->idioma->cursoEliminado(this->Nombre);
    this->profesor->eliminarLink(this->Nombre);
    for(set<Incripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end(); ++it){
        delete it; // Se llama el destructor de cada inscripcion
    }
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        delete it; // Se llama el destructor de cada leccion
    }
}

// Getters y Setters
string Curso::getNombre(){return this->Nombre;}

void Curso::setHabilitado(bool hab){ this->Habilitado = hab; }


// Para el Caso de Uso : [Habilitar Curso]
bool Curso::sePuedeHabilitar()
{
    bool res = true;
    if(this->colLecciones.size() >= 1)
    {
        for(list<Leccion *>::iterator it = this->colLeciones.begin(); it != this->colLecciones.end(); ++it)
        {
            if((*it)->colEjercicios.size() < 1) { res = false; }
        }
    } else
    {
        res = false;
    }
    return res;
}
// Para el Caso de Uso : [Realizar Ejercicio]
bool Curso::igualCurso(string curso){
    if(this->getNombre() == curso){
        return true;
    }
    else{
        return false;
    }
}

set<string> Curso::obtenerListaEjerciciosCurso(){
    set<string> res;
    for(map<string,Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        set<string> aux;
        aux = it->second->listaEjerciciosLeccion();
        res.insert(aux.begin(), aux.end());
    }
    return res;
}

DataEjercicio* Curso::buscarEjercicioEnCurso(string ejercicio){
    for(map<string,Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if(it->second->ejercicioEnLeccion(ejercicio) == true){
            return it->buscarEjercicioEnLeccion(ejercicio);
        }
    }
}

string Curso::buscarLetraEnCurso(int ejercicio){
    for(map<string,Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if(it->second->ejercicioEnLeccion(ejercicio) == true){
            return it->buscarLetraEnLeccion(ejercicio);
        }
    }
}

Ejercicio* Curso::buscarEjercicioEnCursoT(int ejercicio, string sol){
    for(map<string,Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if(it->second->ejercicioEnLeccion(ejercicio) == true){
            return it->second->buscarEjercicioEnLeccionT(ejercicio, sol);
        }
    }
}

Ejercicio* Curso::buscarEjercicioEnCursoCP(int ejercicio, set<string> sol){
    for(map<string,Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if(it->second->ejercicioEnLeccion(ejercicio) == true){
            return it->second->buscarEjercicioEnLeccionCP(ejercicio, sol);
        }
    }
}

Leccion* Curso::comprobarUltimaLeccion(){
    for(map<string,Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if(it->second->ejercicioEnLeccion(ejercicio) == true){
            if(it->second->ejerciciosNoAprobadosLeccion()->size() == 0){
                return it->second;
            }
            else{
                return NULL;
            }
        }
    }
}

// Para el Caso de Uso : [Consultar Estadisticas]
int Curso::obtenerTotalEjercicios()
{
    int res = 0;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        int t = (*it)->totalEjercicios();
        res += t;
    }
    return res;
}

float Curso::darPromedio()
{    
    float res = 0;
    int cantEj = 0;
    float sumAvance = 0;
    int totalInscriptos = this->colLecciones.size();

    // Itero sobre mis lecciones...
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it) {
        int cEj (*it)->totalEjercicios();
        cantEj += cEj;
    }

    // Itero sobre mis inscripciones...
    for(set<Inscricpion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        int cAp = it->cantEjAprobados();
        float avance = (cAp/cantEj) * 100;

        sumAvance += avance;
    }

    res = sumAvance/totalInscriptos;
    return res;

}

InformacionCurso* Curso::infoCurso()
{
    InformacionCurso *res = NULL;

    string nom = this->getNombre();
    string desc = this->getDescripcion();
    difficulty dificultad = this->getDifficulty();

    // Obtengo los nombres de los cursos previos...
    set<string> previos;
    for(set<Curso *>::iterator it = this->colPrevios.begin(); it != this->colPrevios.end(); ++it){
        string nomP = (*it)->getNombre();
        previos.insert(nomP);
    }

    string idi = this->idioma->getNombre();
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

    for (set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end(); ++it) {
        float av = (*it)->darAvance(cantEj);
        avances += av;
    }

    prom = avances/totalInscriptos;

    // Construyo el DataType...
    res = new InformacionCurso(nom,desc,dificultad,previos,idi,prof,cantLec,cantEj,prom);

}

