#include "../include/Inscripcion.hh"

// Constructores
Inscripcion::Inscripcion(Estudiante *est, string curso){
    //Atributos...
    this->CursoAprobado = false;
    this->FechaInscripcion = new DataFecha(21, 6, 2023);

    //PseudoAtributos...
    this->e = est;
    ControladorCurso *cc = ControladorCurso::getInstancia();
    Curso* C = cc->encontrarCurso(curso);
    this->c = C;
    C->crearLinkConInsc(this);
}

// Destructor
Inscripcion::~Inscripcion(){
    this->e->eliminarLinkE(this);
    delete this->FechaInscripcion;
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

int Inscripcion::getUltimaLeccion(){
    int res = 0;

    for(set<Leccion*>::iterator it = this->colLecAprobadas.begin(); it != this->colLecAprobadas.end(); ++it){
        int idNuevo = (*it)->getId();
        if (idNuevo > res){
            res = idNuevo;
        }
    }
    res++;

    return res;
}

// Funciones Auxliares
bool Inscripcion::aproboLeccion(Leccion* lec)
{
    // Obtengo todos los id de los ejercicios de esta leccion y creo un iterador...
    set<int> idsEjLeccion = lec->listaEjerciciosLeccion();
    set<int>::iterator itGeneral = idsEjLeccion.begin();

    // Obtengo todos los id de los ejercicios aprobados
    set<int> aprobados;
    for(set<Ejercicio *>::iterator it = this->colEjAprobados.begin(); it != this->colEjAprobados.end(); ++it)
    {
        aprobados.insert((*it)->getId());
    }

    // Corroboro que todos los ejercicios de esta leccion esten aprobados...
    while( (itGeneral != idsEjLeccion.end()) && (aprobados.find(*itGeneral) != aprobados.end())  ) // Si encontro el ejercicio y no itero sobre todas las lecciones...
    {
        ++itGeneral;
    }
    return (itGeneral == idsEjLeccion.end());
}

// Para el Caso de Uso : [Realizar Ejercicio]
set<DataEjercicio *> Inscripcion::obtenerListaEjerciciosNoAprobadosIns(){
    int idLec = this->getUltimaLeccion();
    Leccion* L = this->c->getLeccion(idLec);
    set<int> aux = L->listaEjerciciosLeccion();
    set<DataEjercicio *> res;
    // set<int> aux = this->c->obtenerListaEjerciciosCurso();
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
    Traduccion* aux2 = (Traduccion*) aux;
    if(aux != NULL){
        //cout << "Respuesta correcta" << endl;
        this->colEjAprobados.insert(aux);
        Leccion* lec = this->c->obtenerLeccionDeEjercicio(ejercicio);
        bool aprobo = this->aproboLeccion(lec);
        if(aprobo){
            //cout << "Leccion aprobada" << endl;
            this->colLecAprobadas.insert(lec);
            if(this->colLecAprobadas.size() == this->c->obtenerTotalLecciones()){
                //cout << "Curso Aprobado" << endl;
                this->setCursoAprobado(true);
            }
        }
    }
    else{
        //cout << "Respuesta incorrecta, la respuesta correcta es: " << aux2->getSolucionT() << endl;
    }
}

void Inscripcion::revisarEjercicioCP(int ejercicio, set<string> sol){
    Ejercicio* aux = this->c->buscarEjercicioEnCursoCP(ejercicio, sol);
    if(aux != NULL){
        //cout << "Respuesta correcta" << endl;
        this->colEjAprobados.insert(aux);
        Leccion* lec = this->c->obtenerLeccionDeEjercicio(ejercicio);
        bool aprobo = this->aproboLeccion(lec);
        if(aprobo){
            //cout << "Leccion aprobada" << endl;
            this->colLecAprobadas.insert(lec);
            if(this->colLecAprobadas.size() == this->c->obtenerTotalLecciones()){
                //cout << "Curso Aprobado" << endl;
                this->setCursoAprobado(true);
            }
        }
    }
    else{
        //cout << "Respuesta incorrecta" << endl;
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