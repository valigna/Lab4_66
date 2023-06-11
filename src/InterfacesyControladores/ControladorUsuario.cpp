#include "../../include/InterfacesyControladores/ControladorUsuario.hh"

// Destructor

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
// Otros

// Set : Unordered set (STL)
set<string> ControladorUsuario::getIdiomas(){
    // Paso 1:
    ControladorCurso* cc = ControladorCurso::getInstancia();
    // Paso 2:
    set<string> idiomas;
    idiomas = cc->getIdiomas();
    
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

// Para el Casod De Uso : [Consulta de Curso]
set<string> ControladorUsuario::obtenerCursos(){
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    return cc->darNombreCursos();
}

DataConsultaCurso* ControladorUsuario::seleccionarCurso(string curso){
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    return cc->obtenerDataCursoSeleccionado(curso);
}

// Para el caso de uso : [Realizar Ejercicio]
set<string> ControladorUsuario::getCursosInscriptosNoAporbados(string nickname){
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    Estudiante* est = dynamic_cast<Estudiante *>(it->second);
    return est->obtenerCursosNoAprobados();
}

set<DataEjercicio *> ControladorUsuario::getEjerciciosNoAprobados(string curso){
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    Estudiante* est = dynamic_cast<Estudiante *>(it->second);
    return est->obtenerEjerciciosNoAprobados(curso);
}

string ControladorUsuario::getProblema(int ejercicio){
    string nomC;
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    return cc->obtenerLetra(nomC,ejercicio); // Como se maneja la memoria en nomC?
}

void ControladorUsuario::resolverEjercicioT(int ejercicio, string sol){
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    Estudiante* est = dynamic_cast<Estudiante *>(it->second);
    return est->hacerEjercicioT(ejercicio, sol);
}

void ControladorUsuario::resolverEjercicioCP(int ejercicio, set<string> sol){
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    Estudiante* est = dynamic_cast<Estudiante *>(it->second);
    return est->hacerEjercicioCP(ejercicio, sol);
}
//

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
    
    Suscripcion* u = dynamic_cast<Suscripcion*>(this->colUsuarios[nickname]);
    ControladorCurso* cc = ControladorCurso::getInstancia();
    cc->agregarObservador(u,idiomas);
}



// Para el caso de uso: [Eliminar Suscripciones]
set<string> ControladorUsuario::idiomasSuscritos(string nickname){
    this->nickname = nickname;
    return this->colUsuarios[nickname]->getIdiomasSuscritos();
}