/* El objetivo de este main es el de hacer pruebas para ver si [Alta Usuario] funciona...*/

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "src/ControladorUsuario.cpp"
#include "src/Usuario.cpp"
#include "src/Estudiante.cpp"
#include "src/Profesor.cpp"
#include "src/ControladorCurso.cpp"
#include "src/Curso.cpp"
#include "src/Leccion.cpp"
#include "src/Ejercicio.cpp"
#include "src/Idioma.cpp"

#include "src/Inscripcion.cpp"
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include <iostream>
using namespace std;
/* ------------------------------------------------------------------------------------------------------ */
int main()
{
    // Obtengo las instancias de los Controladores
    ControladorCurso* cc = ControladorCurso::getInstancia();
    ControladorUsuario* cu = ControladorUsuario::getInstancia();

    // Declaro las variables necesarios para crear un Usuario
    string name;
    string nick;
    string pass;
    string desc;
    // Estudiante
    Estudiante* e = NULL;
    string pResidencia;
    DataFecha* Nacimiento;
    // Profesor
    Profesor* p = NULL;
    string ins;
    string idi;
    set<string> idiomas;

    cout << "Testeando Caso de Uso : [Alta de Usuario]" << endl;

    cout << "Todo usuario requiere de los siguientes campos:" << endl;
    cout << "Ingrese su nombre: " << endl;
    cin >> name;
    cout << "Ingrese el nickname por el cual quiere ser reconocido en la app: " << endl;
    cin >> nick;
    cout << "Ingrese su contrasenia:" << endl;
    cout << "(Tener en cuenta que su contrasenia debe de contener al menos 6 caracteres...)" << endl;
    cin >> pass;
    cout << "Ingrese una descripcion" << endl;
    cin >> desc;

    cout << "Luego, indicar con un: (1) Estudiante / (2) Profesor" << endl;
    int eleccion = 0;
    cin >> eleccion;

    if (eleccion == 1)
    {
        cout << "Al parecer elegiste el alta de un Estudiante, para ello le pediremos los siguientes datos: " << endl;
        cout << "Cual es su pais de residencia?" << endl;
        cin >> pResidencia;
        cout << "A continuacion viene su fecha de nacimiento, por favor ingresar dia, mes y anio (Uno a la vez)" << endl;
        int dia,mes,anio;
        dia = mes = anio = 0;
        cin >> dia;
        cin >> mes;
        cin >> anio;
        Nacimiento = new DataFecha(dia,mes,anio);
        
        // Se dara de alta el Estudiante...
        DataUsuario* datos = new DataEstudiante(nick,name,pass,desc,pResidencia,Nacimiento);
        cu->ingresarUsuario(datos);
    } else
    {
        cout << "Al parecer elegiste el alta de un Profesor, para ello le pediremos los siguientes datos: " << endl;
        cout << "En que instituto trabaja?" << endl;
        cin >> ins;
        cout << "En que idiomas se especializa? (Ingresar uno por uno los nombres, terminar con 'Termine'" << endl;
        cin >> idi;
        while (idi != "Termine")
        {
            idiomas.insert(idi);
        }
        cu->ingresarIdiomas(idiomas);

        // Se dara de alta el Profesor...
        DataUsuario* datos = new DataProfesor(nick,name,pass,desc,ins);
        cu->ingresarUsuario(datos); 
    }
    
    cout << "Desea confirmar el alta de dicho usuario? (Si/No)" << endl;
    string res;
    cin >> res;
    if (res == "Si")
    {
        cu->confirmarAltaUsuario();
        // Haber si puedo mostrar en pantalla los datos ingresados...
        cout << "Si todo salio bien... Usted ingreso:" << endl;
        if (p != NULL)
        {
            cout << "El profesor: " << p->getNickname() << ' ' << p->getNombre() << ' ' << p->getPassword() << ' ' <<  p->getDescripcion() << ' ' << p->getInstituto() << endl;
        } else
        {
            cout << "El estudiante: " << e->getNickname() << ' ' << e->getNombre() << ' ' << e->getPassword() << ' ' <<  e->getDescripcion() << ' ' << e->getPaisResidencia();
            DataFecha* aux = e->getNacimiento();
            cout << " Que nacio el: " << aux->getDia() << '/' << aux->getMes() << '/' << aux->getAnio() << endl;
        }
    }

    return 1;
}