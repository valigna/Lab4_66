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
//ControladorCurso* cc = ControladorCurso::getInstancia();
//ControladorUsuario* cu = ControladorUsuario::getInstancia();


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
        cout << "Fecha de Nacimiento, escribiendo por separado:" << endl;
        cout << "  o Dia: "; getline(cin,ingresado.dia);
        cout << "  o Mes: "; getline(cin,ingresado.mes);
        cout << "  o Anio: "; getline(cin,ingresado.anio);

        DataFecha* f = new DataFecha(stoi(ingresado.dia),stoi(ingresado.mes),stoi(ingresado.anio));
        gestionUsuario->ingresarUsuario(new DataEstudiante(ingresado.nick,ingresado.name,ingresado.pass,ingresado.desc,ingresado.pResidencia,f));
    } else
    {
        cout << "Se pasaran a pedir los datos necesarios para crear un Profesor: " << endl;
        cout << "o Instituto donde trabaja: "; getline(cin,ingresado.ins);
        cout << "o Idiomas en los que se especializa:" << endl;
        cout << "Para ello..." << endl;
        cout << "1- Se listaran los idiomas con los que cuenta el sistema" << endl;
        set<string> idiomasSistema = gestionIdiomas->getIdiomas();
        for(set<string>::iterator it = idiomasSistema.begin(); it != idiomasSistema.end(); ++it){ cout << "  |-> " << (*it) << endl; }
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
        
        gestionUsuario->ingresarIdiomas(ingresado.seleccionados);
        gestionUsuario->ingresarUsuario(new DataProfesor(ingresado.nick,ingresado.name,ingresado.pass,ingresado.desc,ingresado.ins));
    }

    bool altaExitosa = gestionUsuario->confirmarAltaUsuario();
    if (altaExitosa)
    {
        cout << "-> Se creo el usuario de nickname: " << ingresado.nick << "." << endl;
    } else
    {
        cout << "-> Hubo una falla a la hora de crear el Usuario pedido, seguramente se deba a que el nickname ingresado ya esta un uso." << endl;
    }
}

