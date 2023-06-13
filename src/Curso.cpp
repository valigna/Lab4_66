#include "../include/Curso.hh"

// Constructores
Curso::Curso(){ }
// Destructor
Curso::~Curso() {
    this->Idioma->cursoEliminado(this->Nombre);
    this->Profesor->eliminarLinkP(this->Nombre);
    for(set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end(); ++it){
        delete (*it); // Se llama el destructor de cada inscripcion
    }
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        delete (*it); // Se llama el destructor de cada leccion
    }
}

// Getters
string Curso::getNombre(){ return this->Nombre; }
string Curso::getDescripcion(){ return this->Descricpion; }
difficulty Curso::getDificultad(){ return this->Dificultad; }
bool Curso::getHabilitado(){ return this->Habilitado; }
int Curso::getIdLecciones(){ return this->idLecciones; }
int Curso::getIdEjercicios(){ return this->idEjercicios; }
//Profesor* Curso::getProfesor(){ return this->Profesor; }
//Idioma* Curso::getIdioma(){ return this->Idioma; }

// Setters
void Curso::setHabilitado(bool hab){ this->Habilitado = hab; }

// Auxiliares
string Curso::getNombreIdioma(){ return this->Idioma->getNombre(); }
int Curso::obtenerTotalLecciones(){ return this->colLecciones.size(); }

// DataTypes
InformacionCurso* Curso::getInformacionCurso(bool conPromedio)
{
    string nom = this->getNombre();
    string desc = this->getDescripcion();
    difficulty dificultad = this->getDificultad();

    // Obtengo los nombres de los cursos previos...
    set<string> previos;
    for(set<Curso *>::iterator it = this->colPrevios.begin(); it != this->colPrevios.end(); ++it)
    {
        string nomP = (*it)->getNombre();
        previos.insert(nomP);
    }

    string idi = this->Idioma->getNombre();
    string prof = this->Profesor->getNombre();
    
    int cantLec = this->colLecciones.size();
    int cantEj = 0;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it) 
    {
        int cEj;
        cEj = (*it)->totalEjercicios();
        cantEj += cEj;
    }

    float prom = 0;
    if(conPromedio)
    {
        // Obtengo el avance del curso...
        float avances = 0;
        int totalInscriptos = this->colInscripciones.size();

        for (set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end(); ++it) 
        {
            float av = (*it)->darAvance(cantEj);
            avances += av;
        }
    prom = avances/totalInscriptos;
    }

    // Construyo el DataType...
    return new InformacionCurso(nom,desc,dificultad,previos,idi,prof,cantLec,cantEj,prom);
}

InformacionCurso* Curso::getDatosCurso()
{
    string nom = this->getNombre();
    string desc = this->getDescripcion();
    difficulty dificultad = this->getDificultad();
    string idi = getNombreIdioma();
    int cantL = obtenerTotalLecciones();
    int cantE = obtenerTotalEjercicios();

    // Construyo el DataType...
    return new InformacionCurso(nom, desc, dificultad, idi, cantL, cantE);
}

DataConsultaCurso* Curso::getDataConsultaCurso()
{
    string nom = this->getNombre();
    string desc = this->getDescripcion();
    difficulty diff = this->getDificultad();
    string idi = this->getNombreIdioma();
    string prof = this->Profesor->getNombre();
    bool habil = this->getHabilitado();
    return new DataConsultaCurso(nom,desc,diff,idi,prof,habil);
}


set<DataLeccion *> Curso::darDataLecciones(bool conId)
{
    set<DataLeccion *> res;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it)
    {
        res.insert((*it)->getDataLeccion(conId));
    }
    return res;
}
// Para el Caso de Uso : [Habilitar Curso]
/* bool Curso::sePuedeHabilitar()
{
    bool res = true;
    if(this->colLecciones.size() >= 1)
    {
        for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it)
        {
            if((*it)->colEjercicios.size() < 1) { res = false; }
        }
    } else
    {
        res = false;
    }
    return res;
} */
bool Curso::sePuedeHabilitar()
{
    return true;
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

set<int> Curso::obtenerListaEjerciciosCurso(){
    set<int> res;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        set<int> aux;
        aux = (*it)->listaEjerciciosLeccion();
        res.insert(aux.begin(), aux.end());
    }
    return res;
}

DataEjercicio* Curso::buscarEjercicioEnCurso(int ejercicio){
    DataEjercicio* res;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if((*it)->ejercicioEnLeccion(ejercicio) == true)
        {
            res = (*it)->buscarEjercicioEnLeccion(ejercicio);
        }
    }
    return res;
}

string Curso::buscarLetraEnCurso(int ejercicio){
    string res;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if((*it)->ejercicioEnLeccion(ejercicio) == true){
            res = (*it)->buscarLetraEnLeccion(ejercicio);
        }
    }
    return res;
}

Ejercicio* Curso::buscarEjercicioEnCursoT(int ejercicio, string sol){
    Ejercicio* res;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if((*it)->ejercicioEnLeccion(ejercicio) == true){
            res = (*it)->buscarEjercicioEnLeccionT(ejercicio, sol);
        }
    }
    return res;
}

Ejercicio* Curso::buscarEjercicioEnCursoCP(int ejercicio, set<string> sol){
    Ejercicio* res;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if((*it)->ejercicioEnLeccion(ejercicio) == true){
            res = (*it)->buscarEjercicioEnLeccionCP(ejercicio, sol);
        }
    }
    return res;
}

Leccion* Curso::comprobarUltimaLeccion(int ejercicio){ 
    Leccion* res;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if((*it)->ejercicioEnLeccion(ejercicio) == true){
            if((*it)->totalEjercicios() == ejercicio){
                res = (*it);
            }
            else{
                res = NULL;
            }
        }
    }
    return res;
}

// Para el Caso de Uso : [Agregar Ejercicio]
void Curso::agregarEjercicio(int leccionSeleccionada,DataEjercicio* ejercicio)
{
    list<Leccion *>::iterator it = this->colLecciones.begin();
    bool encontrada = false;
    while((!encontrada) && (it != this->colLecciones.end()))
    {
        if(leccionSeleccionada == (*it)->getId())
        {
            (*it)->agregarEjercicio(ejercicio);
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
        int cEj = (*it)->totalEjercicios();
        cantEj += cEj;
    }

    // Itero sobre mis inscripciones...
    for(set<Inscripcion *>::iterator it = this->colInscripciones.begin(); it != this->colInscripciones.end();++it){
        int cAp = (*it)->cantEjAprobados();
        float avance = (cAp/cantEj) * 100;

        sumAvance += avance;
    }

    res = sumAvance/totalInscriptos;
    return res;

}


// Para el caso de uso: [Inscribirse a curso]
/* bool Curso::previosAprobados(set<string> nombresCursosAprobados){
    bool b = true;
    for(set<Curso *>::iterator it = this->colPrevios.begin(); it != this->colPrevios.end(); ++it){
        if (nombresCursosAprobados.find(it) == nombresCursosAprobados.end()){
            b = false;
        }
    }
    return b;
} */
bool Curso::previosAprobados(set<string> nombresCursosAprobados)
{
    return true;
}
void Curso::crearLinkConInsc(Inscripcion *I)
{
    this->colInscripciones.insert(I);
}