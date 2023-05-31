/*
    Cambios que hice con respecto al Lab3 (Martin Idiart)
        - La operacion getEstudiantes():set(string) pasa a ser getNicksEstudiantes():set(string)

*/

#ifndef CONTROLADOR_ESTADISTICAS
#define CONTROLADOR_ESTADISTICAS

// Includes...
#include "../Utils.hh"

class ControladorEstadisticas
{
private:

public:
    set<string> getNicksEstudiantes();

}

#endif