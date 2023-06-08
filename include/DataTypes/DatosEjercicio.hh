#ifndef DATOS_EJERCICIO
#define DATOS_EJERCICIO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
/* ------------------------------------------------------------------------------------------------------ */
class DatosEjercicio{
    private:
        string descripcionEjercicio;
        float idEjercicio;
    public:
        // Contructores
        DatosEjercicio(string descripcionEjercicio, float idEjercicio);
        // Destructores
        ~DatosEjercicio();
        // Getters
        string getDescripcionEjercicio();
        float getIdEjercicio();    
};

#endif