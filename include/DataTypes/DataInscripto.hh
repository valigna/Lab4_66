#ifndef DATA_INSCRIPTO
#define DATA_INSCRIPTO

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "../Utils.hh"
#include "DataFecha.hh"
/* ------------------------------------------------------------------------------------------------------ */

class DataInscripto
{
private:
    string nombre;
    DataFecha* fecha;
public:
    // Constructores
    DataInscripto(string nombre, DataFecha* fecha);
    // Destructor
    ~DataInscripto();
    
    // Getters
    string getNombre();
    DataFecha* getFecha();
};
#endif