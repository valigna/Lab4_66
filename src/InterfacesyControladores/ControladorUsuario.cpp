#include "../../include/InterfacesyControladores/ControladorUsuario.hh"

// Constructores

// Destructor

// Getters y Setters

// Implementacion del Patron de Disenio : Singleton
ControladorUsuario* ControladorUsuario::instancia = NULL;
ControladorUsuario::ControladorUsuario()
{
    this->colUsuarios = new map<string,Usuario *>;
}

ControladorUsuario* ControladorUsuario::getInstancia()
{
    if (ControladorUsuario::instancia == NULL)
    {
        ControladorUsuario::instancia = new ControladorUsuario();
    }
    return ControladorUsuario::instancia;
}
// Otros

// Set : Unordered set (STL)
set<string> ControladorUsuario::getIdiomas(){
    // Paso 1:
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    // Paso 2:
    set<string> idiomas;
    idiomas = cc->darIdiomas();
    
    return idiomas;
}


// Para el Caso de Uso : [Alta de Usuario]
void ControladorUsuario::ingresarUsuario(DataUsuario *datos) { this->datos = datos; }
void ControladorUsuario::ingresarIdiomas(set<string> seleccionados){ this->seleccionados = seleccionados; }

bool ControladorUsuario::confirmarAltaUsuario()
{
    bool altaExitosa = false;
    string nickname = this->datos->getNickname();
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    if (it == this->colUsuarios.end()) // No exisita un usuario con 'nickname', por lo que se pasa a crear uno...
    {
        // Hacemos un casteo dinamico, para saber si se trata de un Estudiante o Profesor...
        DataEstudiante* aux = dynamic_cast<DataEstudiante *>(this->datos);
        if (aux != NULL) // Efectivamente se trata de un estudiante...
        {
            this->colUsuarios.emplace(nickname,new Estudiante(this->datos));
        } else // Se trata de un profesor
        {
            this->colUsuarios.emplace(nickname, new Profesor(this->datos,this->seleccionados));
        }
        altaExitosa = true;
    }
    return altaExitosa;
}

// Para el Caso de Uso : [Consulta de Usuario]
set<string> ControladorUsuario::getNicksUsuarios()
{
    set<string> res;
    for(map<string,Usuario *>::iterator it = this->colUsuarios.begin(); it != this->colUsuarios.end(); ++it)
    {
        res.insert(it->first);
    }
    return res;
}

DatosUsuario* ControladorUsuario::getDatosUsuario(string nick)
{
    Usuario* u = this->colUsuarios.find(nick)->second;
    
    // Tendria que corroborar si se trata de un Estudiante o Profesor...
    Estudiante* est = dynamic_cast<Estudiante *>(u);
    if (est != NULL)
    {
        DatosUsuario* usuarioE = new DatosEstudiante(est->getNombre(),est->getDescripcion(),est->getPaisResidencia(),est->getNacimiento());
        return usuarioE;
    } else // Es un profesor...
    {
        Profesor* prof = (Profesor *)u;
        set<string> especializa;
        for(map<string,Idioma *>::iterator it = prof->colIdiomas.begin(); it != prof->colIdiomas.end(); ++it)
        {
            especializa.insert(it->first);
        }
        DatosUsuario* usuarioP = new DatosProfesor(prof->getNombre(),prof->getDescripcion(),prof->getInstituto(),especializa);
        return usuarioP;
    }
}

// Para el caso de uso : [Realizar Ejercicio]
set<string> ControladorUsuario::getCursosInscriptosNoAporbados(string nickname){
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    /*
    Estudiante* est = dynamic_cast<Estudiante *>(it->second);
    if(est != NULL)
    {

    }

    */
    return it->second->obtenerCursosNoAprobados();
}



set<DatosEjercicio *> ControladorUsuario::getEjerciciosNoAprobados(string curso){
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->obtenerEjerciciosNoAprobados(string curso);
}

string ControladorUsuario::getProblema(int ejercicio){
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    return cc->obtenerLetra(string nomC, int ejercicio); // Como se maneja la memoria en nomC?
}

void ControladorUsuario::resolverEjercicioT(int ejercicio, string sol){
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->hacerEjercicioT(ejercicio, sol);
}

void ControladorUsuario::resolverEjercicioCP(int ejercicio, set<string> sol){
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->hacerEjercicioCP(ejercicio, sol);
}
//

set<string> ControladorUsuario::idiomasNoSuscritos(string nickname) {
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->darIdiomasNoSuscritos();
}

// Para el Caso de Uso : [Alta de Curso]
Usuario ControladorUsuario::findUsuario(string nickname){
    return colUsuarios.find(nickname)->second;
}

// Para el Caso de Uso : [Consultar Estadisticas]
set<string> ControladorUsuario::darNicksEstudiantes()
{
    set<string> res;
    
    // Recorremos la coleccion de Usuarios del Sistema
    for (map<string,Usuario *>::iterator it = this->colUsuarios.begin(); it != this->colUsuarios.end();++it)
    {
        bool estudiante = it->second->esEstudiante();
        if (estudiante) { res.insert(it->second->getNickname()); }
    }
    
    return res;
}

set<InfoCursoEst *> ControladorUsuario::darInfoCursosEst(string nickEstudiante)
{
    set<InfoCursoEst *> res;
    
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickEstudiante);
    if((it != this->colUsuarios.end()) && (it->second->esEstudiante())) {res = it->second->infCursosInscriptos();}
    
    return res;
}

set<string> ControladorUsuario::darNicksProfesores()
{
    set<string> res;
    
    // Recorremos la coleccion de Usuarios del Sistema
    for (map<string,Usuario *>::iterator it = this->colUsuarios.begin(); it != this->colUsuarios.end();++it)
    {
        bool profesor = !(it->second->esEstudiante());
        if (profesor) {res.insert(it->second->getNickname());}
    }
    
    return res;
}

set<InfoCursoProf *> ControladorUsuario::darInfoCursosProf(string nickProfesor)
{
    set<InfoCursoProf *> res;
    
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickProfesor);
    if((it != this->colUsuarios.end()) && !(it->second->esEstudiante()))res = it->second->darInfoCursos();
    
    return res;
}

// Para el caso de uso: [Inscribirse a curso]
set<DatosCurso *> ControladorUsuario::getCursosDisponibles(string nickname){
    set<DatosCurso *> res;
    this->nickname = nickname;
    Estudiante* est = dynamic_cast<Estudiante *>(this->colUsuarios[nickname]);
    if (est != NULL) {
        res = est->darCursosDisponibles();
    }
    return res;
}

// Para el Caso de Uso : [Suscribirse a Notificaciones]
set<string> ControladorUsuario::idiomasNoSuscritos(string nickname)
{
    set<string> res;
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    if(it != this->colUsuarios.end())
    {
        res = it->second->darIdiomasNoSuscritos();
    }
    return res;
}

void ControladorUsuario::suscribirse(set<string> idiomas){

    Usuario *u = colUsuarios.find(nickname);
    ControladorCurso* cc;
    cc = ControladorCurso::getInstancia();
    cc->agregarObservador(u,idiomas);
}



// Para el caso de uso: [Eliminar Suscripciones]
set<string> idiomasSuscritos(string nickname){
    this->nickname = nickname;
    return this->colUsuarios[nickname]->getIdiomasSuscritos();
}



//Estudiante* est = dynamic_cast<Estudiante *>(this->colUsuarios[nickname])