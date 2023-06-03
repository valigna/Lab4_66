#ifndef DATA_FECHA
#define DATA_FECHA
/* ---------------------------------------------- Includes ---------------------------------------------- */
/* ------------------------------------------------------------------------------------------------------ */

class DataFecha
{
private:
    int Dia;
    int Mes;
    int Anio;
public:
    // Constructores
    DataFecha(int dia, int mes, int anio);
    // Destructor
    ~DataFecha();
    // Getters
    int getDia();
    int getMes();
    int getAnio();
};

#endif