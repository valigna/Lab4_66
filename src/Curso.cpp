#include "../include/Curso.hh"

// Constructores
Curso::Curso(DTCurso* datosCurso,string nickProfesor){
    this->Nombre = datosCurso->getNombre();
    this->Descricpion = datosCurso->getDescripcion();
    this->Dificultad = datosCurso->getDifificulty();
    this->Habilitado = false;
    this->idEjercicios = 0;
    this->idLecciones = 0;
    ControladorUsuario* cu = ControladorUsuario::getInstancia();
    Usuario* usuarioP = cu->findUsuario(nickProfesor);
    this->profesor = (Profesor *) usuarioP;
}

// Destructor
Curso::~Curso() {
    this->idioma->cursoEliminado(this->Nombre);
    this->profesor->eliminarLinkP(this->Nombre);
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
Leccion* Curso::getLeccion(int idLec)
{
    list<Leccion *>::iterator it = this->colLecciones.begin();
    while((*it)->getId() != idLec){
        ++it;
    }
    return *it;
};

//Profesor* Curso::getProfesor(){ return this->Profesor; }
//Idioma* Curso::getIdioma(){ return this->Idioma; }

// Setters
void Curso::setHabilitado(bool hab){ this->Habilitado = hab; }
void Curso::setIdioma(Idioma *i){ this->idioma = i; }


// Auxiliares
string Curso::getNombreIdioma(){ return this->idioma->getNombre(); }
int Curso::obtenerTotalLecciones(){ return this->colLecciones.size(); }

// DataTypes
InformacionCurso* Curso::getInformacionCurso(bool conPromedio)
{
    string nom = this->Nombre;
    string desc = this->Descricpion;
    difficulty dificultad = this->Dificultad;
    bool habi = this->Habilitado;

    // Obtengo los nombres de los cursos previos...
    set<string> previos;
    for(set<Curso *>::iterator it = this->colPrevios.begin(); it != this->colPrevios.end(); ++it)
    {
        string nomP = (*it)->getNombre();
        previos.insert(nomP);
    }

    string idi = this->idioma->getNombre();
    string prof = this->profesor->getNombre();
    
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
    return new InformacionCurso(nom,desc,dificultad,habi,previos,idi,prof,cantLec,cantEj,prom);
}

InformacionCurso* Curso::getDatosCurso()
{
    string nom = this->getNombre();
    string desc = this->getDescripcion();
    difficulty dificultad = this->getDificultad();
    bool habilitado = this->Habilitado;
    string idi = getNombreIdioma();
    int cantL = obtenerTotalLecciones();
    int cantE = obtenerTotalEjercicios();

    // Construyo el DataType...
    return new InformacionCurso(nom, desc, dificultad,habilitado, idi, cantL, cantE);
}

DataConsultaCurso* Curso::getDataConsultaCurso()
{
    string nom = this->getNombre();
    string desc = this->getDescripcion();
    difficulty diff = this->getDificultad();
    string idi = this->getNombreIdioma();
    string prof = this->profesor->getNombre();
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
bool Curso::sePuedeHabilitar()
{
    bool res = true;
    if(this->colLecciones.size() >= 1)
    {
        for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it)
        {
            if((*it)->totalEjercicios() < 1) { res = false; }
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

set<int> Curso::obtenerListaEjerciciosCurso(Leccion* ultima){
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

Ejercicio* Curso::encontrarEjercicioEnCurso(int ejercicio){
    Ejercicio* res;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); it++){
        if((*it)->ejercicioEnLeccion(ejercicio) == true){
            res = (*it)->encontrarEjercicioEnLeccion(ejercicio);
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

Leccion* Curso::obtenerLeccionDeEjercicio(int ejercicio){ 
    Leccion* res = NULL;
    for(list<Leccion *>::iterator it = this->colLecciones.begin(); it != this->colLecciones.end(); ++it){
        if((*it)->ejercicioEnLeccion(ejercicio) == true){
            res = (*it);
        }
    }
    return res;
}
// Para el Caso de Uso : [Agregar Leccion]

DataEjercicio* Curso::obtenerIdEjercicio(DataEjercicio* ejercicio){
    this->idEjercicios++;
    DataEjercicio* res;
    if(ejercicio->esCompletarPalabras())
    {
        DataCompletarPalabras* dtCP = (DataCompletarPalabras*) ejercicio;
        res = new DataCompletarPalabras(dtCP->getDescripcion(),this->idEjercicios,dtCP->getFrase(),dtCP->getSolucion());
        delete dtCP;
    } else
    {
        DataTraduccion* dtT = (DataTraduccion*) ejercicio;
        res = new DataTraduccion(dtT->getDescripcion(), this->idEjercicios, dtT->getFrase(), dtT->getTraduccion());
        delete dtT;
    }
    return res;
}


void Curso::agregarLeccion(string tema, string obj, set<DataEjercicio*> ejs){
    this->idLecciones++;
    this->colLecciones.push_back(new Leccion(tema,obj,this->idLecciones,ejs));
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
            this->idEjercicios++;
            (*it)->agregarEjercicio(this->idEjercicios,ejercicio);
            encontrada = true;
        } else
        {
            ++it;
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
bool Curso::previosAprobados(set<string> nombresCursosAprobados){
    bool b = true;
    for(set<Curso *>::iterator it = this->colPrevios.begin(); it != this->colPrevios.end(); ++it){
        string nombreCurso = (*it)->getNombre();
        if (nombresCursosAprobados.find(nombreCurso) == nombresCursosAprobados.end()){
            b = false;
        }
    }
    return b;
}

void Curso::crearLinkConInsc(Inscripcion *I)
{
    this->colInscripciones.insert(I);
}

/* void Curso::agregarLeccion(string tema, string objetivo, set<DataEjercicio *> ejercicios)
{
    this->idLecciones++;
    this->colLecciones.push_back(new Leccion(tema, objetivo, this->idLecciones, ejercicios));
} */
void Curso::ingresarPrevia(Curso* cursoPrevio) { this->colPrevios.insert(cursoPrevio); }

void Curso::notificarNuevoCurso(Idioma* idiomaCurso)
{
    idiomaCurso->nuevoCurso(this);
}

// Para el caso de Uso : [Eliminar Curso]
void Curso::eliminarPrevio(string nombreCurso)
{
    for(set<Curso *>::iterator it = this->colPrevios.begin(); it != this->colPrevios.end(); ++it)
    {
        if ((*it)->getNombre() == nombreCurso)
        {
            colPrevios.erase(it);
            break;
        }
    }
}