/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "include/Utils.hh"

#include"include/InterfacesyControladores/distribuidorInterfaces.hh"
/* ------------------------------------------------------------------------------------------------------ */

// Obtengo la Fabrica junto a sus interfaces...
distribuidorInterfaces* Fab = new distribuidorInterfaces();

IGestionUsuario* gUsuario = Fab->getIGestionUsuario();
IGestionNotificaciones* gNotificaciones = Fab->getIGestionNotificaciones();
IGestionCurso* gCurso = Fab->getIGestionCurso();
IGestionIdiomas* gIdiomas = Fab->getIGestionIdiomas();

/* --------------------------------------------- Directorios --------------------------------------------- */
string DIdiomas = "cargaDatos/Idiomas.csv";
string DUsuarios = "cargaDatos/Usuarios.csv";
string DEstudiantes = "cargaDatos/Usuarios-Estudiantes.csv";
string DProfesores = "cargaDatos/Usuarios-Profesores.csv";
string DCursos = "cargaDatos/Cursos.csv";
string DCursosPrevios = "cargaDatos/Cursos-Previos.csv";
string DCursosLecciones = "cargaDatos/Cursos-Lecciones.csv";
string DCursosLeccionesEjercicios = "cargaDatos/Cursos-Lecciones-Ejercicios.csv";
string DInscripciones = "cargaDatos/Inscripciones.csv";
string DInscripcionesEjerciciosArpobados = "cargaDatos/Inscripciones-EjerciciosAprobados.csv";
/* ------------------------------------------------------------------------------------------------------ */

string misArchivos[] = {DIdiomas, DUsuarios, DEstudiantes, DProfesores, DCursos, DCursosPrevios, DCursosLecciones, DCursosLeccionesEjercicios, DInscripciones, DInscripcionesEjerciciosArpobados};
vector<string> archivos (misArchivos, misArchivos + sizeof(misArchivos) / sizeof(string));

/* --------------------------------------------- Structs Usados Para La Carga --------------------------------------------- */
// Structs usados para la carga...
struct cargaUsuario
{
    // Declaro las variables necesarias para crear un Usuario
    string ref;
    string tipo;

    string nick;
    string pass;
    string name;
    string desc;
    // Estudiante
    string pResidencia;
    string dia,mes,anio;
    // Profesor
    string ins;
    set<string> idiomasP;
};

struct cargaEjercicio
{
    string ref;
    string leccionRef;
    string tipo;

    string desc;
    string problema;
    string sol;
};

struct cargaLeccion
{
    string ref;
    list<string> ejerciciosRef;

    string tema;
    string objetivo;
};



struct cargaCurso
{
    string ref;
    string profRef;
    string idiRef;
    list<string> previosRef;
    list<string> leccionesRef;

    string name;
    string desc;
    difficulty diff;
    bool habilitado;

};

struct cargaInscripcion
{
    string ref;
    string estRef;
    string curRef;
    list<string> ejerciciosRef;

    int dia,mes,anio;
};

map<string,string> idiomas; // La clave es la referencia del idioma
map<string,cargaUsuario> usuarios; // La clave es la referencia del usuario
map<string,cargaCurso> cursos; // La clave es la referencia del curso
map<string,cargaLeccion> lecciones; // La clave es la referencia de la leccion
map<string,cargaEjercicio> ejercicios; // La clave es la referencia del ejercicio
map<string,cargaInscripcion> inscripciones; // La clave es la referencia de la inscripcion
/* ------------------------------------------------------------------------------------------------------------------------ */

void mostrarConjuntosCreados()
{
    cout << "-> Total de idiomas cargados: " << idiomas.size() << endl;
    cout << "-> Total de usuarios cargados: " << usuarios.size() << endl;
    for(map<string,cargaUsuario>::iterator it = usuarios.begin(); it != usuarios.end(); ++it)
    {
        if (it->second.tipo == "P")
        {
            cout << "-> El profesor de referencia " << it->first << " tiene un total de " << it->second.idiomasP.size() << " idiomas." << endl;
        }
    }
    cout << "-> Total de cursos cargados: " << cursos.size() << endl;
    for(map<string,cargaCurso>::iterator it = cursos.begin(); it != cursos.end(); ++it)
    {
        cout << "-> El curso de referencia " << it->first << " tiene un total de " << it->second.leccionesRef.size() << " lecciones." << endl;
    }

    cout << "-> Total de lecciones cargadas: " << lecciones.size() << endl;
    for(map<string,cargaLeccion>::iterator it = lecciones.begin(); it != lecciones.end(); ++it)
    {
        cout << "-> La leccion de referencia " << it->first << " tiene un total de " << it->second.ejerciciosRef.size() << " ejercicios." << endl;
    }

    cout << "Total de ejercicios cargados: " << ejercicios.size() << endl;

    cout << "Total de inscripciones cargadas: " << inscripciones.size() << endl;
}

