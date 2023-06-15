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

// Para el caso de uso : [Eliminar Curso]
// Falta Implementar...
void Usuario::notificarBaja(string nombreCurso)
{

}

/* void Usuario::notificarBaja(string nombreCurso){
    for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it){
        if (it->presentaCurso(nombreCurso)) {
            vector<Notificacion *>::iterator itSup = it; //Se hace esto porque erase actualiza it para que apunte al proximo
            this->colNotificaciones.erase(it);
            delete itSup;
            break;
        }
    }
 
} */

// Para el caso de uso : [Suscribirse a notificaciones]
set<string> Usuario::darIdiomasNoSuscritos() {
    // Obtengo la instancia de Controlador Curso y delego la operacion...
    ControladorCurso* cu = ControladorCurso::getInstancia();
    set<string> idiomas = cu->getIdiomas();
    
    for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it)
    {
        string idi = (*it)->darIdioma();
        set<string>::iterator iter = idiomas.find(idi);
        if(iter != idiomas.end()){ idiomas.erase(idi); }
    }

    return idiomas;
}


// Para el caso de uso: [Eliminar Suscripciones]
set<string> Usuario::darIdiomasSuscritos(){
    set<string> res;
    for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it) {
        string idioma = (*it)->darIdioma();
        res.insert(idioma);
    }
    return res;
}

void Usuario::notificarAlta(Idioma *i, Curso *c){

}