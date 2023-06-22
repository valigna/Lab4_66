#include "include/Utils.hh"
#include "CasosDeUso.cpp"

/* ------------------------------------- Funciones Auxiliares Para Hacer Mas Prolijo el Menu... ------------------------------------- */
#define CON_ENTER true
#define SIN_ENTER false

void separacion(bool conEnter)
{
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    cout << setw(w.ws_col) << setfill('*') << "*" << endl;
    if(conEnter){ cout << endl; }
}

void titulo(string titulo)
{
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int freeSpace = w.ws_col - titulo.length();
    int halfCol = freeSpace / 2;
    cout << string(halfCol,'*');
    cout << titulo;
    if((halfCol % 2) != 0){halfCol++;}
    cout << string(halfCol,'*');
    cout << endl;
}
/* ---------------------------------------------------------------------------------------------------------------------------------- */

int main()
{
    bool terminarEjecucion = false;
    bool primerVez = true;
    bool datosCargados = false;
    string opcion = "42";
    int numOpcion;
    
    // Presentacion...
    titulo(" Laboratorio 4 | Grupo 66 ");
    cout << "Integrantes:" << endl;
    cout << "|-> Ignacio Pérez | CI: 5.298.266-0" << endl;
    cout << "|-> Mateo Olveira | CI: 5.314.183-5" << endl;
    cout << "|-> Juan Ignacio Valero | CI: 4.942.857-4" << endl;
    cout << "|-> Martin Idiart | CI: 5.641.696-0" << endl;
    cout << "|-> Bruno Martínez | CI: 5.316.644-9" << endl;
    cout << endl;
    cout << "Docente: Leonel Peña" << endl;
    separacion(CON_ENTER);

    do
    {
        if(!primerVez)
        {
            separacion(SIN_ENTER);
            cout << "Ingresar proximo comando: ";
            getline(cin, opcion);
            separacion(CON_ENTER);
        }

        if(!stoi(opcion))
        {
            numOpcion = 0;
        } else
        {
            numOpcion = stoi(opcion);
        }
        switch (numOpcion)
        {
        case -1: // Terminar
            separacion(SIN_ENTER);
            cout << "Se dio por finalizada la ejecucion del lab4_66" << endl;
            liberarFabrica();
            separacion(CON_ENTER);
            terminarEjecucion = true;
            break;

        case 0: // Para la carga de los datos publicados en el EVA
            if(!datosCargados)
            {
                datosCargados = true;
                csvLoad();
            } else
            {
                cout << "-> Los datos publicados en el EVA ya se encuentran cargados en el sistema" << endl;
            }
            cout << endl;
            break;

        case 1: // Alta de Usuario
            altaUsuario();
            cout << endl;
            break;

        case 2: // Consulta de Usuario
            consultaUsuario();
            cout << endl;
            break;
        
        case 3: // Alta de Idioma
            altaIdioma();
            cout << endl;
            break;
        
        case 4: // Consultar Idiomas
            consultarIdiomas();
            cout << endl;
            break;

        case 5: // Alta de Curso
            altaCurso();
            cout << endl;
            break;

        case 6: // Agregar Leccion
            agregarLeccion();
            cout << endl;
            break;

        case 7: // Agregar Ejercicio
            agregarEjercicio();
            cout << endl;
            break;
        
        case 8: // Habilitar Curso
            habilitarCurso();
            cout << endl;
            break;

        case 9: // Eliminar Curso
            eliminarCurso();
            cout << endl;
            break;
            
        case 10: // Consultar Curso
            consultarCurso();
            cout << endl;
            break;
            
        case 11: // Inscribirse a Curso
            inscribirseCurso();
            cout << endl;
            break;
            
        case 12: // Realizar Ejercicio
            realizarEjercicio();
            cout << endl;
            break;
            
        case 13: // Consultar Estadisticas
            consultarEstadisticas();
            cout << endl;
            break;
            
        case 14: // Suscribirse a Notificaciones
            suscribirseNotificaciones();
            cout << endl;
            break;
            
        case 15: // Consulta de Notificaciones
            consultaNotificaciones();
            cout << endl;
            break;
            
        case 16: // Eliminar Suscripciones
            eliminarSuscripciones();
            cout << endl;
            break;
            
        default:
            if(!primerVez)
            {
                cout << "-> El comando ingresado no es valido, mostrando nuevamente las opciones" << endl;
                cout << endl;
            } else
            {
                primerVez = false;
            }
            
            titulo(" Comandos ");
            cout << "(0) Cargar los datos publicados en el EVA" << endl;
            cout << "(1) Alta de Usuario" << endl;
            cout << "(2) Consulta de Usuario" << endl;
            cout << "(3) Alta de Idioma" << endl;
            cout << "(4) Consultar Idiomas" << endl;
            cout << "(5) Alta de Curso" << endl;
            cout << "(6) Agregar Leccion" << endl;
            cout << "(7) Agregar Ejercicio" << endl;
            cout << "(8) Habilitar Curso" << endl;
            cout << "(9) Eliminar Curso" << endl;
            cout << "(10) Consultar Curso" << endl;
            cout << "(11) Inscribirse a Curso" << endl;
            cout << "(12) Realizar Ejercicio" << endl;
            cout << "(13) Consultar Estadisticas" << endl;
            cout << "(14) Suscribirse a Notificaciones" << endl;
            cout << "(15) Consulta de Notificaciones" << endl;
            cout << "(16) Eliminar Suscripciones" << endl;
            cout << "[-1] Terminar Ejecucion" << endl;
            separacion(CON_ENTER);
            break;
        };

    } while (!terminarEjecucion);

    return 0;
}