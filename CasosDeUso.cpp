// Mi idea era de hacer todos los casos de uso, por decir de una forma 'Los DSS'
// , en este archivo y dejar el main para solamente el switch-case donde se eligen los
// casos de uso

/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "include/Utils.hh"
// Fabrica
#include "include/InterfacesyControladores/distribuidorInterfaces.hh"

// Para cargar los datos publicados en el EVA
#include "csvLoad.cpp"
//#include "nuevo_csvLoad.cpp"
/* ------------------------------------------------------------------------------------------------------ */

// Poner esto al Principio y Final de cada Caso de Uso...
// 

// Obtengo la Fabrica junto a sus interfaces...
distribuidorInterfaces* Fabrica = new distribuidorInterfaces();

IGestionUsuario* gestionUsuario = Fabrica->getIGestionUsuario();
IGestionNotificaciones* gestionNotificaciones = Fabrica->getIGestionNotificaciones();
IGestionCurso* gestionCurso = Fabrica->getIGestionCurso();
IGestionIdiomas* gestionIdiomas = Fabrica->getIGestionIdiomas();
IConsultarEstadisticas* consEstadisticas = Fabrica->getIConsultarEstadisticas();


// Esto no deberia de estar en la version final...
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

struct courseInfo{
    string nombre;
    string desc;
    string opcionDiff;
    difficulty diff;
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
        set<string> idiomasSistema = gestionIdiomas->getIdiomas();
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
    cout << "o Ingrese el nombre del idioma que quiere dar de alta en el sistema: ";
    getline(cin,nombre);

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
    set<string> nickProfesores = cc->getNicknamesProfesores();
    string nickProfesor;
    string idioma;
    courseInfo infoCurso;
    cout << "Profesores: " << endl;
    for(set<string>::iterator it = nickProfesores.begin(); it != nickProfesores.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
    cout << "Ingrese el nickname del profesor que dara de alta al curso: "; getline(cin,nickProfesor);
    cout << "Se pasaran a pedir los datos necesarios para crear un nuevo curso." << endl;
    cout << "o Nombre del curso: "; getline(cin, infoCurso.nombre);
    cout << "o Descripcion: "; getline(cin, infoCurso.desc);
    cout << "o El curso a crearse es de dificultad: (1) Principiante / (2) Intermedio / (3) Avanzado: "; getline(cin, infoCurso.opcionDiff);
    if (infoCurso.opcionDiff == "1")
    {
        infoCurso.diff = Principiante;
    } else if (infoCurso.opcionDiff == "2")
    {
        infoCurso.diff = Intermedio;
    } else if (infoCurso.opcionDiff == "3")
    {
        infoCurso.diff = Avanzado;
    }
    cc->ingresarDataCurso(nickProfesor, new DTCurso(infoCurso.nombre, infoCurso.desc, infoCurso.diff));
    set<string> idiomas = cc->getIdiomasProfesor();
    cout << "o Se listaran los idiomas en los cuales se especializa el profesor: " << endl;
    for (set<string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
    cout << "o Seleccione el idioma del curso entre los listados: "; getline(cin, idioma);
    cc->agregarIdiomaCurso(idioma);
    cout << "o Se pasara a listar los cursos habilitados, entre los cuales debe seleccionar aquellos que sean previas de el curso a crear: " << endl;
    set<string> cursosHab = cc->getNombreCursosHabilitados();
    for (set<string>::iterator it = cursosHab.begin(); it != cursosHab.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    } 
    cout << "o Ingrese, uno a la vez, los cursos que son previos del creado. Terminar con '-1'" << endl;
    bool masCursos = true;
    set<string> previos;
    string previo;
    while (masCursos)
    {
        getline(cin, previo);
        if (previo != "-1")
        {
            previos.insert(previo);
        } else
        {
            masCursos = false;
        }
    }
    cc->ingresarCursosPrevios(previos);
    cout << "o Comenzaremos a ingresar las lecciones del curso:" << endl;
    bool masLecciones = true;
    while (masLecciones)
    {
        string tema;
        string objetivo;
        string aux;
        cout << "o Desea agregar una nueva leccion?: (1) Si, (2) No: "; getline(cin, aux);
        if (aux == "1")
        {
            cout << "o Ingrese el tema de la leccion: "; getline(cin, tema);
            cout << "o Ingrese el objetivo de la leccion: "; getline(cin, objetivo);
            cc->ingresarLeccionParaAlta(tema, objetivo);
            bool masEjercicios = true;
            string descEj;
            string auxEj;
            cout << "o Ingrese los ejercicios de la leccion:" << endl;
            while (masEjercicios)
            {   
                cout << "o Desea agregar un nuevo ejercicio?: (1) Si, (2) No: "; getline(cin, auxEj);
                if (auxEj == "1")
                { 
                    string tipoEj;
                    cout << "o Que tipo de ejercicio desea agregar: (1) Completar Palabras, (2) Traduccion: "; getline(cin, tipoEj);
                    cout << "o Ingrese la descripcion del ejercicio: "; getline(cin, descEj);
                    if (tipoEj == "1")
                    {
                        string frase;
                        string solucionLeida;
                        set<string> solucion;
                        string palabra;
                        cout << "o Ingrese la frase: "; getline(cin, frase);
                        cout << "o Ingrese la solucion separando las palabras con SOLO ',': "; getline(cin, solucionLeida);
                        stringstream str(solucionLeida);
                        while(getline(str,palabra,','))
                        {
                            solucion.insert(palabra);    
                        }
                        DataCompletarPalabras* ejCP = new DataCompletarPalabras(descEj, 0, frase, solucion);
                        gestionCurso->ingresarEjercicioParaAlta(ejCP);
                    } else if (tipoEj == "2")
                    {
                        string frase;
                        string traduccion;
                        cout << "o Ingrese la frase: "; getline(cin, frase);
                        cout << "o Ingrese la frase traducida: "; getline(cin, traduccion);
                        DataTraduccion* ejT = new DataTraduccion(descEj, 0, frase, traduccion);
                        gestionCurso->ingresarEjercicioParaAlta(ejT);
                    }
                    
                } else if (auxEj == "2")
                {
                    masEjercicios = false;
                }
            }
            gestionCurso->confirmarLeccion();
        } else if (aux == "2")
        {
            masLecciones = false;
        }
    }
    cc->confirmarAltaCurso();
    cout << "-> Se creo el curso: " << infoCurso.nombre << endl;
}

// Para el Caso de Uso 6: [Agregar Leccion]
void agregarLeccion()
{
    set<InformacionCurso *> cursos = gestionCurso->getCursosNoHabilitados();
    if(!cursos.empty()){
        cout << "o Cursos no habilitados: " << endl;
        for(set<InformacionCurso*>::iterator it = cursos.begin(); it != cursos.end(); it++){
            cout << "->" << ((*it)->getNombre()) << endl;
        }
        string nombreCurso;
        cout << "o Ingrese el nombre del curso que desea agregar una leccion: ";
        getline(cin, nombreCurso);
        
        string temaLeccion;
        cout << "o Ingrese el tema de la Leccion: " << endl;
        getline(cin, temaLeccion);

        string objetivoLeccion;
        cout << "o Ingrese el objetivo de la Leccion: " << endl;
        getline(cin, objetivoLeccion);

        gestionCurso->ingresarDatosLeccion(nombreCurso, temaLeccion, objetivoLeccion);

        //Faltan los ejercicios

        gestionCurso->altaLeccion();
    }

}

// Para el Caso de Uso 7: [Agregar Ejercicio]
void agregarEjercicio()
{

}

// Para el Caso de Uso 8: [Habilitar Curso]
void habilitarCurso()
{
    set<InformacionCurso*> cursos = gestionCurso->getCursosNoHabilitados();
    if (!cursos.empty())
    {
        cout << "o Cursos no habilitados: " << endl;
        for(set<InformacionCurso*>::iterator it = cursos.begin(); it != cursos.end(); it++)
        {
            cout << "-> " << ((*it)->getNombre()) << endl;
        }
        string curso;
        cout << "o Ingrese el nombre del curso que desea habilitar: "; getline(cin, curso);
        gestionCurso->habilitarCurso(curso);
        cout << "o El curso fue habilitado correctamente" << endl;
    } else
    {
        cout << "o No hay cursos por habilitar" << endl; 
    }
}

// Para el Caso de Uso 9: [Eliminar Curso]
void eliminarCurso()
{
    cout << "o Cursos creados: " << endl;
    set<string> cursos = gestionCurso->getNombreCursos();
    for(set<string>::iterator it = cursos.begin(); it != cursos.end(); it++){
        cout << "-> " << (*it) << endl;
    }
    cout << "---------o---------" << endl;
    cout << "o Ingrese el nombre del curso que desea eliminar" << endl;
    string nombreCurso;
    getline(cin,nombreCurso);
    gestionCurso->bajarCurso(nombreCurso);
    cout << "o El curso de nombre " << nombreCurso << " fue eliminado";
}

// Para el Caso de Uso 10: [Consultar Curso]
void consultarCurso()
{
    set<string> aux = cc->darNombreCursos();
    if (!aux.empty())
    {
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
        difficulty dificultad = res->getDifificulty();
        switch (dificultad)
        {
        case Principiante:
            cout << "-> Dificultad: Principiante" << endl;
            break;
        case Intermedio:
            cout << "-> Dificultad: Intermedio" << endl;
            break;
        case Avanzado:
            cout << "-> Dificultad: Avanzado" << endl;
            break;
        default:
            break;
        }
        if(res->getHabilitado()){
            cout << "-> Habilitado: SI" << endl;
        }
        else{
            cout << "-> Habilitado: NO" << endl;
        }
    } else
    {
        cout << "No hay cursos cargados." << endl;
    }
    
}

// Para el Caso de Uso 11: [Inscribirse a Curso]
void inscribirseCurso() //Hacer verificacion de que existe el curso
{
    cout << "o Ingrese su nickname" << endl;
    string nicknameUsuario;
    getline(cin, nicknameUsuario);
    set<InformacionCurso *> cursos = gestionUsuario->getCursosDisponibles(nicknameUsuario);
    cout << "o Sus cursos disponibles son:" << endl;
    for(set<InformacionCurso *>::iterator it = cursos.begin(); it != cursos.end(); it++){
        cout << "-> " << (*it)->getNombre() << endl;
        cout << "   -Descripcion: " << (*it)->getDescripcion() << endl;
        cout << "   -Dificultad: " << (*it)->getDificultad() << endl;
        cout << "   -Cantidad de Lecciones: " << (*it)->getCantLecciones() << endl;
        cout << "   -Cantidad de Ejercicios: " << (*it)->getCantEjercicios() << endl;
    }
    cout << "---------o---------" << endl;
    cout << "o Ingrese el nombre del curso al que se quiere inscribir" << endl;
    string nombreCurso;
    getline(cin,nombreCurso);
    gestionUsuario->inscribirseACurso(nombreCurso);
    cout << "o Inscripcion completada" << endl;
}

// Para el Caso de Uso 12: [Realizar Ejercicio]
void realizarEjercicio()
{
    string nombre;
    cout << "o Ingrese su nickname: "; getline(cin,nombre);
    cout << "o Cursos no aprobados: " << endl;
    set<string> cursos = cu->getCursosInscriptosNoAprobados(nombre);
    for(set<string>::iterator it = cursos.begin(); it != cursos.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
    cout << "Escriba el nombre de un curso: ";
    string cursoSeleccionado;
    getline(cin,cursoSeleccionado);
    set<DataEjercicio *> ejercicios = gestionUsuario->getEjerciciosNoAprobados(cursoSeleccionado);
    cout << "ID de los ejercicios no aprobados: " << endl;
    for(set<DataEjercicio* >::iterator it = ejercicios.begin(); it != ejercicios.end(); it++){
        cout << "-> " << (*it)->getId() << endl;
    }
    cout << "Escriba el ID de un ejercicio que quiera realizar: ";
    string aux;
    getline(cin, aux);
    int idEjercicio = stoi(aux);
    cout << "Letra: " << endl;
    cout << "" << cc->obtenerLetra(cursoSeleccionado,idEjercicio) << endl;
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
    string nick;
    cout << "Ingrese su nickname: "; getline(cin, nick);
    cout << "Idiomas no suscrito: " << endl;
    set<string> idiomas = cu->idiomasNoSuscritos(nick);
    for(set<string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
    bool masIdiomas = true;
    cout << "Escriba los idiomas a los cuales desea suscribirse, uno por uno, y termine con -1: " << endl;
    set<string> idiomasSeleccionados;
    string idioma;
    while (masIdiomas)
    {
        getline(cin, idioma);
        if (idioma != "-1")
        {
            idiomasSeleccionados.insert(idioma);
        } else
        {
            masIdiomas = false;
        }
    }
    cu->suscribirse(idiomasSeleccionados);
    cout << "Se ha suscrito correctamente a los siguientes idiomas: " << endl;
    for(set<string>::iterator it = idiomasSeleccionados.begin(); it != idiomasSeleccionados.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
}

// Para el Caso de Uso 15: [Consulta de Notificaciones]
void consultaNotificaciones()
{
    string nick;
    cout << "Ingrese su nickname: "; getline(cin, nick);
    set<DataNotificacion *> notif = cu->obtenerNotificaciones(nick);
    cout << "Aqui estan sus notificaciones: " << endl;
    for(set<DataNotificacion *>::iterator it = notif.begin(); it != notif.end(); ++it)
    {
        cout << "-> Idioma: " << (*it)->getIdioma() << endl;
        cout << "-> Nuevo Curso: " << (*it)->getNombreCurso() << endl;
        cout << endl;
    }
}

// Para el Caso de Uso 16: [Eliminar Suscripciones]
void eliminarSuscripciones()
{

}