void crearDatos()
{
    // Se crean los Idiomas...
    for(map<string,string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        gIdiomas->altaIdioma(it->second);
    }
    cout << "-> Se cargaron correctamente los idiomas." << endl;
    cout << "    |-> Total de idiomas cargados: " << idiomas.size() << endl;

    // Se crean los Usuarios...
    for(map<string,cargaUsuario>::iterator it = usuarios.begin(); it != usuarios.end(); ++it)
    {
        cargaUsuario u = it->second;
        if(u.tipo == "E")
        {
            DataFecha* f = new DataFecha(stoi(u.dia),stoi(u.mes),stoi(u.anio));
            DataEstudiante* est = new DataEstudiante(u.nick,u.name,u.pass,u.desc,u.pResidencia,f);
            gUsuario->ingresarUsuario(est);
            gUsuario->confirmarAltaUsuario();
            delete est;
        } else if (u.tipo == "P")
        {
            DataProfesor* prof = new DataProfesor(u.nick,u.name,u.pass,u.desc,u.ins);
            gUsuario->ingresarUsuario(prof);
            gUsuario->ingresarIdiomas(u.idiomasP);
            gUsuario->confirmarAltaUsuario();
            delete prof;
        }else
        {
            cout << "Error: Usuario no es ni Estudiante ni Profesor" << endl;
        }
    }
    cout << "-> Se cargaron correctamente los usuarios." << endl;
    cout << "    |-> Total de usuarios cargados: " << usuarios.size() << endl;

    // Se crean los Cursos...
    for(map<string,cargaCurso>::iterator it = cursos.begin(); it != cursos.end(); ++it)
    {
        cargaCurso cur = it->second;
        DTCurso* datosCurso = new DTCurso(cur.name,cur.desc,cur.diff);
        gCurso->ingresarDataCurso(usuarios[cur.profRef].nick,datosCurso);
        gCurso->agregarIdiomaCurso(idiomas[cur.idiRef]);

        // Agrego los cursos previos...
        set<string> cursosPrevios;
        for(list<string>::iterator it2 = cur.previosRef.begin(); it2 != cur.previosRef.end(); ++it2)
        {
            cursosPrevios.insert(cursos[(*it2)].name);
        }
        gCurso->ingresarCursosPrevios(cursosPrevios);

        // Agrego las lecciones y sus ejercicios...
        for(list<string>::iterator it3 = cur.leccionesRef.begin(); it3 != cur.leccionesRef.end(); ++ it3)
        {
            cargaLeccion lec = lecciones[(*it3)];
            gCurso->ingresarLeccionParaAlta(lec.tema,lec.objetivo);

            // Ingreso sus ejercicios...
            for(list<string>::iterator it31 = lec.ejerciciosRef.begin(); it31 != lec.ejerciciosRef.end(); ++it31)
            {
                cargaEjercicio ejer = ejercicios[(*it31)];
                if(ejer.tipo == "T")
                {
                    DataTraduccion* dtTrad = new DataTraduccion(ejer.desc,0,ejer.problema,ejer.sol);
                    gCurso->ingresarEjercicioParaAlta(dtTrad);
                } else
                {
                    // Adapto la solucion al formato necesario...
                    set<string> solucion;
                    stringstream str(ejer.sol);
                    string palabra;
                    while(getline(str,palabra,','))
                    {
                        solucion.insert(palabra);
                    } 

                    // Creo el ejercicio...
                    DataCompletarPalabras* dtCP = new DataCompletarPalabras(ejer.desc,0,ejer.problema,solucion);
                    gCurso->ingresarEjercicioParaAlta(dtCP);
                }
            }
            // Creo la leccion...
            gCurso->confirmarLeccion();
        }
        gCurso->confirmarAltaCurso();
        delete datosCurso;
        // Tengo que verificar si el curso esta habilitado...
        if(cur.habilitado)
        {
            gCurso->habilitarCurso(cur.name);
        }
    }
    cout << "-> Se cargaron correctamente los cursos." << endl;
    cout << "    |-> Total de cursos cargados: " << cursos.size() << endl;

    // Se registran las inscripciones...
    for(map<string,cargaInscripcion>::iterator it = inscripciones.begin(); it != inscripciones.end(); ++it)
    {
        // Registramos la inscripcion...
        cargaInscripcion insc = it->second;
        set<InformacionCurso *> inecesario = gUsuario->getCursosDisponibles(usuarios[insc.estRef].nick);
        gUsuario->inscribirseACurso(cursos[insc.curRef].name);

        // Apruebo los ejercicios correspondientes...
        for(list<string>::iterator it2 = insc.ejerciciosRef.begin(); it2 != insc.ejerciciosRef.end(); ++it2)
        {
            cargaEjercicio ej = ejercicios[(*it2)];
            set<string> inecesario2 = gUsuario->getCursosInscriptosNoAprobados(usuarios[insc.estRef].nick);
            set<DataEjercicio *> inecesario3 = gUsuario->getEjerciciosNoAprobados(cursos[insc.curRef].name);
            // Encuentro el ejercicio dentro del sistema...
            DataEjercicio* dataEj;
            for(set<DataEjercicio*>::iterator it3 = inecesario3.begin(); it3 != inecesario3.end();++it3)
            {
                DataEjercicio* dato = *it3;
                if(dato->getDescripcion() == ej.desc){ dataEj = dato; }
            }
            if (ej.tipo == "T")
            {
                DataTraduccion* dtT = (DataTraduccion*) dataEj;
                gUsuario->resolverEjercicioT(dtT->getId(),dtT->getTraduccion());
                delete dtT;
            } else
            {
                DataCompletarPalabras* dtCP = (DataCompletarPalabras*) dataEj;
                gUsuario->resolverEjercicioCP(dtCP->getId(),dtCP->getSolucion());
                delete dtCP;
            }
        }
    }
    cout << "-> Se cargaron correctamente las inscripciones." << endl;
    cout << "   |-> Total de inscripciones cargadas: " << inscripciones.size() << endl;
    cout << "---> Se cargaron correctamente los datos publicados en el EVA." << endl;
}

