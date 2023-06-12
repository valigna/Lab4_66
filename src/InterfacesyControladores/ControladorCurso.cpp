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

// Falta Implementar...
set<string> ControladorCurso::getNicknamesProfesores()
{
    set<string> res;

    return res;
}

 void ControladorCurso::ingresarDataCurso(string profesor, DTCurso* curso) {
    this->seleccionado = curso;
    this->Profesor = profesor;
 }

// Falta Implementar...
set<string> ControladorCurso::getIdiomasProfesor()
{
    set<string> res;

    return res;
}

// Falta Implementar...
void ControladorCurso::agregarIdiomaCurso(string idioma)
{

}

// Falta Implementar...
set<string> ControladorCurso::getNombreCursosHabilitados()
{
    set<string> res;

    return res;
}

void ControladorCurso::ingresarCursosPrevios(set<string> previos){ this->previos = previos; }
void ControladorCurso::ingresarLeccionParaAlta(DataLeccion* leccion){ this->Leccion = leccion; }
void ControladorCurso::ingresarEjercicioParaAlta(DataEjercicio* ejercicio){ this->Ejercicio = ejercicio; }

// Falta Implementar...
void ControladorCurso::confirmarAltaCurso()
{

}

// Para el Caso de Uso : [Agregar Leccion]
// Falta Implementar...
void ControladorCurso::ingresarDatosLeccion(string cursoSeleccionado,string tema, string objetivo)
{

}

// Falta Implementar...
void ControladorCurso::ingresarEjercicio(DataEjercicio* ejercicio)
{

}

void ControladorCurso::altaLeccion()
{

}

// Para el Caso de Uso : [Agregar Ejercicio]
// Falta Implementar...
set<DataLeccion *> ControladorCurso::getLecciones(string cursoSeleccionado)
{
    set<DataLeccion *> res;

    return res;
}

// Falta Implementar...
void ControladorCurso::agregarEjercicio(int leccionSeleccionada, DataEjercicio* ejercicio)
{

}

// Para el Caso de Uso : [Habilitar Curso]

set<InformacionCurso *> ControladorCurso::getCursosNoHabilitados()
{
    set<InformacionCurso *> res;

    return res;
}

// No compila...
/* set<InformacionCurso *> ControladorCurso::getCursosNoHabilitados()
{
    set<InformacionCurso *> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it)
    {
        Curso* actual = it->second;
        if(!(actual->getHabilitado()))
        {
            // Obtengo el nombre del Idioma que se ensenia...
            string nombreIdi = actual->Idioma->getNombre();
            // Obtengo el profesor que creo este curso...
            DataProfesor* creo = new DataProfesor(actual->Profesor->getNickname(),actual->Profesor->getNombre(),actual->Profesor->getPassword(),actual->Profesor->getDescripcion(),actual->Profesor->getInstituto());
            // Obtengo los nombres de los cursos previos...
            set<string> previos;
            for(set<Curso *>::iterator iter = actual->colPrevios.begin(); iter != actual->colPrevios.end(); ++iter)
            {
                previos.insert((*iter)->getNombre());
            }
            int cEjs = 0;
            for(list<Leccion *>::iterator iter2 = actual->colLecciones.begin(); iter2 != actual->colLecciones.end(); ++iter2)
            {
                cEjs += (*iter2)->colEjercicios.size();
            }
            res.insert(new InformacionDeCurso(actual->getNombre(),actual->getDescripcion(),actual->getDificultad(),nombreIdi,creo,actual->colLecciones.size(),cEjs));
        }
    }
    return res;
} */

bool ControladorCurso::habilitarCurso(string seleccionado) 
{
    bool pudoHabilitarse;
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

// Para el Caso de Uso : [Eliminar Curso] -> Ambas funciones ya estan definidas mas arriba en 'Operaciones del sistema'
// Falta Implementar...
//set<string> ControladorCurso::getNombreCursos()
//{
//    set<string> res;
//
//    return res;
//}

set<string> ControladorCurso::getNombreCursos(){
    set<string> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it) {
        res.insert(it->first);
    }
    return res;
}

// Falta Implementar...
//void ControladorCurso::seleccionarCurso(string nombreCurso)
//{
//
//}


void ControladorCurso::seleccionarCurso(string nombreCurso){
    this->nombreCurso = nombreCurso;
}

// Falta Implementar...
void ControladorCurso::bajarCurso()
{

}

/* void ControladorCurso::bajarCurso(){
    Curso *C = this->colCursos[this->nombreCurso];
    this->colCursos.erase(this->nombreCurso); // Se saca el curso de la coleccion
    delete C; // Se llama al destructor de Curso
} */

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
/* set<InformacionCurso *> ControladorCurso::darCursosHabilitadosDisponibles(set<string> nombresCursosAprobados, set<string> nombresCursosInscriptos){
    set<InformacionCurso *> res;
    // Para cada curso...
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end();++it){
         // Si esta habilitado
        if (it->second->getHabilitado()){
            string nombreCurso = it->second->getNombre();
             // Si no esta inscipto
            if((set<string>::iterator it2 = nombresCursosInscriptos.find(nombreCurso)) == nombresCursosInscriptos.end()){
                // Si no tiene previas sin aprobar
                if(it->second->previosAprobados(nombresCursosAprobados)){
                    // Se agrega al set resultado
                    res.insert(it->second->getDatosCurso());
                }
            }
        }    
    }
} */
set<InformacionCurso *> ControladorCurso::darCursosHabilitadosDisponibles(set<string> nombresCursosAprobados, set<string> nombresCursosInscriptos)
{
    set<InformacionCurso *> res;

    return res;
}

Curso *ControladorCurso::encontrarCurso(string curso){
    return this->colCursos[curso];
}

set<InscripcionCurso *> ControladorCurso::getCursosDisponibles(string nickname)
{
    set<InscripcionCurso *> res;

    return res;
}

void ControladorCurso::inscribirseACurso(string nickname, string curso)
{

}

// Para el Caso de Uso : [Realizar Ejercicio]
string ControladorCurso::obtenerLetra(string nomC, int ejercicio){
    map<string,Curso *>::iterator it = this->colCursos.find(nomC);
    return it->second->buscarLetraEnCurso(ejercicio);
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