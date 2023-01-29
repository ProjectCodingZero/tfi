#ifndef register_h
#define register_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wctype.h>
#include <ctype.h>
#include <time.h>
#include "verificar.h"
#include "library.h"


#define color(c); system("COLOR " #c);
#define pause(); system("PAUSE"); system("CLS");

//Funcion para poder ingresar un numero ya sea int o float
#define IngresarNumero(TipoDato, Dato, Quien); \
system("CLS"); printf("Ingresar %s del nuevo %s\n",TipoDato , Quien); \
if(sizeof(Dato) == sizeof(int)){ \
	scanf("%i", &Dato); \
} \
else{ \
	scanf("%f", &Dato);\
}
//Funcion para poder ingresar un dato string
#define IngresarChar(TipoDato, Texto, Quien); \
system("CLS"); printf("Ingresar %s del nuevo %s\n",TipoDato , Quien); \
_flushall(); gets(Texto); _flushall();


//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02
bool registerUser(FILE *Archivo)
{
	char Intento;
	color(30);
	system("CLS");
	printf("Bienvenido a la creacion de usuario\n");
	system("PAUSE");
	struct Usuario NewUser;

	while(true)
	{

		printf("El usuario debe ser:\n");
		printf("* Ser unico para cada usuario registrado.\n");
		printf("* Comenzar con una letra minuscula.\n");
		printf("* Tener al menos 2 letras mayusculas.\n");
		printf("* Tener como maximo 3 digitos.\n");
		printf("Ingresar el nuevo usuario: ");
		_flushall();
		gets(NewUser.usuario);
		_flushall();
		printf("A continuacion se comprobora si el usuario cumple con los requisitos:\n");
		
		
		if(VerificadorUserUser(NewUser.usuario, Archivo))
		{
			//Si el usuario el aceptado saldra del while
			break;
		}
		else{
			printf("Quiere volver a intentar? (S)i o (N)o");
			scanf("%c", &Intento);
			if(toupper(Intento) != 'S')
			{
				pause();
				return false; //Para salir de la funcion
				
			}
			else
			{
				printf("Vuelva a ingresar un usuario: ");
				pause();
			}
		}
	}

	
	while(true)
	{
		printf("* Debera contener al menos una letra mayuscula, una letra minuscula y un numero.\n");
		printf("* Solo caracteres alfanumericos.\n");
		printf("* Debera tener entre 6 y 32 caracteres.\n");
		printf("* No debe tener mas de 3 caracteres numericos consecutivos.\n");
		printf("* No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas\n");
		printf("Ingrese la contrasena del nuevo usuario: ");
		_flushall();
		gets(NewUser.contrasena);
		_flushall();
		printf("A continuacion se comprobora si la contrasena cumple con los requisitos:\n");
		
		
		if(VerificadorPass(NewUser.contrasena))
		{
			//Si la contrasena es aceptada saldra del while
			break;
		}
		else
		{
			printf("Quiere volver a intentar? (S)i o (N)o");
			scanf("%c", &Intento);
			if(toupper(Intento) == 'S')
			{
				printf("Vuelva a ingresar una contrasena\n");
				pause();
			}
			else if(toupper(Intento) == 'N')
			{
				printf("Saliendo...\n");
				pause();
				return false; //Para salir de la funcion
			}
			else
			{
				color(46);
				printf("Error: Opcion ingresada no existe\n");
				printf("Opcion: \"%c\"\n", Intento);
				pause();
				color(30);
			}
		}
	}
	
	char nombre[60];
	IngresarChar("nombre y apellido", NewUser.ApelYNom, "usuario");

	//Se escribira el archivo enviada como parametro
	fwrite(&NewUser, sizeof(NewUser), 1, Archivo);
}


