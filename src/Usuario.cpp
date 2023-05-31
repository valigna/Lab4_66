#include "../include/Usuario.hh"

set<string> Usuario::getIdiomasSuscritos(){
    set<string> res;
    for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it) {
        string idioma = it->darIdioma();
        res.insert(idioma);
    }
    return res;
}