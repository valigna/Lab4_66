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

// Para el Caso de Uso : [Alta de Usuario]
Idioma* ControladorCurso::obtenerIdioma(string nombre)
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

// Para el Caso de Uso : [Alta de idioma]
bool ControladorCurso::altaIdioma(string nombre)
{
    // Se corrobora si ya existia un idioma de nombre 'nombre'...
    bool altaExitosa = false;
    if(this->colIdiomas.find(nombre) == this->colIdiomas.end())
    {
        this->colIdiomas.emplace(nombre,new Idioma(nombre));
        altaExitosa = true;
    }
    return altaExitosa;

}

set<string> ControladorCurso::getIdiomas()
{
    set<string> res;
    for(map<string,Idioma *>::iterator it = this->colIdiomas.begin(); it != this->colIdiomas.end(); ++it)
    {
        res.insert(it->first);
    }
    return res;
}

// Para el Caso de Uso : [Alta de Curso]

 void ControladorCurso::ingresarDataCurso(string profesor, DTCurso curso) {
    this->Curso = curso;
    ControladorUsuario * cu;
    cu = ControladorUsuario::getInstancia();
    this->Profesor = cu->findUsuario(profesor);
 }

void ControladorCurso::ingresarCursosPrevios(set<string> previos){
    
    map<string,Curso *> Pr;

    this->Previos = Pr;

}

// Para el Caso de Uso : [Habilitar Curso]
set<InfromacionDeCurso *> ControladorCurso::getCursosNoHabilitados()
{
    set<InformacionDeCurso *> res;
    for(map<string,Curso *>::iterator it = this->colCursos.begin(); it != this->colCursos.end(); ++it)
    {
        Curso* actual = it->second;
        if(!(actual->getHabilitado()))
        {
            // Obtengo el nombre del Idioma que se ensenia...
            string nombreIdi = actual->Idioma->getNombre();
            // Obtengo el profesor que creo este curso...
            DataProfesor* creo = new DataProfesor(actual->Profesor->getNickname(),actual->Profesor->getNombre(),actual->Profesor->getPassword(),actual->Profesor->getDescripcion(),actual->Profesor->getInstituto());
            // Obtengo los nombres de los cursos previos...
            set<string> previos;
            for(set<Curso *>::iterator iter = actual->colPrevios.begin(); iter != actual->colPrevios.end(); ++iter)
            {
                previos.insert((*iter)->getNombre());
            }
            int cEjs = 0;
            for(list<Leccion *>::iterator iter2 = actual->coclLecciones.begin(); iter2 != actual->colLecciones.end(); ++iter2)
            {
                cEjs += (*iter2)->colEjercicios.size();
            }
            res.insert(new InformacionDeCurso(actual->getNombre(),actual->getDescripcion(),actual->getDificultad(),nombreIdi,creo,actual->colLecciones.size(),cEjs));
        }
    }
    return res;
}

bool ControladorCurso::habilitarCurso(string seleccionado) 
{
    bool pudoHabilitarse;
    map<string,Curso *>::iterator it = this->colCursos.find(seleccionado);
    if (it != this->colCursos.end() )
    {
        pudoHabilitarse = it->second->sePuedeHabilitar();
    } else
    {
        pudoHabilitarse = false;
    }
    if (pudoHabilitarse)
    {
        it->second->setHabilitado(true);
    }
    return pudoHabilitarse;
}



// Para el Caso de Uso : [Realizar Ejercicio]
string ControladorCurso::obtenerLetra(string nomC, int ejercicio){
    map<string,Curso *>::iterator it = this->colCursos.find(nomC);
    return it->buscarLetraEnCurso(int ejercicio);
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




/*
CODIGO VIEJO / CPZ SIRVE

            // Obtengo la informacion de las lecciones que tiene este curso...
            set<DataLeccion *> lecciones;
            for(list<Leccion *>::iterator it2 = actual->colLecciones.begin(); it2 != actual->colLecciones.end(); ++it2)
            {
                set<DataEjercicio *> ejercicios;
                for(set<Ejercicio*>::iterator it3 = (*it2)->colEjercicios.begin(); it3 != (*it2)->colEjercicios.end(); ++it3)
                {
                    DataTraduccion* trad = dynamic_cast<DataTraduccion *> (*it3);
                    if (trad != NULL)
                    {
                        ejercicios.insert(new DataTraduccion(trad->getDescripcion(),trad->getId(),trad->getFrase(),trad->getTraduccion()));
                    } else
                    {
                        DataCompletarPalabras* comP = (DataCompletarPalabras *) (*it3);
                        ejercicios.insert(new DataCompletarPalabras(comP->getDescripcion(),comP->getId(),comP->getFrase(),comP->getSolucion()));
                    }
                }
                lecciones.insert((*it2)->getTema(),(*it2)->getObjetivo();,ejercicios);
            }

*/
