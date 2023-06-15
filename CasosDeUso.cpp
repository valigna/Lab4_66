// Mi idea era de hacer todos los casos de uso, por decir de una forma 'Los DSS'
// , en este archivo y dejar el main para solamente el switch-case donde se eligen los
// casos de uso

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "include/Utils.hh"

// Fabrica
#include "include/InterfacesyControladores/distribuidorInterfaces.hh"

// DataTypes (???
/* #include "src/DataTypes/DataUsuario.cpp"
#include "src/DataTypes/DataProfesor.cpp"
#include "src/DataTypes/DataEstudiante.cpp" */

// Interfaces
//#include "include/InterfacesyControladores/IGestionUsuario.hh"
//#include "include/InterfacesyControladores/IGestionNotificaciones.hh"
//#include "include/InterfacesyControladores/IGestionCurso.hh"
//#include "include/InterfacesyControladores/IGestionIdiomas.hh"
//#include "include/InterfacesyControladores/IConsultarEstadisticas.hh"
/* ------------------------------------------------------------------------------------------------------ */

// Poner esto al Principio y Final de cada Caso de Uso...
// 

// Obtengo las instancias de los Controladores
distribuidorInterfaces* Fabrica = new distribuidorInterfaces();
IGestionCurso* gestionCurso = Fabrica->getIGestionCurso();



ControladorCurso* cc = ControladorCurso::getInstancia();
ControladorUsuario* cu = ControladorUsuario::getInstancia();


// Para el Caso de Uso 1: [Alta de Usuario]

struct userInfo{
    // Declaro las variables necesarias para crear un Usuario
    string name;
    string nick;
    string pass;
    string desc;

    string opcion;
    // Estudiante
    string pResidencia;
    string dia,mes,anio;
    // Profesor
    string ins;
    set<string> seleccionados;
};

void altaUsuario()
{
    userInfo ingresado;
    cout << "Para poder crear un nuevo Usuario en el sistema, porfavor ingrese: " << endl;
    cout << "o Su Nombre: "; getline(cin,ingresado.name);
    cout << "o El Nickname por el cual quiere ser reconocido en el sistema: "; getline(cin,ingresado.nick);
    cout << "o Una breve descricpion sobre usted: "; getline(cin,ingresado.desc);

    // Pasamos a distinguir entre Estudiante y Profesor
    cout << "o El usuario que se va a crear es de : (1) Un Estudiante? / (2) Un Profesor? "; getline(cin,ingresado.opcion); cout << endl;

    if(stoi(ingresado.opcion) == 1)
    {
        cout << "Se pasaran a pedir los datos necesarios para crear un Estudiante: " << endl;
        cout << "o Pais de Residencia: "; getline(cin,ingresado.pResidencia);
        cout << "o Fecha de Nacimiento, escribiendo por separado:" << endl;
        cout << "  -> Dia: "; getline(cin,ingresado.dia);
        cout << "  -> Mes: "; getline(cin,ingresado.mes);
        cout << "  -> Anio: "; getline(cin,ingresado.anio);

        DataFecha* f = new DataFecha(stoi(ingresado.dia),stoi(ingresado.mes),stoi(ingresado.anio));
        cu->ingresarUsuario(new DataEstudiante(ingresado.nick,ingresado.name,ingresado.pass,ingresado.desc,ingresado.pResidencia,f));
    } else
    {
        cout << "Se pasaran a pedir los datos necesarios para crear un Profesor: " << endl;
        cout << "o Instituto donde trabaja: "; getline(cin,ingresado.ins);
        cout << "o Idiomas en los que se especializa:" << endl;
        cout << "Para ello..." << endl;
        cout << "1- Se listaran los idiomas con los que cuenta el sistema" << endl;
        set<string> idiomasSistema = cu->getIdiomas();
        for(set<string>::iterator it = idiomasSistema.begin(); it != idiomasSistema.end(); ++it){ cout << "  -> " << (*it) << endl; }
        cout << "2- Ingrese, uno a la vez, los idiomas en los cuales se especializa. Terminar con '-1'" << endl;
        bool masIdiomas = true;
        string idi;
        while(masIdiomas)
        {
            getline(cin,idi);
            if(idi != "-1")
            {
                ingresado.seleccionados.insert(idi);
            } else
            {
                masIdiomas = false;
            }
        }
        
        cu->ingresarIdiomas(ingresado.seleccionados);
        cu->ingresarUsuario(new DataProfesor(ingresado.nick,ingresado.name,ingresado.pass,ingresado.desc,ingresado.ins));
    }

    bool altaExitosa = cu->confirmarAltaUsuario();
    if (altaExitosa)
    {
        cout << "Se creo el usuario de nickname: " << ingresado.nick << "." << endl;
    } else
    {
        cout << "Hubo una falla a la hora de crear el Usuario pedido, seguramente se deba a que el nickname ingresado ya esta un uso." << endl;
    }
}

