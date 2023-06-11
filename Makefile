# MakeFile permite definir constantes para los directorios. 
# Supongamos que un directorio es : DIR = dir/archivos, 
# en el codigo podes abreviarlo como $(DIR)
HDIR = include
HIDIR = include/InterfacesyControladores
HDTDIR = include/DataTypes
SDIR = src
SIDIR = src/InterfacesyControladores
SDTDIR = src/DataTypes
ODIR = obj

CC = g++
CCFLAGS = -std=c++11 -g

main: $(ODIR)/main.o $(ODIR)/CasosDeUso.o $(ODIR)/distribuidorInterfaces.o $(ODIR)/IGestionUsuario.o $(ODIR)/IGestionNotificaciones.o $(ODIR)/IGestionCurso.o $(ODIR)/IGestionIdiomas.o $(ODIR)/IConsultarEstadisticas.o $(ODIR)/Suscripcion.o $(ODIR)/ControladorUsuario.o $(ODIR)/ControladorCurso.o $(ODIR)/ControladorEstadisticas.o $(ODIR)/DataCompletarPalabras.o $(ODIR)/DataConsultaCurso.o $(ODIR)/DataCurso.o $(ODIR)/DataEjercicio.o $(ODIR)/DataEstudiante.o $(ODIR)/DataFecha.o $(ODIR)/DataInscripto.o $(ODIR)/DataLeccion.o $(ODIR)/DataNotificacion.o $(ODIR)/DataProfesor.o $(ODIR)/DataTraduccion.o $(ODIR)/DataUsuario.o $(ODIR)/DatosEjercicio.o $(ODIR)/DTCurso.o $(ODIR)/InfoCurso.o $(ODIR)/InformacionCurso.o $(ODIR)/InscripcionCurso.o $(ODIR)/Usuario.o $(ODIR)/Traduccion.o $(ODIR)/Profesor.o $(ODIR)/Notificacion.o $(ODIR)/Leccion.o $(ODIR)/Inscripcion.o $(ODIR)/Idioma.o $(ODIR)/Estudiante.o $(ODIR)/Ejercicio.o $(ODIR)/Curso.o $(ODIR)/CompletarPalabras.o
	$(CC) $(CCFLAGS) $^ -o $@
#./main

$(ODIR)/main.o: main.cpp CasosDeUso.cpp
	$(CC) $(CCFLAGS) main.cpp -o $@ CasosDeUso.cpp -o $(ODIR)/CasosDeUso.o
	
# Se define la Fabrica
$(ODIR)/distribuidorInterfaces.o: $(SIDIR)/distribuidorInterfaces.cpp $(HIDIR)/distribuidorInterfaces.hh
	$(CC) $(CCFLAGS) -c $< -o $@

# Definir todas las interfaces...
$(ODIR)/IGestionUsuario.o: $(SIDIR)/IGestionUsuario.cpp $(HIDIR)/IGestionUsuario.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/IGestionNotificaciones.o: $(SIDIR)/IGestionNotificaciones.cpp $(HIDIR)/IGestionNotificaciones.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/IGestionCurso.o: $(SIDIR)/IGestionCurso.cpp $(HIDIR)/IGestionCurso.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/IGestionIdiomas.o: $(SIDIR)/IGestionIdiomas.cpp $(HIDIR)/IGestionIdiomas.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/IConsultarEstadisticas.o: $(SIDIR)/IConsultarEstadisticas.cpp $(HIDIR)/IConsultarEstadisticas.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Suscripcion.o: $(SIDIR)/Suscripcion.cpp $(HIDIR)/Suscripcion.hh
	$(CC) $(CCFLAGS) -c $< -o $@
	
# Se definen los controladores...
$(ODIR)/ControladorUsuario.o: $(SIDIR)/ControladorUsuario.cpp $(HIDIR)/ControladorUsuario.hh $(SIDIR)/IGestionUsuario.cpp $(HIDIR)/IGestionUsuario.hh $(SIDIR)/IGestionNotificaciones.cpp $(HIDIR)/IGestionNotificaciones.hh
	$(CC) $(CCFLAGS) -c $< -o $@
	
$(ODIR)/ControladorCurso.o: $(SIDIR)/ControladorCurso.cpp $(HIDIR)/ControladorCurso.hh $(SIDIR)/IGestionCurso.cpp $(HIDIR)/IGestionCurso.hh $(SIDIR)/IGestionIdiomas.hh $(HIDIR)/IGestionIdiomas.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/ControladorEstadisticas.o: $(SIDIR)/ControladorEstadisticas.cpp $(HIDIR)/ControladorEstadisticas.hh $(SIDIR)/IConsultarEstadisticas.cpp $(HIDIR)/IConsultarEstadisticas.hh
	$(CC) $(CCFLAGS) -c $< -o $@

