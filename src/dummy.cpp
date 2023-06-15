#include "../include/InterfacesYControladores/dummy.hh"

Dummy::Dummy()
{
    this->nombre = "NombreUsuario";
}

Dummy::~Dummy(){ }

string Dummy::getNombre(){ return this->nombre; }