// Para el Caso de Uso 2: [Consulta de Usuario]
void consultaUsuario()
{
    string seleccionado;
    set<string> usuarios = cu->getNicksUsuarios();
    cout << "Los usuarios con los que cuenta el sistema son los de nickname: " << endl;
    for(set<string>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {cout << "-> " << (*it) << endl; }
    cout << "o Ingresar el nickname del cual quiera consultar su informacion: "; getline(cin,seleccionado); cout << endl;
    DataUsuario* datos = cu->getDatosUsuario(seleccionado);

    if(datos->esEstudiante())
    {
        DataEstudiante* est = (DataEstudiante*) datos;
        cout << "Usted selecciono al estudiante con:" << endl;
        cout << "-> Nombre: " << datos->getNombre() << endl;
        cout << "-> Descripcion: " << datos->getDescripcion() << endl;
        DataFecha* nac = est->getNacimiento();
        cout << "-> Pais de Residencia: " << est->getPaisResidencia() << endl;
        cout << "-> Nacimiento: " << nac->getDia() << "/" << nac->getMes() << "/" << nac->getAnio() << endl;
    } else
    {
        DataProfesor* prof = (DataProfesor*) datos;
        cout << "Usted selecciono al profesor con:" << endl;
        cout << "-> Nombre: " << datos->getNombre() << endl;
        cout << "-> Descripcion: " << datos->getDescripcion() << endl;
        cout << "-> Instituto donde trabaja: " << prof->getInstituto() << endl;
        set<string> idiomas = prof->getIdiomas();
        cout << "-> Idiomas en los que se especializa: " << endl;
        for(set<string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it){cout << "   |-> " << (*it) << endl; }
    }

}

// Para el Caso de Uso 3: [Alta de Idioma]
void altaIdioma()
{
    string nombre;
    cout << "o Ingrese el nombre del idioma que quiere dar de alta en el sistema: "; getline(cin,nombre);

    bool altaExitosa = cc->altaIdioma(nombre);
    if (altaExitosa)
    {
        cout << "-> Se creo el idioma: " << nombre << endl;
    } else
    {
        cout << "Error: El idioma ya se encuentra creado en el sistema" << endl;
    }
}

// Para el Caso de Uso 4: [Consultar Idiomas]
void consultarIdiomas()
{
    set<string> idiomas = cc->getIdiomas();
    cout << "Los idiomas creados en el sistema son: " << endl;
    for(set<string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
}

// Para el Caso de Uso 5: [Alta de Curso]
void altaCurso()
{
    
}

// Para el Caso de Uso 6: [Agregar Leccion]
void agregarLeccion()
{

}

// Para el Caso de Uso 7: [Agregar Ejercicio]
void agregarEjercicio()
{

}

// Para el Caso de Uso 8: [Habilitar Curso]
void habilitarCurso()
{

}

// Para el Caso de Uso 9: [Eliminar Curso]
void eliminarCurso()
{
    
}

// Para el Caso de Uso 10: [Consultar Curso]
void consultarCurso()
{
    set<string> aux = cc->darNombreCursos();
    cout << "o Cursos disponibles: " << endl;
    for(set<string>::iterator it = aux.begin(); it != aux.end(); it++){
        cout << "-> " << (*it) << endl;
    }
    cout << "Ingrese el nombre de un curso";
    string seleccionado;
    getline(cin, seleccionado);
    cout << endl;
    DataConsultaCurso* res = cc->obtenerDataCursoSeleccionado(seleccionado);
    cout << "-> Nombre: " << res->getNombre() << endl;
    cout << "-> Idioma: " << res->getIdioma() << endl;
    cout << "-> Profesor: " << res->getProfesor() << endl;
    cout << "-> Descripcion: " << res->getDescripcion() << endl;
    cout << "-> Dificultad: " << res->getDifificulty() << endl;
    if(res->getHabilitado()){
        cout << "-> Habilitado: SI" << endl;
    }
    else{
        cout << "-> Habilitado: NO" << endl;
    }

}

// Para el Caso de Uso 11: [Inscribirse a Curso]
void inscribirseCurso()
{
    
}

// Para el Caso de Uso 12: [Realizar Ejercicio]
void realizarEjercicio()
{
    string nombre;
    cout << "o Ingrese su nickname: "; getline(cin,nombre);
    cout << "o Cursos no aprobados: " << endl;
    set<string> cursos = cu->getCursosInscriptosNoAporbados(nombre);
    for(set<string>::iterator it = cursos.begin(); it != cursos.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
    cout << "Escriba el nombre de un curso: ";
    string cursoSeleccionado;
    getline(cin,cursoSeleccionado);
    cout << endl;
    set<DataEjercicio* > ejercicios = cu->getEjerciciosNoAprobados(cursoSeleccionado);
    cout << "ID de los ejercicios no aprobados: " << endl;
    for(set<DataEjercicio* >::iterator it = ejercicios.begin(); it != ejercicios.end(); it++){
        cout << "-> " << (*it)->getId() << endl;
    }
    cout << "Escriba el ID de un ejercicio que quiera realizar: ";
    string aux;
    getline(cin, aux);
    int idEjercicio = stoi(aux);
    cout << "Letra: " << endl;
    cout << "" << cu->getProblema(idEjercicio) << endl;
    DataEjercicio* eje = cc->encontrarEjercicio(cursoSeleccionado, idEjercicio);
    if(eje->esCompletarPalabras()){
        cout << "Escriba sus soluciones, una por una, y termine con -1: " << endl;
        set<string> respuestaCP;
        string resCP;
        bool respuestas = true;
        while(respuestas){
            getline(cin,resCP);
            if(resCP != "-1")
            {
                respuestaCP.insert(resCP);
            } else
            {
                respuestas = false;
            }
        }
        cu->resolverEjercicioCP(idEjercicio, respuestaCP);
    }
    else{
        string respuestaT;
        cout << "Escriba su solucion: "; getline(cin, respuestaT);
        cu->resolverEjercicioT(idEjercicio, respuestaT);
    }
}

// Para el Caso de Uso 13: [Consultar Estadisticas]
void consultarEstadisticas()
{

}

// Para el Caso de Uso 14: [Suscribirse a Notificaciones]
void suscribirseNotificaciones()
{

}

// Para el Caso de Uso 15: [Consulta de Notificaciones]
void consultaNotificaciones()
{

}

// Para el Caso de Uso 16: [Eliminar Suscripciones]
void eliminarSuscripciones()
{

}
