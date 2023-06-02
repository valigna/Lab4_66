#ifndef DATOSEJERCICIOS
#define DATOSEJERCICIO

//Includes..
#include "../Utils.hh"

class DatosEjercicio{
    private:
        string descripcionEjercicio;
        float idEjercicio;
    public:
        DatosEjercicio(string descripcionEjercicio, float idEjercicio);
        ~DatosEjercicio();
        string getDescripcionEjercicio();
        float getIdEjercicio();    
}

#endif