#include "../include/Inscripcion.hh"

// Constructores
Inscripcion::Inscripcion(Estudiante *est, string curso){
    //Atributos...
    this->CursoAprobado = false;
    //FALTA FECHA

    //PseudoAtributos...
    this->e = est;
    ControladorCurso *cc = ControladorCurso::getInstancia();
    Curso *C = cc->encontrarCurso(curso);
    this->c = C;
    C->crearLinkConInsc(this);
}

// Destructor
Inscripcion::~Inscripcion(){
    this->e->eliminarLinkE(this);
}


// Getters y Setters

DataFecha* Inscripcion::getFechaInscripcion(){ return this->FechaInscripcion; }

void Inscripcion::setCursoAprobado(bool curso){
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
        if(this->noAprobado((*it))){
            DataEjercicio* eje = this->c->buscarEjercicioEnCurso((*it));
            res.insert(eje);
        }
    }
    return res;
}

bool Inscripcion::noAprobado(int ejercicio){
    set<Ejercicio *>::iterator it = this->colEjAprobados.begin();
    bool aux = true;
    while(it != this->colEjAprobados.end() && aux != false){
        if((*it)->getId() == ejercicio){
            return false;
        }
        it++;
    }
    return aux;
}

void Inscripcion::revisarEjercicioT(int ejercicio, string sol){
    Ejercicio* aux = this->c->buscarEjercicioEnCursoT(ejercicio, sol);
    if(aux != NULL){
        cout << "Respuesta correcta" << endl;
        this->colEjAprobados.insert(aux);
        Leccion* lec = this->c->comprobarUltimaLeccion(ejercicio);
        if(lec != NULL){
            cout << "Leccion aprobada" << endl;
            this->colLecAprobadas.insert(lec);
            if(this->colLecAprobadas.size() == this->c->obtenerTotalLecciones()){
                cout << "Curso Aprobado" << endl;
                this->setCursoAprobado(true);
            }
        }
    }
    else{
        cout << "Respuesta incorrecta" << endl;
    }
}

void Inscripcion::revisarEjercicioCP(int ejercicio, set<string> sol){
    Ejercicio* aux = this->c->buscarEjercicioEnCursoCP(ejercicio, sol);
    if(aux != NULL){
        cout << "Respuesta correcta" << endl;
        this->colEjAprobados.insert(aux);
        Leccion* lec = this->c->comprobarUltimaLeccion(ejercicio);
        if(lec != NULL){
            cout << "Leccion aprobada" << endl;
            this->colLecAprobadas.insert(lec);
            if(this->colLecAprobadas.size() == this->c->obtenerTotalLecciones()){
                cout << "Curso Aprobado" << endl;
                this->setCursoAprobado(true);
            }
        }
    }
    else{
        cout << "Respuesta incorrecta" << endl;
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