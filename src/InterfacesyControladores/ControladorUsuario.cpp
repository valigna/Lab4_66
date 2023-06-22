#include "../../include/InterfacesyControladores/ControladorUsuario.hh"

// Destructor
ControladorUsuario::~ControladorUsuario(){ }

// Implementacion del Patron de Disenio : Singleton
ControladorUsuario* ControladorUsuario::instancia = NULL;
ControladorUsuario::ControladorUsuario(){ }

ControladorUsuario* ControladorUsuario::getInstancia()
{
    if (ControladorUsuario::instancia == NULL)
    {
        ControladorUsuario::instancia = new ControladorUsuario();
    }
    return ControladorUsuario::instancia;
}

// Para la Carga de Datos
void ControladorUsuario::registrarInscripcion(string nombreCurso,string nickEstudiante,DataFecha* fecha)
{
    // Se busca al estudiante en la coleccion de usuarios usando el nickname
    Estudiante* est = dynamic_cast<Estudiante *>(this->colUsuarios[nickEstudiante]);
    // Se corrobora que el usuario sea un estudiante
    if (est != NULL) {
        est->realizarInscripcion(nombreCurso,fecha);
    }
}

// Para el Caso de Uso : [Alta de Usuario]
void ControladorUsuario::ingresarUsuario(DataUsuario *datos) { this->datos = datos; }

set<string> ControladorUsuario::getIdiomas()
{
    ControladorCurso* cc = ControladorCurso::getInstancia();
    set<string> idiomas = cc->getIdiomas();
    return idiomas;
}

void ControladorUsuario::ingresarIdiomas(set<string> seleccionados){ this->seleccionados = seleccionados; }

bool ControladorUsuario::confirmarAltaUsuario()
{
    bool altaExitosa = false;
    string nickname = this->datos->getNickname();
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    if (it == this->colUsuarios.end()) // No exisita un usuario con 'nickname', por lo que se pasa a crear uno...
    {
        bool estudiante = this->datos->esEstudiante();
        if (estudiante) // Efectivamente se trata de un estudiante...
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

DataUsuario* ControladorUsuario::getDatosUsuario(string nick)
{
    Usuario* u = this->colUsuarios.find(nick)->second;
    return u->getDatosUsuario();   
}

// Para el Casod De Uso : [Consulta de Curso]
set<string> ControladorUsuario::obtenerCursos(){
    ControladorCurso* cc = ControladorCurso::getInstancia();
    return cc->darNombreCursos();
}

DataConsultaCurso* ControladorUsuario::seleccionarCurso(string curso){
    ControladorCurso* cc = ControladorCurso::getInstancia();
    return cc->obtenerDataCursoSeleccionado(curso);
}

// Para el caso de uso : [Realizar Ejercicio]
set<string> ControladorUsuario::getCursosInscriptosNoAprobados(string nickname){
    set<string> res;
    this->nickname = nickname;
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    if (it->second->esEstudiante())
    {
        Estudiante* est = (Estudiante*) it->second;
        res = est->obtenerCursosNoAprobados();
    }
    return res;
}

set<DataEjercicio *> ControladorUsuario::getEjerciciosNoAprobados(string curso){
    set<DataEjercicio *> res;
    this->nomC = curso;
    map<string,Usuario *>::iterator it = this->colUsuarios.find(this->nickname);
    if(it->second->esEstudiante())
    {
        Estudiante* est = (Estudiante*) it->second;
        res = est->obtenerEjerciciosNoAprobados(curso);
    }
    return res;
}

string ControladorUsuario::getProblema(int ejercicio){
    ControladorCurso* cc = ControladorCurso::getInstancia();
    return cc->obtenerLetra(this->nomC,ejercicio);
}

bool ControladorUsuario::resolverEjercicioT(int ejercicio, string sol){
    map<string,Usuario *>::iterator it = this->colUsuarios.find(this->nickname);
    Estudiante* est = dynamic_cast<Estudiante *>(it->second);
    return est->hacerEjercicioT(this->nomC, ejercicio, sol);
}

bool ControladorUsuario::resolverEjercicioCP(int ejercicio, set<string> sol){
    map<string,Usuario *>::iterator it = this->colUsuarios.find(this->nickname);
    Estudiante* est = dynamic_cast<Estudiante *>(it->second);
    return est->hacerEjercicioCP(this->nomC, ejercicio, sol);
}
//

// Para el Caso de Uso : [Alta de Curso]
Usuario* ControladorUsuario::findUsuario(string nickname){
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

set<string> ControladorUsuario::darNicksProfesores()
{
    set<string> res;
    
    // Recorremos la coleccion de Usuarios del Sistema
    for (map<string,Usuario *>::iterator it = this->colUsuarios.begin(); it != this->colUsuarios.end();++it)
    {
        bool profesor = (it->second->esProfesor());
        if (profesor) {res.insert(it->second->getNickname());}
    }
    
    return res;
}

set<InfoCurso *> ControladorUsuario::darInfoCursos(string nickUsuario)
{
    set<InfoCurso *> res;
    
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickUsuario);
    if(it != this->colUsuarios.end()) {res = it->second->getInfoCursos();}
    
    return res;
}



// Para el caso de uso: [Inscribirse a curso]
set<InformacionCurso *> ControladorUsuario::getCursosDisponibles(string nickname){
    set<InformacionCurso *> res;
    this->nickname = nickname;

    Estudiante* est = dynamic_cast<Estudiante *>(this->colUsuarios[this->nickname]);
    res = est->darCursosDisponibles();
    return res;
}

void ControladorUsuario::inscribirseACurso(string curso){
    // Se busca al estudiante en la coleccion de usuarios usando el nickname recordado
    Estudiante* est = dynamic_cast<Estudiante *>(this->colUsuarios[this->nickname]);
    // Se corrobora que el usuario sea un estudiante
    if (est != NULL) {
        est->realizarInscripcion(curso);
    }
}

// Para el Caso de Uso : [Suscribirse a Notificaciones]
set<string> ControladorUsuario::idiomasNoSuscritos(string nickname)
{
    set<string> res;
    this->nickname = nickname;
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    if(it != this->colUsuarios.end())
    {
        res = it->second->darIdiomasNoSuscritos();
    }
    return res;
}

void ControladorUsuario::suscribirse(set<string> idiomas)
{
    Usuario* u = colUsuarios[this->nickname];
    u->agregarIdiomasSuscrito(idiomas);
    Suscripcion* sub = (Suscripcion*) (u);
    ControladorCurso* cc = ControladorCurso::getInstancia();
    cc->agregarObservador(sub,idiomas);
}

// Para el Caso de Uso : [Consulta de Notificaciones]
// Falta Implementar...
set<DataNotificacion *> ControladorUsuario::obtenerNotificaciones(string nickname)
{
    set<DataNotificacion *> res;
    Usuario* u = this->colUsuarios.find(nickname)->second;
    res = u->darNotificaciones();
    return res;
}

// Para el caso de uso: [Eliminar Suscripciones]
set<string> ControladorUsuario::idiomasSuscritos(string nickname){
    this->nickname = nickname;
    return this->colUsuarios[nickname]->darIdiomasSuscritos();
}

void ControladorUsuario::eliminarSuscripciones(set<string> seleccionados)
{
    map<string,Usuario *>::iterator it = this->colUsuarios.find(this->nickname);
    if(it != this->colUsuarios.end())
    {
        it->second->eliminarSuscripciones(seleccionados);
    }
}