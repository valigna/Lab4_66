#ifndef LECCION
#define LECCION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos del Modelo de Dominio
#include "Ejercicio.hh"
#include "CompletarPalabras.hh"
#include "Traduccion.hh"
// DataTypes
#include "DataTypes/DataLeccion.hh"
#include "DataTypes/DataEjercicio.hh"
/* ------------------------------------------------------------------------------------------------------ */


class Leccion
{
private:
    string Tema;
    string Objetivo;
    int Id;
    // PseudoAtributos...
    map<int,Ejercicio *> colEjercicios;
public:
    // Constructores

    // Destructor
    ~Leccion();
    // Getters y Setters
    string getTema();
    string getObjetivo();
    int getId();
    // DataTypes
    DataLeccion* getDataLeccion(bool conId);
    // Para el Caso de Uso : [Realizar Ejercicio]
    set<int> listaEjerciciosLeccion();
    string buscarLetraEnLeccion(int ejercicio);
    bool ejercicioEnLeccion(int ejercicio);
    DataEjercicio* buscarEjercicioEnLeccion(int ejercicio);
    Ejercicio* encontrarEjercicioEnLeccion(int ejercicio);
    Ejercicio* buscarEjercicioEnLeccionT(int ejercicio, string sol);
    Ejercicio* buscarEjercicioEnLeccionCP(int ejercicio, set<string> sol);

    // Para el Caso de Uso : [Agregar Ejercicio]
    void agregarEjercicio(DataEjercicio* ejercicio);

    // Para el Caso de Uso : [Consultar Estadisticas]
    int totalEjercicios();

};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */

/* ------------------------------------------------------------------------------------------------------ */

#endif