// Para el Caso de Uso 2: [Consulta de Usuario]
void consultaUsuario()
{
    string seleccionado;
    set<string> usuarios = gestionUsuario->getNicksUsuarios();
    cout << "Los usuarios con los que cuenta el sistema son los de nickname: " << endl;
    for(set<string>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {cout << "  |-> " << (*it) << endl; }
    cout << "o Ingresar el nickname del cual quiera consultar su informacion: "; getline(cin,seleccionado); cout << endl;
    DataUsuario* datos = gestionUsuario->getDatosUsuario(seleccionado);

    if(datos->esEstudiante())
    {
        DataEstudiante* est = (DataEstudiante*) datos;
        cout << "Usted selecciono al estudiante con: " << endl;
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

    bool altaExitosa = gestionIdioma->altaIdioma(nombre);
    if (altaExitosa)
    {
        cout << "-> Se creo el idioma: " << nombre << endl;
    } else
    {
        cout << "-> Error: El idioma ya se encuentra creado en el sistema" << endl;
    }
}

// Para el Caso de Uso 4: [Consultar Idiomas]
void consultarIdiomas()
{
    set<string> idiomas = gestionIdioma->getIdiomas();
    cout << "Los idiomas creados en el sistema son: " << endl;
    for(set<string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        cout << "  |-> " << (*it) << endl;
    }
}

// Para el Caso de Uso 5: [Alta de Curso]
void altaCurso()
{
    set<string> nickProfesores = gestionCurso->getNicknamesProfesores();
    string nickProfesor;
    string idioma;
    courseInfo infoCurso;
    cout << "Profesores: " << endl;
    for(set<string>::iterator it = nickProfesores.begin(); it != nickProfesores.end(); ++it)
    {
        cout << "  -> " << (*it) << endl;
    }
    cout << "o Ingrese el nickname del profesor que dara de alta al curso: "; getline(cin,nickProfesor);
    cout << "  Se pasaran a pedir los datos necesarios para crear un nuevo curso." << endl;
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
    gestionCurso->ingresarDataCurso(nickProfesor, new DTCurso(infoCurso.nombre, infoCurso.desc, infoCurso.diff));
    set<string> idiomas = gestionCurso->getIdiomasProfesor();
    cout << "Se listaran los idiomas en los cuales se especializa el profesor: " << endl;
    for (set<string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        cout << "  |-> " << (*it) << endl;
    }
    cout << "o Seleccione el idioma del curso entre los listados: "; getline(cin, idioma);
    gestionCurso->agregarIdiomaCurso(idioma);
    cout << "Se pasara a listar los cursos habilitados, entre los cuales debe seleccionar aquellos que sean previas de el curso a crear: " << endl;
    set<string> cursosHab = gestionCurso->getNombreCursosHabilitados();
    for (set<string>::iterator it = cursosHab.begin(); it != cursosHab.end(); ++it)
    {
        cout << "  |-> " << (*it) << endl;
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
    gestionCurso->ingresarCursosPrevios(previos);
    cout << "Comenzaremos a ingresar las lecciones del curso:" << endl;
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
            gestionCurso->ingresarLeccionParaAlta(tema, objetivo);
            bool masEjercicios = true;
            string descEj;
            string auxEj;
            cout << "o Ingrese los ejercicios de la leccion: " << endl;
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
    gestionCurso->confirmarAltaCurso();
    cout << "-> Se creo el curso: " << infoCurso.nombre << endl;
}

// Para el Caso de Uso 6: [Agregar Leccion]
void agregarLeccion()
{
    set<InformacionCurso *> cursos = gestionCurso->getCursosNoHabilitados();
    if(!cursos.empty()){
        cout << "Cursos no habilitados: " << endl;
        for(set<InformacionCurso*>::iterator it = cursos.begin(); it != cursos.end(); it++){
            cout << "  |->" << ((*it)->getNombre()) << endl;
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
        bool masEjercicios = true;
        while(masEjercicios){
            string auxEj;
            cout << "o Desea agregar un Ejercicio? (1) SI, (2) NO: "; getline(cin, auxEj);
            if (auxEj == "1")
            { 
                string descEj;
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
        gestionCurso->altaLeccion();
    }

}

// Para el Caso de Uso 7: [Agregar Ejercicio]
void agregarEjercicio()
{
    set<InformacionCurso *> cursos = gestionCurso->getCursosNoHabilitados();
    if(!cursos.empty()){
        cout << "Cursos no habilitados: " << endl;
        for(set<InformacionCurso*>::iterator it = cursos.begin(); it != cursos.end(); it++){
            cout << "  |-> " << ((*it)->getNombre()) << endl;
        }
        string nombreCurso;
        cout << "o Ingrese el nombre del curso que desea agregar un ejercicio: ";
        getline(cin, nombreCurso);
        set<DataLeccion *> lecciones = gestionCurso->getLecciones(nombreCurso);
        if (lecciones.size() != 0)
        {
            cout << "Lecciones:" << endl;
            for(set<DataLeccion *>::iterator it = lecciones.begin(); it != lecciones.end(); ++it)
            {
                cout << "  |-> Leccion Numero:" << (*it)->getId() << " -> " << (*it)->getTema() << endl; //Las muestra sin orden
            }
            cout << "o Ingrese el Numero de la leccion a la cual desea agregar un ejercicio: " << endl;
            string IdStr;
            getline(cin,IdStr);
            int Id = stoi(IdStr);
            string descEj;
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
                gestionCurso->agregarEjercicio(Id, ejCP);
            } else if (tipoEj == "2")
            {
                string frase;
                string traduccion;
                cout << "o Ingrese la frase: "; getline(cin, frase);
                cout << "o Ingrese la frase traducida: "; getline(cin, traduccion);
                DataTraduccion* ejT = new DataTraduccion(descEj, 0, frase, traduccion);
                gestionCurso->agregarEjercicio(Id, ejT);
            }
        } else
        {
            cout << "-> Este curso no tiene lecciones" << endl;
        }
    } 
}

// Para el Caso de Uso 8: [Habilitar Curso]
void habilitarCurso()
{
    set<InformacionCurso*> cursos = gestionCurso->getCursosNoHabilitados();
    if (!cursos.empty())
    {
        cout << "Cursos no habilitados: " << endl;
        for(set<InformacionCurso*>::iterator it = cursos.begin(); it != cursos.end(); it++)
        {
            cout << "  |-> " << ((*it)->getNombre()) << endl;
        }
        string curso;
        cout << "o Ingrese el nombre del curso que desea habilitar: "; getline(cin, curso);
        bool habilitado = gestionCurso->habilitarCurso(curso);
        if(habilitado)
        {
            cout << "-> El curso fue habilitado correctamente" << endl;
        } else
        {
            cout << "-> El curso no puede ser habilitado" << endl;
        }
    } else
    {
        cout << "-> No hay cursos por habilitar" << endl; 
    }
}

// Para el Caso de Uso 9: [Eliminar Curso]
void eliminarCurso()
{
    cout << "Cursos creados: " << endl;
    set<string> cursos = gestionCurso->getNombreCursos();
    for(set<string>::iterator it = cursos.begin(); it != cursos.end(); it++){
        cout << "  |-> " << (*it) << endl;
    }
    cout << "---------o---------" << endl;
    cout << "o Ingrese el nombre del curso que desea eliminar" << endl;
    string nombreCurso;
    getline(cin,nombreCurso);
    gestionCurso->bajarCurso(nombreCurso);
    cout << "-> El curso de nombre " << nombreCurso << " fue eliminado";
}

// Para el Caso de Uso 10: [Consultar Curso]
void consultarCurso()
{
    set<string> aux = gestionCurso->darNombreCursos();
    if (!aux.empty())
    {
        cout << "Cursos disponibles: " << endl;
        for(set<string>::iterator it = aux.begin(); it != aux.end(); it++){
            cout << "  |-> " << (*it) << endl;
        }
        cout << "o Ingrese el nombre de un curso: " << endl;
        string seleccionado;
        getline(cin, seleccionado);
        cout << endl;
        DataConsultaCurso* res = gestionCurso->obtenerDataCursoSeleccionado(seleccionado);
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
        cout << "-> No hay cursos cargados." << endl;
    }
    
}

// Para el Caso de Uso 11: [Inscribirse a Curso]
void inscribirseCurso() //Hacer verificacion de que existe el curso
{
    cout << "o Ingrese su nickname" << endl;
    string nicknameUsuario;
    getline(cin, nicknameUsuario);
    set<InformacionCurso *> cursos = gestionUsuario->getCursosDisponibles(nicknameUsuario);
    cout << "-> Sus cursos disponibles son:" << endl;
    for(set<InformacionCurso *>::iterator it = cursos.begin(); it != cursos.end(); it++){
        cout << "-> " << (*it)->getNombre() << endl;
        cout << "-> Descripcion: " << (*it)->getDescripcion() << endl;
        cout << "-> Dificultad: " << (*it)->getDificultad() << endl;
        cout << "-> Cantidad de Lecciones: " << (*it)->getCantLecciones() << endl;
        cout << "-> Cantidad de Ejercicios: " << (*it)->getCantEjercicios() << endl;
    }
    cout << "---------o---------" << endl;
    cout << "o Ingrese el nombre del curso al que se quiere inscribir" << endl;
    string nombreCurso;
    getline(cin,nombreCurso);
    gestionUsuario->inscribirseACurso(nombreCurso);
    cout << "-> Inscripcion completada" << endl;
}

// Para el Caso de Uso 12: [Realizar Ejercicio]
void realizarEjercicio()
{
    string nombre;
    cout << "o Ingrese su nickname: "; getline(cin,nombre);
    cout << "-> Cursos no aprobados: " << endl;
    set<string> cursos = gestionUsuario->getCursosInscriptosNoAprobados(nombre);
    for(set<string>::iterator it = cursos.begin(); it != cursos.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
    cout << "o Escriba el nombre de un curso: ";
    string cursoSeleccionado;
    getline(cin,cursoSeleccionado);
    set<DataEjercicio *> ejercicios = gestionUsuario->getEjerciciosNoAprobados(cursoSeleccionado);
    cout << "-> ID de los ejercicios no aprobados: " << endl;
    for(set<DataEjercicio* >::iterator it = ejercicios.begin(); it != ejercicios.end(); it++){
        cout << "-> " << (*it)->getId() << endl;
    }
    cout << "o Escriba el ID de un ejercicio que quiera realizar: ";
    string aux;
    getline(cin, aux);
    int idEjercicio = stoi(aux);
    cout << "-> Letra: " << endl;
    cout << "-> " << gestionCurso->obtenerLetra(cursoSeleccionado,idEjercicio) << endl;
    DataEjercicio* eje = gestionCurso->encontrarEjercicio(cursoSeleccionado, idEjercicio);
    if(eje->esCompletarPalabras()){
        cout << "o Escriba sus soluciones, una por una, y termine con -1: " << endl;
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
        gestionUsuario->resolverEjercicioCP(idEjercicio, respuestaCP);
    }
    else{
        string respuestaT;
        cout << "o Escriba su solucion: "; getline(cin, respuestaT);
        gestionUsuario->resolverEjercicioT(idEjercicio, respuestaT);
    }
}

// Para el Caso de Uso 13: [Consultar Estadisticas]
void consultarEstadisticas()
{
    string opcion;
    cout << "o Desea consultar las estadisticas de un: (1) Estudiante | (2) Profesor | (3) Curso"; getline(cin,opcion);
    if(opcion == "1")
    {
        cout << "Los nicks de los estudiantes dentro del sistema son:" << endl;
        set<string> estudiantes = consEstadisticas->getNicksEstudiantes();
        for(set<string>::iterator it = estudiantes.begin(); it != estudiantes.end(); ++it)
        {
            cout << "|-> " << (*it) << endl;
        }
        string estudiante;
        cout << "o De cual estudiante desea observar sus estadisticas? "; getline(cin,estudiante);
        set<InfoCurso *> infoEst = listarCursosEstudiante(estudiante);
        cout << "El estudiante " << estudiante << "presenta las siguientes estadisticas: " << endl;
        for(set<InfoCurso *>::iterator it = infoEst.begin(); it != infoEst.end(); ++it)
        {
            cout << "El curso " << (*it)->getNombreCurso() << "con un porcentaje de avance del " << (*it)->getDato() << "%" << endl;
        }
    } else if (opcion == "2")
    {
        cout << "Los nicks de los profesores dentro del sistema son:" << endl;
        set<string> profesores = consEstadisticas->getNicksProfesores();
        for(set<string>::iterator it = profesores.begin(); it != profesores.end(); ++it)
        {
            cout << "|-> " << (*it) << endl;
        }
        string profesor;
        cout << "o De cual profesor desea observar sus estadisticas? "; getline(cin,profesor);
        set<InfoCurso *> infoProf = listarCursosPropuestos(profesor);
        cout << "El profesor " << profesor << "presenta las siguientes estadisticas: " << endl;
        for(set<InfoCurso *>::iterator it = infoProf.begin(); it != infoProf.end(); ++it)
        {
            cout << "El curso " << (*it)->getNombreCurso() << "con un promedio de avance del " << (*it)->getDato() << "%" << endl;
        }
    } else if (opcion == "3")
    {
        cout << "Los nombres de los cursos dentro del sistema son:" << endl;
        set<string> cursos = consEstadisticas->getNombresCursos();
        for(set<string>::iterator it = cursos.begin(); it != cursos.end(); ++it)
        {
            cout << "|-> " << (*it) << endl;
        }
        string curso;
        cout << "o De que curso desea observar sus estadisticas? ";getline(cin,curso);
        InformacionCurso* infoC = consEstadisticas->infoCurso(curso);
        cout << "El curso " << curso << "presenta las siguientes estadisticas:" << endl;
        cout << " |-> Descripcion: " << infoC->getDescripcion() << endl;
        cout << " |-> Dificultad: " << adaptarDificultad(infoC->getDificultad) << endl;
        cout << " |-> Cursos previos: " << endl;
        set<string> previos = infoC->getPrevios();
        for(set<string>::iterator it = previos.begin(); it != previos.end(); ++it)
        {
            cout << "      |-> " << (*it) << endl;
        }
        cout << " |-> Idioma: " << infoC->getIdioma() << endl;
        cout << " |-> Creado por: " << infoC->getProfesor() << endl;
        cout << " |-> Total lecciones: " << infoC->getCantLecciones() << endl;
        cout << " |-> Total ejercicios: " << infoC->getCantEjercicios() << endl;
        cout << " |-> Grado de avance: " << infoC->getPromedio() << "%" << endl;
    } else
    {
        cout << "-> Opcion invalida, por favor vuelva a intentarlo" << endl;
    }
}

// Para el Caso de Uso 14: [Suscribirse a Notificaciones]
void suscribirseNotificaciones()
{
    string nick;
    cout << "o Ingrese su nickname: "; getline(cin, nick);
    cout << "-> Idiomas no suscrito: " << endl;
    set<string> idiomas = gestionNotificaciones->idiomasNoSuscritos(nick);
    for(set<string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
    bool masIdiomas = true;
    cout << "o Escriba los idiomas a los cuales desea suscribirse, uno por uno, y termine con -1: " << endl;
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
    gestionUsuario->suscribirse(idiomasSeleccionados);
    cout << "-> Se ha suscrito correctamente a los siguientes idiomas: " << endl;
    for(set<string>::iterator it = idiomasSeleccionados.begin(); it != idiomasSeleccionados.end(); ++it)
    {
        cout << "-> " << (*it) << endl;
    }
}

// Para el Caso de Uso 15: [Consulta de Notificaciones]
void consultaNotificaciones()
{
    string nick;
    cout << "o Ingrese su nickname: "; getline(cin, nick);
    set<DataNotificacion *> notif = gestionNotificaciones->obtenerNotificaciones(nick);
    cout << "-> Aqui estan sus notificaciones: " << endl;
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
    string nick;
    cout << "o Ingrese su nickname: ";
    getline(cin, nick);
    cout << "-> Aqui estan sus suscripciones: " << endl;
    set<string> aux = gestionNotificaciones->idiomasSuscritos(nick);
    for(set<string>::iterator it = aux.begin(); it != aux.end(); it++){
        cout << "-> " << (*it) << endl;
    }
    string auxiliar;
    set<string> suscripcionesSeleccionada;
    cout << "o Escriba los nombres de las suscripciones a eliminar y termine con '-1': " << endl;
    bool masSuscripciones = true;
    while (masSuscripciones)
    {
        getline(cin,auxiliar);
        if (auxiliar != "-1")
        {
            suscripcionesSeleccionada.insert(auxiliar);
        } else
        {
            masSuscripciones = false;
        }
    }
    gestionNotificaciones->eliminarSuscripciones(suscripcionesSeleccionada);
}
