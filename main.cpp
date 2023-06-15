#include "include/Utils.hh"
#include "CasosDeUso.cpp"

int main()
{
    bool terminarEjecucion = false;
    bool primerVez = true;
    string opcion = "0";
    
    // Presentacion...
    /*
    // Bienvenidos al lab.... (NO mostrar opciones)
    
    */

    do
    {
        if(!primerVez)
        {   
            cout << "Ingresar proximo comando..." << endl;
            getline(cin, opcion);
        } else
        {
            primerVez = false;
        }
        
        switch (stoi(opcion))
        {
        case -1: // Terminar
            terminarEjecucion = true;
            break;

        case 0: // Mostrar opciones
            cout << "Estoy mostrando las opciones..." << endl;
            break;

        case 1: // Alta de Usuario
            altaUsuario();
            break;

        case 2: // Consulta de Usuario
            consultaUsuario();
            break;
        
        case 3: // Alta de Idioma
            altaIdioma();
            break;
        
        case 4: // Consultar Idiomas
            consultarIdiomas();
            break;

        case 5: // Alta de Curso
            break;

        case 6: // Agregar Leccion
            break;

        case 7: // Agregar Ejercicio
            break;
        
        case 8: // Habilitar Curso
            break;

        case 9: // Eliminar Curso
            break;
            
        case 10: // Consultar Curso
            consultarCurso();
            break;
            
        case 11: // Inscribirse a Curso
            break;
            
        case 12: // Realizar Ejercicio
            realizarEjercicio();
            break;
            
        case 13: // Consultar Estadisticas
            break;
            
        case 14: // Suscribirse a Notificaciones
            break;
            
        case 15: // Consulta de Notificaciones
            break;
            
        case 16: // Eliminar Suscripciones
            break;
            
        default:
            break;
        };

    } while (!terminarEjecucion);

    return 0;
}