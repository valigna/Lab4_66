#ifndef NOTIFICACION
#define NOTIFICACION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
// Conceptos del Modelo de Dominio
#include "Idioma.hh"
#include "Curso.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Notificacion
{
private:
    // PseudoAtributos...
    Idioma* MiIdioma;
    Curso* MiCurso;
public:
    // Constructores
    Notificacion(Idioma* i,Curso* c);
    // Destructor
    ~Notificacion();
    // Getters y Setters
   
    // Otros

    // Para el Caso De Uso : [Eliminar Curso]
    bool presentaCurso(string nombreCurso);

    DataNotificacion* darData();

    // Para el caso de uso: [Eliminar Suscripciones]
    string darIdioma();

};

/* --------------------------------- Cierre de los Forward Declarations --------------------------------- */

/* ------------------------------------------------------------------------------------------------------ */

#endif