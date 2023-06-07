#include "../include/Profesor.hh"
#include "../include/InterfacesyControladores/ControladorCurso.hh"

// Constructores
/* Profesor::Profesor(string nick,string name, string pass, string desc, DataProfesor* prof,set<string> seleccionados) : Usuario(nick,name,pass,desc)
{
    this->colCursos = new map<string,Curso *>();
    this->colIdiomas = new map<string,Idioma *>();
    this->Instituto = prof->getInstituto();
    
    // Obtengo la instancia de ControladorCurso para recorrer su coleccion de idiomas.
    ControladorCurso* cc;
    for(set<string>::iterator it = seleccionados.begin(); it != seleccionados.end(); ++it)
    {
        Idioma* i = cc->obtenerIdioma();
        if(i != NULL) this->colIdiomas.insert(i->getNombre(),i);
    }

} */
Profesor::Profesor(DataUsuario* datos,set<string> seleccionados) : Usuario(datos->getNickname(),datos->getNombre(),datos->getContrasenia(),datos->getDescripcion())
{
    DataProfesor* aux = (DataProfesor *)datos;
    this->Instituto = aux->getInstituto();

    // Obtengo la instancia de ControladorCurso para recorrer la coleccion de idiomas del sistema
    ControladorCurso* cc;
    cc = ControladorCurso::getInstancia();

    for(set<string>::iterator it = seleccionados.begin(); it != seleccionados.end(); ++it)
    {
        if(cc->colIdiomas.find(*it) != cc->colIdiomas.end()) 
        {
            this->colIdiomas.emplace((*it),cc->colIdiomas[*it]);
        }
    }

}
// Destructor

// Getters y Setters
string Profesor::getInstituto(){ return this->Instituto; }

// Otres

void Profesor::eliminarLinkP(string nombreCurso){
    this->colCursos.erase(nombreCurso);
}

// Para el Caso de Uso : [Consultar Estadisticas]
set<InfoCursoProf *> Profesor::darInfoCursos()
{
    set<InfoCursoProf *> res; 
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it) {
        string nomC = it->first;
        float prom = it->second->darPromedio();

        InfoCursoProf *elem = new InfoCursoProf(nomC,prom);
        res.insert(elem);
    }
    return res;
}