# Se definen los DataTypes
$(ODIR)/DataCompletarPalabras.o: $(SDTDIR)/DataCompletarPalabras.cpp $(HDTDIR)/DataCompletarPalabras.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataConsultaCurso.o: $(SDTDIR)/DataConsultaCurso.cpp $(HDTDIR)/DataConsultaCurso.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataCurso.o: $(SDTDIR)/DataConsultaCurso.cpp $(HDTDIR)/DataCompletarPalabras.hh
	$(CC) $(CCFLAGS) -c $< -o $@
	
$(ODIR)/DataEjercicio.o: $(SDTDIR)/DataEjercicio.cpp $(HDTDIR)/DataEjercicio.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataEstudiante.o: $(SDTDIR)/DataEstudiante.cpp $(HDTDIR)/DataEstudiante.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataFecha.o: $(SDTDIR)/DataFecha.cpp $(HDTDIR)/DataFecha.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataInscripto.o: $(SDTDIR)/DataInscripto.cpp $(HDTDIR)/DataInscripto.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataLeccion.o: $(SDTDIR)/DataLeccion.cpp $(HDTDIR)/DataLeccion.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataNotificacion.o: $(SDTDIR)/DataNotificacion.cpp $(HDTDIR)/DataNotificacion.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataProfesor.o: $(SDTDIR)/DataProfesor.cpp $(HDTDIR)/DataProfesor.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataTraduccion.o: $(SDTDIR)/DataTraduccion.cpp $(HDTDIR)/DataTraduccion.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DataUsuario.o: $(SDTDIR)/DataUsuario.cpp $(HDTDIR)/DataUsuario.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DatosEjercicio.o: $(SDTDIR)/DatosEjercicio.cpp $(HDTDIR)/DatosEjercicio.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/DTCurso.o: $(SDTDIR)/DTCurso.cpp $(HDTDIR)/DTCurso.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/InfoCurso.o: $(SDTDIR)/InfoCurso.cpp $(HDTDIR)/InfoCurso.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/InformacionCurso.o: $(SDTDIR)/InformacionCurso.cpp $(HDTDIR)/InformacionCurso.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/InscripcionCurso.o: $(SDTDIR)/InscripcionCurso.cpp $(HDTDIR)/InscripcionCurso.hh
	$(CC) $(CCFLAGS) -c $< -o $@

# Se definen los Conceptos del Modelo de Dominio
$(ODIR)/Usuario.o: $(SDIR)/Usuario.cpp $(HDIR)/Usuario.hh $(SIDIR)/Suscripcion.cpp $(HDIR)/Suscripcion.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Traduccion.o: $(SDIR)/Traduccion.cpp $(HDIR)/Traduccion.hh $(SDIR)/Ejercicio.cpp $(HDIR)/Ejercicio.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Profesor.o: $(SDIR)/Profesor.cpp $(HDIR)/Profesor.hh $(SDIR)/Usuario.cpp $(HDIR)/Usuario.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Notificacion.o: $(SDIR)/Notificacion.cpp $(HDIR)/Notificacion.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Leccion.o: $(SDIR)/Leccion.cpp $(HDIR)/Leccion.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Inscripcion.o: $(SDIR)/Inscripcion.cpp $(HDIR)/Inscripcion.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Idioma.o: $(SDIR)/Idioma.cpp $(HDIR)/Idioma.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Estudiante.o: $(SDIR)/Estudiante.cpp $(HDIR)/Estudiante.hh $(SDIR)/Usuario.cpp $(HDIR)/Usuario.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Ejercicio.o: $(SDIR)/Ejercicio.cpp $(HDIR)/Ejercicio.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/Curso.o: $(SDIR)/Curso.cpp $(HDIR)/Curso.hh
	$(CC) $(CCFLAGS) -c $< -o $@

$(ODIR)/CompletarPalabras.o: $(SDIR)/CompletarPalabras.cpp $(HDIR)/CompletarPalabras.hh $(SDIR)/Ejercicio.cpp $(HDIR)/Ejercicio.hh
	$(CC) $(CCFLAGS) -c $< -o $@
	
# Funciones extra
clean:
	rm $(ODIR)/*.o main


#Repasando
#target: dependencies (Quiero volver a compilar esto cuando "dependencies" cambien)
#	action

# Sintaxis de MakeFile :
#$@ : Agarra el nombre de 'target'
#$< : Agarra el primer nombre de 'dependencies'
#$^ : Agarra todos los nombres de 'dependencies'