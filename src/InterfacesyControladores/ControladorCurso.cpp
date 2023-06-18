#include "../../include/InterfacesyControladores/ControladorCurso.hh"

// Destructor
ControladorCurso::~ControladorCurso(){ }
// Getters y Setters

// Implementacion del Patron de Disenio : Singleton
ControladorCurso* ControladorCurso::instancia = NULL;
ControladorCurso::ControladorCurso(){ }
 
ControladorCurso* ControladorCurso::getInstancia()
{
    if (ControladorCurso::instancia == NULL)
    {
        ControladorCurso::instancia = new ControladorCurso();
    }
    return ControladorCurso::instancia;
}

// Getters
Idioma* ControladorCurso::darIdiomaEnColeccion(string nombre)
{
    Idioma* res;
    map<string,Idioma *>::iterator it = this->colIdiomas.find(nombre);
    if(it != this->colIdiomas.end())
    {
        res = it->second;
    } else
    {
        res = NULL;
    }
    return res;
}


// Para el Caso de Uso : [Alta de Usuario]
Idioma* ControladorCurso::obtenerIdioma(string nombre)
{
    Idioma* res;
    map<string, Idioma*>::iterator it = this->colIdiomas.find(nombre);
    if (it != this->colIdiomas.end())
    {
        res = it->second;
    } else
    {
        res = NULL;
    }
    return res;
}

// Para el Caso de Uso : [Alta de idioma]
bool ControladorCurso::altaIdioma(string nombre)
{
    // Se corrobora si ya existia un idioma de nombre 'nombre'...
    bool altaExitosa = false;
    if(this->colIdiomas.find(nombre) == this->colIdiomas.end())
    {
        this->colIdiomas.emplace(nombre,new Idioma(nombre));
        altaExitosa = true;
    }
    return altaExitosa;

}

// Para el Caso de Uso : [Consultar Idiomas]
set<string> ControladorCurso::getIdiomas()
{
    set<string> res;
    for(map<string,Idioma *>::iterator it = this->colIdiomas.begin(); it != this->colIdiomas.end(); ++it)
    {
        res.insert(it->first);
    }
    return res;
}

// Para el Caso de Uso : [Alta de Curso]

set<string> ControladorCurso::getNicknamesProfesores()
{
    ControladorUsuario *cu = ControladorUsuario::getInstancia();
    set<string> res = cu->darNicksProfesores();
    return res;
}

 void ControladorCurso::ingresarDataCurso(string profesor, DTCurso* curso) {
    this->idLeccion = 0;
    this->idEjercicio = 0;
    this->previos.clear();
    this->Ejs.clear();
    this->Lecciones.clear();    
    this->seleccionado = curso;
    this->nickProfesor = profesor;
 }

set<string> ControladorCurso::getIdiomasProfesor()
{
    ControladorUsuario* cu = ControladorUsuario::getInstancia();
    string nickProfesor = this->nickProfesor;
    DataUsuario* p = cu->getDatosUsuario(nickProfesor);
    DataProfesor* prof = dynamic_cast<DataProfesor*>(p);
    set<string> res = prof->getIdiomas();
    return res;
}

void ControladorCurso::agregarIdiomaCurso(string idioma)
{
    this->idiomaCurso = idioma;
}

set<string> ControladorCurso::getNombreCursosHabilitados()
{   
    set<string> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it) {
        if (it->second->getHabilitado())
        {
            res.insert(it->first);
        }
    }
    return res;
}

void ControladorCurso::ingresarCursosPrevios(set<string> previos){ this->previos = previos; }
void ControladorCurso::ingresarLeccionParaAlta(string tema, string objetivo) {
    this->idLeccion++;
    this->temaLeccion = tema;
    this->objLeccion = objetivo;
}
void ControladorCurso::ingresarEjercicioParaAlta(DataEjercicio* ejercicio){ 
    this->idEjercicio++;
    DataEjercicio* ej;
    if(ejercicio->esCompletarPalabras())
    {
        DataCompletarPalabras* dt = (DataCompletarPalabras*) ejercicio;
        ej = new DataCompletarPalabras(dt->getDescripcion(),this->idEjercicio,dt->getFrase(),dt->getSolucion());
        delete dt;
    } else
    {
        DataTraduccion* dt = (DataTraduccion*) ejercicio;
        ej = new DataTraduccion(ejercicio->getDescripcion(), this->idEjercicio, dt->getFrase(), dt->getTraduccion());
        delete dt;
    }
    this->Ejs.insert(ej);
}

