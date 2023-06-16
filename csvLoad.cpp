/* ---------------------------------------------- Includes ---------------------------------------------- */
#include "include/Utils.hh"

#include"include/InterfacesyControladores/distribuidorInterfaces.hh"

using namespace std;
/* ------------------------------------------------------------------------------------------------------ */

// Obtengo la Fabrica junto a sus interfaces...
distribuidorInterfaces* Fab = new distribuidorInterfaces();

IGestionUsuario* gUsuario = Fab->getIGestionUsuario();
IGestionNotificaciones* gNotificaciones = Fab->getIGestionNotificaciones();
IGestionCurso* gCurso = Fab->getIGestionCurso();
IGestionIdiomas* gIdiomas = Fab->getIGestionIdiomas();
IConsultarEstadisticas* cEstadisticas = Fab->getIConsultarEstadisticas();

/* --------------------------------------------- Directorios --------------------------------------------- */
string DIdiomas = "cargaDatos/CSVs/Idiomas.csv";
string DUsuarios = "cargaDatos/CSVs/Usuarios.csv";
string DEstudiantes = "cargaDatos/CSVs/Usuarios-Estudiantes.csv";
string DProfesores = "cargaDatos/CSVs/Usuarios-Profesores.csv";
string DCursos = "cargaDatos/CSVs/Cursos.csv";
string DCursosPrevios = "cargaDatos/CSVs/Cursos-Previos.csv";
string DCursosLecciones = "cargaDatos/CSVs/Cursos-Lecciones.csv";
string DCursosLeccionesEjercicios = "cargaDatos/CSVs/Cursos-Lecciones-Ejercicios.csv";
string DInscripciones = "cargaDatos/CSVs/Inscripciones.csv";
string DInscripcionesEjerciciosArpobados = "cargaDatos/CSVs/Inscripciones-EjerciciosAprobados.csv";
/* ------------------------------------------------------------------------------------------------------ */


string misArchivos[] = {DIdiomas, DUsuarios, DEstudiantes, DProfesores, DCursos, DCursosPrevios, DCursosLecciones, DCursosLeccionesEjercicios, DInscripciones, DInscripcionesEjerciciosArpobados};
vector<string> archivos (misArchivos, misArchivos + sizeof(misArchivos) / sizeof(string));

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

map<string,cargaUsuario> users;
map<string,string> idiomas;

void crearDatos()
{
    // Se crean los Idiomas...
    for(map<string,string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
    {
        gIdiomas->altaIdioma(it->second);
    }

    // Se crean los usuarios...
    for(map<string,cargaUsuario>::iterator it = users.begin(); it != users.end(); ++it)
    {
        cargaUsuario u = it->second;
        if(u.tipo == "E")
        {
            DataFecha* f = new DataFecha(stoi(u.dia),stoi(u.mes),stoi(u.anio));
            DataEstudiante* est = new DataEstudiante(u.nick,u.name,u.pass,u.desc,u.pResidencia,f);
            gUsuario->ingresarUsuario(est);
            gUsuario->confirmarAltaUsuario();
        } else if (u.tipo == "P")
        {
            DataProfesor* prof = new DataProfesor(u.nick,u.name,u.pass,u.desc,u.ins);
            gUsuario->ingresarUsuario(prof);
            gUsuario->ingresarIdiomas(u.idiomasP);
            gUsuario->confirmarAltaUsuario();
        }else
        {
            cout << "Error: Usuario no es ni Estudiante ni Profesor" << endl;
        }
    }
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

                    users[u.ref] = u;
                }
            } else if (archivo == DEstudiantes)
            {
                while(getline(file,linea))
                {
                    stringstream str(linea);
                    // Obtengo la referencia...
                    getline(str,palabra,';');
                    cargaUsuario e = users[palabra];
                    // Obtengo la fecha
                    // Dia
                    getline(str,palabra,'/');
                    e.dia = palabra;
                    // Mes
                    getline(str,palabra,'/');
                    e.mes = palabra;
                    // Anio
                    getline(str,palabra,';');
                    e.anio = palabra;
                    // Pais residencia
                    getline(str,palabra,';');
                    e.pResidencia = palabra;
                }
            } else if (archivo == DProfesores)
            {
                while(getline(file, linea))
                {
                    stringstream str(linea);
                    // Obtengo la referencia...
                    getline(str,palabra,';');
                    cargaUsuario p = users[palabra];
                    // Obtengo el Instituto...
                    getline(str,palabra,';');
                    p.ins = palabra;
                    // Obtengo Idiomas...
                    for (map<string, string>::iterator it = idiomas.begin(); it != idiomas.end(); ++it)
                    {
                        getline(str, palabra, ';');
                        if (palabra == "Si" || palabra == " Si")
                        {
                            p.idiomasP.insert(it->second);
                        }
                    }
                } // vector<string> idiomas; " Si" || "Si"
            } else if (archivo == DCursos)
            {
                
            }
        } else
        {
            cout << "Error al abrir el archivo: " << archivo << endl;
        }
    }
    crearDatos();
}