//Para crear un entrenador
bool RegistrarEntrenador()
{
	srand(time(NULL));
	system("CLS");
	color(30);
	struct Entrenador NewEntrenador;
	printf("Ingresar el nombre del nuevo entrenador\n");
	IngresarChar("Nombre Completo", NewEntrenador.ApelYNom, "entrenador");
	int Dia;
	
	//Todos los dias se ponen en cero para que el listado de entrenadores
	for(Dia = 0; Dia < 7; Dia++)
		NewEntrenador.Dias[Dia] = 0;
	
	Dia = 1;
	while(Dia != 0)
	{
		printf("Ingresar el dia donde el entrenador trabajo\n");
		printf("Lunes = 1\nMartes = 2\nMiercoles = 3");
		printf("Jueves = 4\nViernes = 5\nSabado = 6\nDomingo = 7\n");
		printf("Salir = 0\n\n");
		scanf("%i", &Dia);
		if(Dia >= 0 && Dia <= 7)
		{
			NewEntrenador.Dias[Dia-1] = Dia;
			printf("Se registro correctamente el dia\n");
			pause();
		}
		else if(Dia == 0)
			break;
		else
		{
			color(46);
			printf("Error: Opcion ingresada no existe\n");
			printf("Opcion: %i\n", Dia);
			pause();
			color(30);
		}
	}
	//Calcular las horas del entrenador
	system("CLS");
	int NroSocio;
	
	FILE *EntrenadoresArch = fopen("./Entrenadores.dat", "rb");
	
	if(EntrenadoresArch == NULL)
	{
		//Se comprueba que el archivo exista
		//Si no existe lo crea
		fclose(EntrenadoresArch);
		EntrenadoresArch = fopen("./Entrenadores.dat", "wb");
		fclose(EntrenadoresArch);
		NewEntrenador.Legajo = rand() % 2147483647;
	}
	else
	{
		//Si existe se verifica que el legajo no sea repetido
		bool Verificiar = false;
		struct Entrenador OldEntrenador;
		//Se hace un ciclo para ingresar un numero de socio no repetido
		while(!Verificiar){
			NewEntrenador.Legajo = rand() % 2147483647;
		
			fread(&OldEntrenador, sizeof(OldEntrenador), 1, EntrenadoresArch);
			while(!feof(EntrenadoresArch)){
				if(OldEntrenador.Legajo != NewEntrenador.Legajo)
					Verificiar = true;
				else
					Verificiar = false;
				fread(&OldEntrenador, sizeof(OldEntrenador), 1, EntrenadoresArch);
			}
		}
	}
	
	printf("El legajo del nuevo entrenador es \"%i\"", NewEntrenador.Legajo);
	pause();
	NewEntrenador.cargaHoraria = 0;
	system("CLS");
	EntrenadoresArch = fopen("./Entrenadores.dat", "ab");
	fwrite(&NewEntrenador, sizeof(NewEntrenador), 1, EntrenadoresArch);
	fclose(EntrenadoresArch);
	printf("El nuevo entrenador fue registrado con exito\n");
	pause();
	return true;
}


//Para crear un socio
void CreationSocio()
{	
	system("CLS");
	struct Socio NewSocio; 
	color(30);
	printf("Bienvenido a la creacion de socio\n");
	pause();
	
	//Se ingresa el nombre y apellido
	IngresarChar("Nombre", NewSocio.ApelYNom, "socio");
	//Se ingresa el celular
	IngresarNumero("Celular", NewSocio.Celular, "socio");
	//Se ingresa el dni
	IngresarNumero("DNI", NewSocio.DNI, "socio");
	//Se ingresa las indicaciones medicas
	int i, rta = 15;
	IngresarChar("Indicaciones Medicas", NewSocio.IndMedicas, "socio");
	//Se ingresa la altura
	IngresarNumero("Altura", NewSocio.Altura, "socio");
	//Se ingresa el peso
	IngresarNumero("Peso", NewSocio.Altura, "socio");
	srand(time(NULL));
	FILE *SociosArch = fopen("./Socios.dat", "rb");
	
	// Se abre el archivo para comprobar que el numero de socio no es repetido
	if(SociosArch == NULL){
		NewSocio.NroSocio = rand() % 2147483647;
		fclose(SociosArch);
	}
	else
	{
		bool Verificiar = false;
		struct Socio OldSocio;
		//Se hace un ciclo para ingresar un numero de socio no repetido
		while(!Verificiar){
			NewSocio.NroSocio = rand() % 2147483647;
		
			fread(&OldSocio, sizeof(OldSocio), 1, SociosArch);
			while(!feof(SociosArch)){
				if(OldSocio.NroSocio != NewSocio.NroSocio)
					Verificiar = true;
				else
					Verificiar = false;
				fread(&OldSocio, sizeof(OldSocio), 1, SociosArch);
			}
		}
	}
	
	printf("El numero de socio asignado es \"%i\"\n", NewSocio.NroSocio);
	pause();
	while(true)
	{
		printf("Ingrese la fecha de ingreso XX/XX/XXXX\n");
		scanf("%i/%i/%i", &NewSocio.FechaIng.Dia, &NewSocio.FechaIng.Mes, &NewSocio.FechaIng.Anual);
		if(!((1 <= NewSocio.FechaIng.Dia && NewSocio.FechaIng.Dia <= 31) && (1 <= NewSocio.FechaIng.Mes && NewSocio.FechaIng.Mes <= 12) && (2020 <= NewSocio.FechaIng.Anual && NewSocio.FechaIng.Anual <= 2023))){
			color(46);
			printf("Error: La fecha ingresa es invalida\n");
			printf("Fecha ingresada: %02i/%02i/%04i\n", NewSocio.FechaIng.Dia, NewSocio.FechaIng.Mes, NewSocio.FechaIng.Anual);
			pause();
			color(30);
		}
		else
			break;
	}
	
	SociosArch = fopen("Socios.dat", "ab");
	fwrite(&NewSocio, sizeof(NewSocio), 1, SociosArch);
	fclose(SociosArch);
	printf("El socio fue registrado correctamente\n");
	pause();
	
}