void ControladorCurso::confirmarLeccion() {
    set<DataEjercicio *> ejs;
    for(set<DataEjercicio *>::iterator it = this->Ejs.begin(); it != this->Ejs.end(); ++it)
    {
        ejs.insert((*it));
    }
    DataLeccion* leccion = new DataLeccion(this->temaLeccion, this->objLeccion, this->idLeccion, ejs);
    this->Lecciones.push_back(leccion);
    this->Ejs.clear();
}

// ingresarLeccionParaAlta(string tema, string objetivo), ngresarEjercicioParaAlta(DataEjercicio* ejercicio, DataLeccion* leccion){ leccion->Ejercicios.insert(ejercicio); }, confirmarLeccion()



void ControladorCurso::confirmarAltaCurso()
{
    Curso* curso = new Curso(this->seleccionado, nickProfesor);
    for (list<DataLeccion *>::iterator it = this->Lecciones.begin(); it != this->Lecciones.end(); it++)
    {   
        curso->agregarLeccion((*it)->getTema(), (*it)->getObjetivo(), (*it)->getEjercicios());
    }
    ControladorUsuario* cu = ControladorUsuario::getInstancia();
    Usuario* p = cu->findUsuario(this->nickProfesor);
    Profesor* prof = dynamic_cast<Profesor*>(p);
    prof->agregarCurso(curso);

    this->colCursos.emplace(curso->getNombre(),curso); 
    set<Curso *> cursosPrevios;
    for (set<string>::iterator it = this->previos.begin(); it != this->previos.end(); it++)
    {
        Curso* cursoPrevio = this->colCursos.find(*it)->second;
        curso->ingresarPrevia(cursoPrevio);
    }
    Idioma* idiomaC = this->colIdiomas.find(this->idiomaCurso)->second;
    curso->setIdioma(idiomaC);
    curso->notificarNuevoCurso(idiomaC);
}

// Para el Caso de Uso : [Agregar Leccion]
void ControladorCurso::ingresarDatosLeccion(string cursoSeleccionado,string tema, string objetivo){
    this->nombreCurso = cursoSeleccionado;
    this->temaLeccion = tema;
    this->objLeccion = objetivo;
}

void ControladorCurso::ingresarEjercicio(DataEjercicio* ejercicio){
    DataEjercicio* nuevo = this->colCursos.find(this->nombreCurso)->second->obtenerIdEjercicio(ejercicio);
    this->Ejs.insert(nuevo);
}

void ControladorCurso::altaLeccion(){
    this->colCursos.find(this->nombreCurso)->second->agregarLeccion(this->temaLeccion, this->objLeccion, this->Ejs);
    this->Ejs.clear();
}

// Para el Caso de Uso : [Agregar Ejercicio]
set<DataLeccion *> ControladorCurso::getLecciones(string cursoSeleccionado)
{
    // Recordamos el nombre del curso...
    this->nombreCurso = cursoSeleccionado;

    set<DataLeccion *> res;
    map<string,Curso *>::iterator it = this->colCursos.find(cursoSeleccionado);
    if (it != this->colCursos.end())
    {
        res = it->second->darDataLecciones(true);
    }
    return res;
}

void ControladorCurso::agregarEjercicio(int leccionSeleccionada, DataEjercicio* ejercicio)
{
    map<string,Curso *>::iterator it = this->colCursos.find(this->nombreCurso);
    it->second->agregarEjercicio(leccionSeleccionada,ejercicio);
}

// Para el Caso de Uso : [Habilitar Curso]

set<InformacionCurso *> ControladorCurso::getCursosNoHabilitados()
{
    set<InformacionCurso *> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it)
    {
        Curso* actual = it->second;
        if(!(actual->getHabilitado()))
        {
            res.insert(actual->getInformacionCurso(false)); // Pide un informacion curso sin promedio...
        }
    }
    return res;
}

