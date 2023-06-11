#ifndef IDIOMA
#define IDIOMA


/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "Utils.hh"
#include "InterfacesyControladores/Suscripcion.hh"
/* ------------------------------------------------------------------------------------------------------ */

class Idioma
{
private:
    string Nombre;
    // Pseudoatibutos...
    vector<Suscripcion *> colSuscripciones;
public:
    // Constructores
    Idioma(string nombre);
    // Destructor
    ~Idioma();
    // Getters y Setters
    string getNombre();

    // Otros
    void cursoEliminado(string nombreCurso);

   // Para el Caso de Uso : [Suscribirse a Notificaciones]
   void agregar(Suscripcion* u);
};

#endif