//Se registra las rutinas de gimnasia
bool RegistrarTurnos(FILE *Arch)
{
	
	struct Turnos Turno;
	int Si;
	
	pause();
	bool Valido;
	FILE *EntrenadorArch = fopen("Entrenadores.dat", "rb");
	struct Entrenador Entrenadores;
	//Se comprueba que el archivo exista
	//Para comprobar si el legajo es valido
	if(EntrenadorArch == NULL)
	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Entrenadores.dat\"\n");
		pause();
		color(07);
		exit(EXIT_FAILURE);
	}
	else
	{
		while(true)
		{
			printf("* El legajo ingresado debe ser de un entrenador registrado\n");
			printf("Ingresar el legajo del entrenador\n");
			
			scanf("%i", &Turno.legajoEntrenador);
			rewind(EntrenadorArch);
			fread(&Entrenadores, sizeof(Entrenadores), 1, EntrenadorArch);
			while(!feof(EntrenadorArch))
			{
				if(Entrenadores.Legajo == Turno.legajoEntrenador)
				{
					printf("El legajo ingresado corresponde a %s\n", Entrenadores.ApelYNom);
					pause();
					Valido = true;
					break;
				}
				else
					fread(&Entrenadores, sizeof(Entrenadores), 1, EntrenadorArch);
			}
			if(!Valido)
			{
				color(46);
				printf("Error: No se encontro el legajo ingresado\n");
				printf("Legajo: %i\n", Turno.legajoEntrenador);
				pause();
				color(30);
				printf("Quiere continuar? Si = 1// No != 1\n");
				scanf("%i", &Si);
				if(Si == 1)
					printf("");
				else
					return false;
			}
			else
				break;
		}
	}
	//Reestablecemos valido
	Valido = false;
	fclose(EntrenadorArch);
	system("CLS");
	//Ahora verificamos si el socio es valido
	//La cantidad de socios que se registraran
	struct Socio Socios;
	FILE *SociosArch = fopen("Socios.dat", "rb");
	//Se comprueba que el archivo exista
	if(SociosArch == NULL)
	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Socios.dat\"\n");
		pause();
		color(07);
		exit(EXIT_FAILURE);
	}
	else
	{
		while(true)
		{
			printf("* El numero del socio tiene que estar registrado\n");
			printf("Ingresar el numero de socio: ");
			scanf("%i", &Turno.nroSocio);
			rewind(SociosArch);
			fread(&Socios, sizeof(Socios), 1, SociosArch);
			while(!feof(SociosArch))
			{
				if(Socios.NroSocio == Turno.nroSocio)
				{
					printf("El numero de socio corresponde a %s\n", Socios.ApelYNom);
					pause();
					Valido = true;
					break;
				}
				fread(&Socios, sizeof(Socios), 1, SociosArch);
			}
			if(!Valido)
			{
				color(46);
				printf("Error: No se encontro numero de socio ingresado\n");
				printf("Numero de socio: %i\n", Turno.nroSocio);
				pause();
				color(30);
				printf("Quiere continuar? Si = 1// No != 1\n");
				scanf("%i", &Si);
				if(Si == 1)
					printf("");
				else
					return false;
			}
			else
			{
				printf("Se ingreso el numero de socio de %s\n", Socios.ApelYNom);
				break;
			}
		}
	}
	
	//Reestablecemos otra vez para comprobar si el entrenador trabaja ese dia
	Valido = false;
	int eleccion, i;
	while(!Valido)
	{
		printf("* El dia ingresado debe coincidir con un dia que el entrenador trabaja\n");
		printf("Ingresar el dia donde esta ubicado el turno\n");
		printf("Lunes = 1\nMartes = 2\nMiercoles = 3\n");
		printf("Jueves = 4\nViernes = 5\nSabado = 6\nDomingo = 7\n\n");
		printf("Ingrese: ");
		scanf("%i", &eleccion);
		switch(eleccion)
		{
			case 1:
				if(Entrenadores.Dias[eleccion-1] == eleccion)
					Turno.Dia = eleccion;
				else
				{
				//Si el dia del entrenador no coincide
				color(46);
				printf("Error: El dia ingresado no coincide con el del entrenador\n");
				printf("Dia ingresado(numero): %i\n", eleccion);
				pause();
				color(30);
				}
				break;
				
			case 2:
				if(Entrenadores.Dias[eleccion-1] == eleccion)
					Turno.Dia = eleccion;
				else
				{
				//Si el dia del entrenador no coincide
				color(46);
				printf("Error: El dia ingresado no coincide con el del entrenador\n");
				printf("Dia ingresado(numero): %i\n", eleccion);
				pause();
				color(30);
				}
				break;
				
			case 3:
				if(Entrenadores.Dias[eleccion-1] == eleccion)
					Turno.Dia = eleccion;
				else
				{
				//Si el dia del entrenador no coincide
				color(46);
				printf("Error: El dia ingresado no coincide con el del entrenador\n");
				printf("Dia ingresado(numero): %i\n", eleccion);
				pause();
				color(30);
				}
				break;
			
			case 4:
			if(Entrenadores.Dias[eleccion-1] == eleccion)
					Turno.Dia = eleccion;
			else
				{
				//Si el dia del entrenador no coincide
				color(46);
				printf("Error: El dia ingresado no coincide con el del entrenador\n");
				printf("Dia ingresado(numero): %i\n", eleccion);
				pause();
				color(30);
				}
				break;
				
			case 5:
			if(Entrenadores.Dias[eleccion-1] == eleccion)
					Turno.Dia = eleccion;
				else
				{
				//Si el dia del entrenador no coincide
				color(46);
				printf("Error: El dia ingresado no coincide con el del entrenador\n");
				printf("Dia ingresado(numero): %i\n", eleccion);
				pause();
				color(30);
				}
				break;
				
			case 6:
				if(Entrenadores.Dias[eleccion-1] == eleccion)
					Turno.Dia = eleccion;
				else
				{
				//Si el dia del entrenador no coincide
				color(46);
				printf("Error: El dia ingresado no coincide con el del entrenador\n");
				printf("Dia ingresado(numero): %i\n", eleccion);
				pause();
				color(30);
				}
				break;
				
			case 7:
				if(Entrenadores.Dias[eleccion-1] == eleccion)
					Turno.Dia = eleccion;
				else
				{
				//Si el dia del entrenador no coincide
				color(46);
				printf("Error: El dia ingresado no coincide con el del entrenador\n");
				printf("Dia ingresado(numero): %i\n", eleccion);
				pause();
				color(30);
				}
				break;
			
			default:
				color(46);
				printf("Error: Opcion ingresada no valida\n");
				printf("Opcion: %i\n", eleccion);
				pause();
				color(30);
				break;

		}
	}
	fclose(SociosArch);
	Valido = false;
	while(!Valido)
	{
		printf("A continuacion aqui estan los horarios\n");
		printf("1. 8:00 A 10:00\n");
		printf("2. 10:00 A 12:00\n");
		printf("3. 01:00 A 03:00\n");
		printf("4. 03:00 A 05:00\n");
		printf("5. 05:00 A 07:00\n");
		printf("6. 07:00 A 09:00\n");
		printf("7. 09:00 A 11:00\n");
		printf("Ingrese su opcion: ");
		scanf("%i", &eleccion);
		switch(eleccion)
		{
			case 1:
				Turno.HoraInicial = 8;
				Valido = VerficiarRutina(Arch, Turno.Dia, Turno.HoraInicial, Turno.legajoEntrenador);
				if(!Valido)
					return false;
				break;
			case 2:
				Turno.HoraInicial = 10;
				if(!VerficiarRutina(Arch, Turno.Dia, Turno.HoraInicial, Turno.legajoEntrenador));
					return false;
				break;
			case 3:
				Turno.HoraInicial = 1;
				if(!VerficiarRutina(Arch, Turno.Dia, Turno.HoraInicial, Turno.legajoEntrenador));
					return false;
				break;
			case 4:
				Turno.HoraInicial = 3;
				if(!VerficiarRutina(Arch, Turno.Dia, Turno.HoraInicial, Turno.legajoEntrenador));
					return false;
				break;
			case 5:
				Turno.HoraInicial = 5;
				if(!VerficiarRutina(Arch, Turno.Dia, Turno.HoraInicial, Turno.legajoEntrenador));
					return false;
				break;
			case 6:
				Turno.HoraInicial = 7;
				if(!VerficiarRutina(Arch, Turno.Dia, Turno.HoraInicial, Turno.legajoEntrenador));
					return false;
				break;
			case 7:
				Turno.HoraInicial = 9;
				if(!VerficiarRutina(Arch, Turno.Dia, Turno.HoraInicial, Turno.legajoEntrenador));
					return false;
				break;
			default:
				color(46);
				printf("Error: Opcion ingresada no valida\n");
				printf("Opcion: %i\n", eleccion);
				pause();
				color(30);
				break;
		}
		if(Valido)
			break;
		else
			printf("");
	
	}
	color(02);
	fwrite(&Turno, sizeof(Turno), 1, Arch);
	printf("\nSe registro exitosamente la rutina\n");
	pause();
	color(30);
}

#endif
