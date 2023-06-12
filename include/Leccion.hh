#ifndef LECCION
#define LECCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos del Modelo de Dominio
#include "Ejercicio.hh"
#include "CompletarPalabras.hh"
#include "Traduccion.hh"
// DataTypes
#include "DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */


class Leccion
{
private:

    // PseudoAtributos...
    map<int,Ejercicio *> colEjercicios;
    
public:
    // Constructores

    // Destructor
    ~Leccion();
    // Getters y Setters

    // Para el Caso de Uso : [Realizar Ejercicio]
    set<int> listaEjerciciosLeccion();
    string buscarLetraEnLeccion(int ejercicio);
    bool ejercicioEnLeccion(int ejercicio);
    DataEjercicio* buscarEjercicioEnLeccion(int ejercicio);
    Ejercicio* buscarEjercicioEnLeccionT(int ejercicio, string sol);
    Ejercicio* buscarEjercicioEnLeccionCP(int ejercicio, set<string> sol);

    // Para el Caso de Uso : [Consultar Estadisticas]
    int totalEjercicios();

};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */

/* ------------------------------------------------------------------------------------------------------ */

#endif