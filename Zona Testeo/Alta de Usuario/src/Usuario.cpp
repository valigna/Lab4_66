#include "../include/Usuario.hh"

// Constructores
Usuario::Usuario(string nick, string name, string con, string desc)
{
    this->Nickname = nick;
    this->Nombre = name;
    this->Password = con;
    this->Descripcion = desc;

}

Usuario::Usuario(DataUsuario* datos,set<string> seleccionados)
{
    Usuario* nuevo = NULL;

    string nick = datos->getNickname();
    string name = datos->getNombre();
    string pass = datos->getContrasenia();
    string desc = datos->getDescripcion();

    DataEstudiante* est = dynamic_cast<DataEstudiante *>(datos);
    if (est != NULL)
    {
        nuevo = new Estudiante(nick,name,pass,desc,est);
    } else
    {
        DataProfesor* prof = dynamic_cast<DataProfesor *>(&datos);
        nuevo = new Profesor(nick,name,pass,desc,prof,seleccionados);
    }
}

// Destructor


// Getters y Setters
string Usuario::getNickname() { return this->Nickname; }
string Usuario::getNombre() { return this->Nombre; }
string Usuario::getPassword() { return this->Password; }
string Usuario::getDescripcion() { return this->Descripcion; }