#ifndef LECCION
#define LECCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "Ejercicio.hh"
// DataTypes
#include "DataTypes/DataEjercicio.hh"
#include "DataTypes/DatosEjercicio.hh"
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

    // Para el Caso de Uso : [Realizar Ejercicio]
    set<string> listaEjerciciosLeccion();
    string buscarLetraEnLeccion(int ejercicio);
    bool ejercicioEnLeccion(int ejercicio);
    Ejercicio* buscarEjercicioEnLeccionT(int ejercicio, string sol);
    Ejercicio* buscarEjercicioEnLeccionCP(int ejercicio, set<string> sol);

    // Para el Caso de Uso : [Consultar Estadisticas]
    int totalEjercicios();

};

#endif