void liberarMemoriaFabrica()
{
    delete Fab;
    delete gUsuario;
    delete gCurso;
}

void csvLoad()
{
    for(vector<string>::iterator it = archivos.begin(); it != archivos.end();++it)
    {
        string archivo = (*it);
        fstream file (archivo,ios::in);

        if(file.is_open())
        {
            string linea,palabra;
            getline(file,linea); // Este es el cabezal...
            if (archivo == DIdiomas)
            {
                while(getline(file,linea))
                {
                    stringstream str(linea);
                    getline(str,palabra,';');
                    string clave = palabra;
                    getline(str,palabra,';');
                    idiomas[clave] = palabra;
                }
            } else if(archivo == DUsuarios)
            {
                cargaUsuario u;
                while(getline(file,linea))
                {
                    stringstream str(linea);
                    // Guardo la referencia...
                    getline(str,palabra,';');
                    u.ref = palabra;
                    // Guardo el tipo...
                    getline(str,palabra,';');
                    u.tipo = palabra;
                    // Guardo el nickname...
                    getline(str,palabra,';');
                    u.nick = palabra;
                    // Guardo la contrasenia...
                    getline(str,palabra,';');
                    u.pass = palabra;
                    // Guardo el nombre...
                    getline(str,palabra,';');
                    u.name = palabra;
                    // Guardo la descripcion...
                    getline(str,palabra,';');
                    u.desc = palabra;

                    usuarios[u.ref] = u;
                }
            } else if (archivo == DEstudiantes)
            {
                while(getline(file,linea))
                {
                    string estRef;
                    stringstream str(linea);
                    // Obtengo la referencia...
                    getline(str,estRef,';');
                    // Obtengo la fecha
                    // Dia
                    getline(str,palabra,'/');
                    usuarios[estRef].dia = palabra;
                    // Mes
                    getline(str,palabra,'/');
                    usuarios[estRef].mes = palabra;
                    // Anio
                    getline(str,palabra,';');
                    usuarios[estRef].anio = palabra;
                    // Pais residencia
                    getline(str,palabra,';');
                    usuarios[estRef].pResidencia = palabra;
                }
            } else if (archivo == DProfesores)
            {
                while(getline(file, linea))
                {
                    string profRef;
                    stringstream str(linea);
                    // Obtengo la referencia...
                    getline(str,profRef,';');
                    // Obtengo el Instituto...
                    getline(str,palabra,';');
                    usuarios[profRef].ins = palabra;
                    // Obtengo Idiomas...
                    for (map<string, string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
                    {
                        getline(str, palabra, ';');
                        if (palabra == "Si" || palabra == " Si")
                        {
                            usuarios[profRef].idiomasP.insert(it->second);
                        }
                    }
                }
            } else if (archivo == DCursos)
            {
                cargaCurso c;
                while(getline(file,linea))
                {
                    stringstream str(linea);
                    // Guardo la referencia...
                    getline(str,palabra,';');
                    c.ref = palabra;
                    // Guardo el nombre...
                    getline(str,palabra,';');
                    c.name = palabra;
                    // Guardo la descripcion...
                    getline(str,palabra,';');
                    c.desc = palabra;
                    // Guardo la Dificultad...
                    getline(str,palabra,';');
                    if (palabra == "Principiante")
                    {
                        c.diff = Principiante;
                    } else if (palabra == "Medio")
                    {
                        c.diff = Intermedio;
                    } else if (palabra == "Avanzado")
                    {
                        c.diff = Avanzado;
                    }
                    // Guardo la referencia al profesor...
                    getline(str,palabra,';');
                    c.profRef = palabra;
                    // Guardo la referencia al idioma...
                    getline(str,palabra,';');
                    c.idiRef = palabra;
                    // Me fijo si esta habilitado...
                    getline(str,palabra,';');
                    if (palabra == "Si")
                    {
                        c.habilitado = true;
                    } else if (palabra == "No")
                    {
                        c.habilitado = false;
                    }
                    cursos[c.ref] = c;
                }
            } else if (archivo == DCursosPrevios)
            {
                while(getline(file,linea))
                {
                    stringstream str(linea);
                    string origen,previa;
                    // Obtengo la referencia al origen...
                    getline(str,palabra,';');
                    origen = palabra;
                    // Obtengo la referencia a la previa...
                    getline(str,palabra,';');
                    previa = palabra;

                    // Agrego la referencia del previo al curso correspondiente
                    cursos[origen].previosRef.push_back(previa);
                }
            } else if (archivo == DCursosLecciones )
            {
                cargaLeccion lec;
                while(getline(file,linea))
                {
                    stringstream str(linea);
                    string cursoPerteneciente;
                    // Obtengo la referencia...
                    getline(str,palabra,';');
                    lec.ref = palabra;
                    // Obtengo la referencia del curso al que pertenece...
                    getline(str,palabra,';');
                    cursoPerteneciente = palabra;
                    // Obtengo el tema...
                    getline(str,palabra,';');
                    lec.tema = palabra;
                    // Obtengo el objetivo...
                    getline(str,palabra,';');
                    lec.objetivo = palabra;

                    // Registro en el curso la referencia a esta leccion...
                    cursos[cursoPerteneciente].leccionesRef.push_back(lec.ref);
                    lecciones[lec.ref] = lec;
                }
            } else if (archivo == DCursosLeccionesEjercicios)
            {
                cargaEjercicio ej;
                while(getline(file,linea))
                {
                    stringstream str(linea);

                    // Obtengo la referencia...
                    getline(str,palabra,';');
                    ej.ref = palabra;
                    // Obtengo la leccion a la que pertenece...
                    getline(str,palabra,';');
                    ej.leccionRef = palabra;
                    // Obtengo el tipo...
                    getline(str,palabra,';');
                    ej.tipo = palabra;
                    // Obtengo la Descripcion...
                    getline(str,palabra,';');
                    ej.desc = palabra;
                    // Obtengo el problema...
                    getline(str,palabra,';');
                    ej.problema = palabra;
                    // Obtengo la solucion...
                    getline(str,palabra,';');
                    ej.sol = palabra;

                    // Registro en la leccion la referencia a este ejercicio...
                    lecciones[ej.leccionRef].ejerciciosRef.push_back(ej.ref);
                    ejercicios[ej.ref] = ej;
            }
            } else if (archivo == DInscripciones)
            {
                cargaInscripcion ins;
                while(getline(file,linea))
                {
                    stringstream str(linea);

                    // Obtengo la referencia...
                    getline(str,palabra,';');
                    ins.ref = palabra;
                    // Obtengo la referencia al estudiante...
                    getline(str,palabra,';');
                    ins.estRef = palabra;
                    // Obtengo la referencia al curso...
                    getline(str,palabra,';');
                    ins.curRef = palabra;
                    // Obtengo el dia...
                    getline(str,palabra,'/');
                    int dia = stoi(palabra);
                    ins.dia = dia;
                    // Obtengo el mes...
                    getline(str,palabra,'/');
                    int mes = stoi(palabra);
                    ins.mes = mes;
                    // Obtengo el anio...
                    getline(str,palabra,';');
                    int anio = stoi(palabra);
                    ins.anio = anio;

                    inscripciones[ins.ref] = ins;
                                      
                }
            } else if (archivo == DInscripcionesEjerciciosArpobados)
            {
                while(getline(file,linea))
                {
                    stringstream str(linea);
                    string inscripcionRef,ejercicioRef;

                    // Obtengo la referencia de la inscripcion...
                    getline(str,palabra,';');
                    inscripcionRef = palabra;
                    // Obtengo la referencia del ejercicio...
                    getline(str,palabra,';');
                    ejercicioRef = palabra;

                    // Registro la aprobacion en la inscripcion...
                    inscripciones[inscripcionRef].ejerciciosRef.push_back(ejercicioRef);
                }
            }
        } else
        {
            cout << "Error al abrir el archivo: " << archivo << endl;
        }
    }
    //mostrarConjuntosCreados();
    crearDatos();
    //liberarMemoriaFabrica();
}