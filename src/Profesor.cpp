#include "../include/Profesor.hh"

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

    // Obtengo la instancia de ControladorCurso
    ControladorCurso* cc = ControladorCurso::getInstancia();
    map<string,Idioma *> idiomas;

    for(set<string>::iterator it = seleccionados.begin(); it != seleccionados.end(); ++it)
    {
        idiomas.emplace((*it),cc->darIdiomaEnColeccion((*it)));
    }
    this->colIdiomas = idiomas;
}
// Destructor

// Getters y Setters
string Profesor::getInstituto(){ return this->Instituto; }

// DataTypes
DataUsuario* Profesor::getDataUsuario()
{
    set<string> sinIdiomas;
    return (new DataProfesor(this->getNickname(),this->getNombre(),this->getPassword(),this->getDescripcion(),this->getInstituto(),sinIdiomas));
}

DataUsuario* Profesor::getDatosUsuario()
{
    set<string> conIdiomas;
    for(map<string,Idioma *>::iterator it = this->colIdiomas.begin(); it != this->colIdiomas.end(); ++it)
    {
        conIdiomas.insert(it->first);
    }
    return (new DataProfesor(" ",this->getNombre()," ",this->getDescripcion(),this->getInstituto(),conIdiomas));
}

// Para distinguir entre las distintas sub-clases

bool Profesor::esEstudiante(){ return false; }
bool Profesor::esProfesor(){ return true; }

void Profesor::eliminarLinkP(string nombreCurso){
    this->colCursos.erase(nombreCurso);
}

// Para el Caso de Uso : [Consultar Estadisticas]
set<InfoCurso *> Profesor::getInfoCursos()
{
    set<InfoCurso *> res; 
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it) {
        string nomC = it->first;
        float promedio = it->second->darPromedio();

        InfoCurso* elem = new InfoCurso(nomC,promedio);
        res.insert(elem);
    }
    return res;
}