// Includes
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

// Directorios
string DIdiomas = "CSVs/Idiomas.csv";
string DUsuarios = "CSVs/Usuarios.csv";
string DEstudiantes = "CSVs/Usuarios-Estudiantes.csv";
string DProfesores = "CSVs/Usuarios-Profesores.csv";
string DCursos = "CSVs/Cursos.csv";
string DCursosPrevios = "CSVs/Cursos-Previos.csv";
string DCursosLecciones = "CSVs/Cursos-Lecciones.csv";
string DCursosLeccionesEjercicios = "CSVs/Cursos-Lecciones-Ejercicios.csv";
string DInscripciones = "CSVs/Inscripciones.csv";
string DInscripcionesEjerciciosArpobados = "CSVs/Inscripciones-EjerciciosAprobados.csv";


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
    vector<string> idiomasP;
};

map<string,cargaUsuario> users;
map<string,string> idiomas;

int main()
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
                    cout << palabra << endl;
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
                            p.idiomasP.push_back(it->second);
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
}