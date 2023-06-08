#include "../include/Usuario.hh"

// Constructores
Usuario::Usuario(DataUsuario *datos,set<string> seleccionados)
{
    Usuario* nuevo = NULL;

    string nick = datos->getNickname();
    string name = datos->getNombre();
    string pass = datos->getContrasenia();
    string desc = datos->getDescripcion();

    DataEstudiante* est = dynamic_cast<DataEstudiante *>(&datos);
    if (est != NULL)
    {
        nuevo = new Estudiante(nick,name,pass,desc,est);
    } else
    {
        DataProfesor* prof = dynamic_cast<DataProfesor *>(&datos);
        nuevo = new Profesor(nick,name,pass,desc,prof,seleccionados);
    }
}
// Este creo que no va, tendria que revisarlo... (MI)

// Destructor


// Getters y Setters
string Usuario::getNickname() { return this->Nickname; }
string Usuario::getNombre() { return this->Nombre; }
string Usuario::getPassword() { return this->Password; }
string Usuario::getDescripcion() { return this->Descripcion; }

// Otres...

// Para el Caso de Uso : [Consultar Estadisticas]
bool Usuario::esEstudiante()
{
    Estudiante* aux = dynamic_cast<Estudiante *>(this);
    if (aux != NULL) 
    {
        return true;
    } else 
    {
        return false;
    }
}

// Para el caso de uso : [Realizar Ejercicio]
// set<string> Usuario::getCursosNoAprobados(){
//     set<string> res;
//     for(vector<Inscripcion *>::iterator it = this->colInscripcion.begin(); it != this->colInscripcion.end(); it++){
//         if(verificarEstado(it)){
//             string curso = it->
//         }
//     }
// }

// Para el caso de uso : [Eliminar Curso]
void Usuario::notificarBaja(string nombreCurso){
    for(vector<Notificacion *>::iterator it = this->colNotificaciones.begin(); it != this->colNotificaciones.end(); ++it){
        if (it->presentaCurso(nombreCurso)) {
            vector<Notificacion *>::iterator itSup = it; //Se hace esto porque erase actualiza it para que apunte al proximo
            this->colNotificaciones.erase(it);
            delete itSup;
            break;
        }
    }
    
    
}

// Para el Caso de Uso : [Consultar Estadisticas]
bool Usuario::esEstudiante()
{
    Estudiante* aux = dynamic_cast<Estudiante *>(&this);
    if (aux != NULL) 
    {
        return true;
    } else 
    {
        return false;
    }
}

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
        string idioma = it->darIdioma();
        res.insert(idioma);
    }
    return res;
}