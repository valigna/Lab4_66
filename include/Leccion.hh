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
    set<Traduccion *> colEjerciciosT;
    set<CompletarPalabras *> colEjerciciosCP;
    
public:
    // Constructores

    // Destructor
    ~Leccion();
    // Getters y Setters

    // Para el Caso de Uso : [Realizar Ejercicio]
    set<DataEjercicio *> ejerciciosNoAprobadosLeccion();
    string buscarLetraEnLeccion(int ejercicio);
    bool ejercicioEnLeccion(int ejercicio);
    Ejercicio* buscarEjercicioEnLeccionT(int ejercicio, string sol);

    // Para el Caso de Uso : [Consultar Estadisticas]
    int totalEjercicios();

};

#endif