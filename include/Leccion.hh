#ifndef LECCION
#define LECCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Ejercicio.hh"
// DataTypes
#include "DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */


class Leccion
{
private:

    // PseudoAtributos...
    set<Ejercicio *> colEjercicios;

public:
    // Constructores

    // Destructor
    ~Leccion();
    // Getters y Setters

    // Otres

    set<DataEjercicio *> ejerciciosNoAprobadosLeccion();
    string buscarLetraEnLeccion(int ejercicio);

    // Para el Caso de Uso : [Consultar Estadisticas]
    int totalEjercicios();

}

#endif