bool ControladorCurso::habilitarCurso(string seleccionado) 
{
    bool pudoHabilitarse = false;
    map<string,Curso *>::iterator it = this->colCursos.find(seleccionado);
    if (it != this->colCursos.end() )
    {
        pudoHabilitarse = it->second->sePuedeHabilitar();
    } else
    {
        pudoHabilitarse = false;
    }
    if (pudoHabilitarse)
    {
        it->second->setHabilitado(true);
    }
    return pudoHabilitarse;
}

// Para el Caso de Uso : [Eliminar Curso]

set<string> ControladorCurso::getNombreCursos(){
    set<string> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it) {
        res.insert(it->first);
    }
    return res;
}

//Quiero borrar esta funcion. Alguien la usa? Nacho p.
void ControladorCurso::seleccionarCurso(string nombreCurso){ this->nombreCurso = nombreCurso; }


void ControladorCurso::bajarCurso(string nombreCurso)
{
    Curso *C = this->colCursos[nombreCurso];
    this->colCursos.erase(nombreCurso); // Se saca el curso de la coleccion
    delete C; // Se llama al destructor de Curso
}


// Para el Caso de Uso : [Consulta de Curso]
DataConsultaCurso* ControladorCurso::obtenerDataCursoSeleccionado(string curso){
    map<string,Curso *>::iterator it = this->colCursos.find(curso);
    return it->second->getDataConsultaCurso();
}

// Falta Implementar...
InscripcionCurso* ControladorCurso::getCurso(string seleccionado)
{
    InscripcionCurso* res;

    return res;
}

// Para el Caso de Uso : [Inscribirse a Curso]
// Obtiene una lista de todos los cursos habilitados, sacandole los inscriptos y los que tengan previas sin aprobar...
set<InformacionCurso *> ControladorCurso::darCursosHabilitadosDisponibles(set<string> nombresCursosAprobados, set<string> nombresCursosInscriptos){
    set<InformacionCurso *> res;

    // Para cada curso...
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end();++it){

         // Si esta habilitado
        if (it->second->getHabilitado()){
            string nombreCurso = it->second->getNombre();
            set<string>::iterator it2 = nombresCursosInscriptos.find(nombreCurso);

             // Si no esta inscipto
            if(it2 == nombresCursosInscriptos.end()){

                // Si no tiene previas sin aprobar
                if(it->second->previosAprobados(nombresCursosAprobados)){
                    // Se agrega al set resultado
                    res.insert(it->second->getDatosCurso());
                }
            }
        }    
    }
    return res;
}


Curso* ControladorCurso::encontrarCurso(string curso){
    return this->colCursos[curso];
}

// Para el Caso de Uso : [Realizar Ejercicio]
string ControladorCurso::obtenerLetra(string nomC, int ejercicio){
    map<string,Curso *>::iterator it = this->colCursos.find(nomC);
    return it->second->buscarLetraEnCurso(ejercicio);
}

DataEjercicio* ControladorCurso::encontrarEjercicio(string nomC, int ejercicio){
    map<string,Curso *>::iterator it = this->colCursos.find(nomC);
    return it->second->buscarEjercicioEnCurso(ejercicio);
}

// Para el Caso de Uso : [Consultar Estadisticas] 

//Igual a getNombreCusos?
set<string> ControladorCurso::darNombreCursos()
{
    set<string> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end();++it)
    {
        string nomC = it->second->getNombre();
        res.insert(nomC);
    }
    return res;
}

InformacionCurso* ControladorCurso::darInformacionCurso(string nombreCurso)
{
    InformacionCurso* res = NULL;
    map<string,Curso *>::iterator it = this->colCursos.find(nombreCurso);
    if(it != this->colCursos.end()) { res = it->second->getInformacionCurso(true); }
    return res;
}

// Para el Caso de Uso : [Suscribirse a Notificaciones]

void ControladorCurso::agregarObservador(Suscripcion *u, set<string> idiomas){
    
    for(set<string>::iterator iter = idiomas.begin(); iter != idiomas.end(); ++iter)
    {
        this->colIdiomas.find((*iter))->second->agregar(u);
    }
}

// Para el Caso de Uso : [Eliminar Suscripciones]
void ControladorCurso::quitarObservador(Suscripcion *s, set<string> seleccionados)
{
    for (set<string>::iterator it = seleccionados.begin(); it !=seleccionados.end(); ++it)
    {
        this->colIdiomas[(*it)]->eliminarUsuario(s);
    }
}