#include "../include/Usuario.hh"


// Constructores
Usuario::Usuario(string nick, string name, string con, string desc){
    this->Nickname = nick;
    this->Nombre = name;
    this->Password = con;
    this->Descripcion = desc;
}
// Destructor

Usuario::~Usuario(){

}

// Getters y Setters
string Usuario::getNickname() { return this->Nickname; }
string Usuario::getNombre() { return this->Nombre; }
string Usuario::getPassword() { return this->Password; }
string Usuario::getDescripcion() { return this->Descripcion; }

// Para el Caso de Uso : [Alta de Curso]
void Usuario::notificarAlta(Idioma *i,Curso *c)
{
    this->colNotificaciones.push_back(new Notificacion(i,c));
}

// Para el caso de uso : [Eliminar Curso]
void Usuario::notificarBaja(string nombreCurso)
{
    for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it){
        if ((*it)->presentaCurso(nombreCurso)) {
            delete (*it);
            this->colNotificaciones.erase(it);
            break;
        }
    }
}

// Para el caso de uso : [Suscribirse a notificaciones]
set<string> Usuario::darIdiomasNoSuscritos() {
    // Obtengo la instancia de Controlador Curso y delego la operacion...
    ControladorCurso* cc = ControladorCurso::getInstancia();
    set<string> idiomas = cc->getIdiomas();
    set<string> suscritos = this->idiomasSuscritos;
    
    for(set<string>::iterator it = suscritos.begin(); it != suscritos.end(); ++it)
    {
        set<string>::iterator iter = idiomas.find(*it);
        if(iter != idiomas.end()){ idiomas.erase(*it); }
    }

    return idiomas;
}

void Usuario::agregarIdiomasSuscrito(set<string> idiomas)
{
    for (set<string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        this->idiomasSuscritos.insert((*it));
    }
    
}

set<DataNotificacion *> Usuario::darNotificaciones()
{
    set<DataNotificacion*> res;
    for (vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it)
    {
        res.insert((*it)->darData());
        delete (*it);
    }
    this->colNotificaciones.clear();
    return res;
}
// Para el caso de uso: [Eliminar Suscripciones]
set<string> Usuario::darIdiomasSuscritos(){
    /* set<string> res;
    for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it) {
        string idioma = (*it)->darIdioma();
        res.insert(idioma);
    } */
    return this->idiomasSuscritos;
}

void Usuario::eliminarSuscripciones(set<string> seleccionados)
{
/*     for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it)
    {
        string idioma = (*it)->darIdioma();
        if(seleccionados.find(idioma) != seleccionados.end()){this->colNotificaciones.erase(it);}
        delete (*it);
    } */
    for(set<string>::iterator it = seleccionados.begin(); it != seleccionados.end(); ++it)
    {
        set<string>::iterator itDummy = this->idiomasSuscritos.find(*it);
        if(itDummy != this->idiomasSuscritos.end()) { this->idiomasSuscritos.erase(itDummy); }
    }
    Suscripcion* sub = (Suscripcion*) this;
    ControladorCurso* cc = ControladorCurso::getInstancia();
    cc->quitarObservador(sub,seleccionados);
}