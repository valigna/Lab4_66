#include "../../include/InterfacesyControladores/ControladorCurso.hh"

// Constructores

// Destructor

// Getters y Setters

// Implementacion del Patron de Disenio : Singleton
ControladorCurso* ControladorCurso::instancia = NULL;
ControladorCurso::ControladorCurso()
{
    this->colIdiomas = new map<string,Idioma *>;
    this->colCursos = new map<string,Curso *>;
}

ControladorCurso* ControladorCurso::getInstancia()
{
    if (ControladorCurso::instancia == NULL)
    {
        ControladorCurso::instancia = new ControladorCurso();
    }
    return ControladorCurso::instancia;
}

//(no se si es op de sistema o no)
set<string> darIdiomas(){
    for (auto& x: this->colIdiomas) {
        // 
    }
}

//Operaciones de sistema
set<string> ControladorCurso::getNombreCursos(){
    set<string> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it) {
        res.insert(it->first);
    }
    return res;
}

void ControladorCurso::seleccionarCurso(string nombreCurso){
    this->nombreCurso = nombreCurso;
}

void ControladorCurso::bajarCurso(){
    Curso *C = this->colCursos[this->nombreCurso];
    this->colCursos.erase(this->nombreCurso); // Se saca el curso de la coleccion
    delete C; // Se llama al destructor de Curso
}

string ControladorCurso::obtenerLetra(string nomC, int ejercicio){
    map<string,Curso *>::iterator it = this->colCursos.find(nomC);
    return it->buscarLetraEnCurso(int ejercicio);
}

// Para el Caso de Uso : [Alta de Usuario]
Idioma* ControladorCurso::obtenerIdidioma(string nombre)
{
    Idioma* res;
    res = this->colIdiomas.find(nombre);
    if (res != this->colIdiomas.end())
    {
        return res;
    } else
    {
        return NULL;
    }
}

// Para el Caso de Uso : [Consultar Estadisticas]

//Igual a getNombreCusos?
set<string> ControladorCurso::darNombreCursos()
{
    set<string> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end();++it)
    {
        string nomC = it->second->getNombre();
        res.insert(nomC);
    }
    return res;
}

InformacionCurso* ControladorCurso::darInformacionCurso(string nombreCurso)
{
    InformacionCurso *res = NULL;
    map<string,Curso *>::iterator it = this->colCursos.find(nombreCurso);
    if(it != this->colCursos.end()) { res = it->second->infoCurso(); }
}



