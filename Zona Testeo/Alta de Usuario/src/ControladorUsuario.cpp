#include "../include/ControladorUsuario.hh"

// Destructor
ControladorUsuario::~ControladorUsuario()
{

}

// Implementacion del Patron de Disenio : Singleton
ControladorUsuario* ControladorUsuario::instancia = NULL;
ControladorUsuario::ControladorUsuario()
{

}

ControladorUsuario* ControladorUsuario::getInstancia()
{
    if (ControladorUsuario::instancia == NULL)
    {
        ControladorUsuario::instancia = new ControladorUsuario();
    }
    return ControladorUsuario::instancia;
}

Usuario* ControladorUsuario::darUsuario(string nick)
{
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nick);
    return it->second;
}

// Para el Caso de Uso : [Alta de Usuario]
void ControladorUsuario::ingresarUsuario(DataUsuario* datos) { this->datos = datos; }
void ControladorUsuario::ingresarIdiomas(set<string> seleccionados){ this->seleccionados = seleccionados; }

bool ControladorUsuario::confirmarAltaUsuario()
{
    bool altaExitosa = false;
    string nickname = this->datos->getNickname();
    map<string,Usuario *>::iterator it = this->colUsuarios.find(nickname);
    if (it == this->colUsuarios.end())
    {
        //Usuario* nuevo = new Usuario(this->datos,this->seleccionados);
        DataEstudiante* aux = dynamic_cast<DataEstudiante *>(this->datos);
        if (aux != NULL)
        {
            Usuario *nuevo = new Estudiante(aux);
            this->colUsuarios.insert(std::pair<string,Usuario *>(this->datos->getNickname(),nuevo));
        } else 
        {
            Usuario *nuevo = NULL;
        }
        altaExitosa = true;
    }
    return altaExitosa;
}