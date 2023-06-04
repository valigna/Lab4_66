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

set<string> ControladorUsuario::getCursosInscriptosNoAprobados(string nickname){
    return this->colUsuarios[nickname]->getCursosNoAprobados();
}

set<string> ControladorUsuario::getCursosInscriptosNoAporbados(string nickname){
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->obtenerCursosNoAprobados();
}

set<DataEjercicio *> ControladorUsuario::getEjerciciosNoAprobados(string curso){
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->obtenerEjerciciosNoAprobados(string curso);
}

string ControladorUsuario::getProblema(int ejercicio){
    ControladorCurso *cc;
    cc = ControladorCurso::getInstancia();
    return cc->obtenerLetra(string nomC, int ejercicio);
}

set<string> ControladorUsuario::idiomasNoSuscritos(string nickname) {
    map<string,Usuario *>::iterator it = this->colUsuarios->find(nickname);
    return it->second->darIdiomasNoSuscritos();
}

// Para el Caso de Uso : [Alta de Usuario]
void ControladorUsuario::ingresarUsuario(DataUsuario *datos) { this->datos = datos; }
void ControladorUsuario::ingresarIdiomas(set<string> seleccionados){ this->seleccionados = seleccionados; }

bool ControladorUsuario::confirmarAltaUsuario()
{
    bool altaExitosa = false;
    string nickname = this->datos->getNickname();
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    if (it == this->colUsuarios.end())
    {
        Usuario* nuevo = new Usuario(this->datos,this->seleccionados);
        this->colUsuarios.insert(this->datos->getNickname,nuevo);
        altaExitosa = true;
    }
    return res;
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


// Para el caso de uso: [Eliminar Suscripciones]
set<string> idiomasSuscritos(string nickname){
    this->nickname = nickname;
    return this->colUsuarios[nickname]->getIdiomasSuscritos();
}