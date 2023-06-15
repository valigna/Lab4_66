#ifndef DATA_NOTIFICACION
#define DATA_NOTIFICACION

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataNotificacion
{
private:
    string Idioma;
    string NombreCurso;
public:
    // Constructores
    DataNotificacion(string idi,string nomC);
    // Destructor
    ~DataNotificacion();
    // Getters
    string getIdioma();
    string getNombreCurso();
};

#endif