#ifndef register_h
#define register_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wctype.h>
#include <ctype.h>
#include <time.h>
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

bool VerificadorPass(char contra[50]);
bool VerificadorUserUser(char Usuario[50], FILE *Archivo);

void CreationSocio();
bool registerUser();

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
	for(Dia = 0; Dia < 7; Dia++)
	{
		if(NewEntrenador.Dias[Dia-1] != 0)
			NewEntrenador.HrasPromedio += 8;
	}
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
	char Intento;
	while(true)
	{
		printf("* Debera contener al menos una letra mayuscula, una letra minuscula y un numero.\n");
		printf("* Sólo caracteres alfanumericos.\n");
		printf("* Debera tener entre 6 y 32 caracteres.\n");
		printf("* No debe tener mas de 3 caracteres numericos consecutivos.\n");
		printf("* No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas\n");
		printf("Ingrese la contrasena del nuevo usuario: ");
		_flushall();
		gets(NewEntrenador.contrasena);
		_flushall();
		printf("A continuacion se comprobora si la contrasena cumple con los requisitos:\n");
		
		
		if(VerificadorPass(NewEntrenador.contrasena))
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
				printf("Opcion: \"%c\"\n", Dia);
				pause();
				color(30);
			}
		}
	}
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
bool RegistrarTurnos()
{
	struct Turnos Turno;
	int Si;
	while(true)
	{
		printf("Ingresar la fecha XX/XX/XXXX\n");
		
		scanf("%i/%i/%i", &Turno.fecha.Dia, &Turno.fecha.Mes, &Turno.fecha.Anual);
		if((Turno.fecha.Dia >= 1 && Turno.fecha.Dia <= 31) && (1 <= Turno.fecha.Mes && Turno.fecha.Mes <= 12) && (2023 <= Turno.fecha.Anual && Turno.fecha.Anual <= 9999)){
			color(46);
			printf("Error: La fecha esta no tiene sentido\n");
			printf("Fecha ingresada: %02i/%02i/%04i\n", Turno.fecha.Dia, Turno.fecha.Mes, Turno.fecha.Anual);
			pause();
			color(30);
		}
		else
			break;
	}
	pause();
	bool Valido;
	int legajo;
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
			printf("Ingresar el legajo del entrenador\n");
			printf("* El legajo ingresado debe ser de un entrenador registrado\n");
			scanf("%i", &Turno.legajoEntrenador);
			rewind(EntrenadorArch);
			fread(&Entrenadores, sizeof(Entrenadores), 1, EntrenadorArch);
			while(!feof(EntrenadorArch))
			{
				if(Entrenadores.Legajo == legajo)
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
				printf("Legajo: %i\n", legajo);
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
	int NroSocio;
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
			scanf("%i", &NroSocio);
			rewind(SociosArch);
			fread(&Socios, sizeof(Socios), 1, SociosArch);
			while(!feof(SociosArch))
			{
				if(Socios.NroSocio == NroSocio)
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
				printf("Numero de socio: %i\n", NroSocio);
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
	
	//Reestablecemos otra vez para comprobar si el entrenador trabaja ese dia
	Valido = false;
	int Dia;
	while(!Valido)
	{
		printf("Ingresar el dia donde esta ubicado el turno\n");
		printf("* El dia ingresado debe coincidir con un dia que el entrenador trabaja\n");
		printf("Lunes = 1\nMartes = 2\nMiercoles = 3\n");
		printf("Jueves = 4\nViernes = 5\nSabado = 6\nDomingo = 7\n\n");
		printf("Ingrese: ");
		scanf("%i", &Dia);
		if(Dia >= 1 && Dia <= 7)
		{
			
			pause();
			if(Entrenadores.Dias[Dia-1] == Dia)
			{
				Turno.dia = Dia;
				//Registramos el dia para el socio
				Socios.Dias[Dia-1] = Dia;
				printf("El dia fue exitosamenta registrado\n");
			}
			else{
				//Si el dia del entrenador no coincide
				color(46);
				printf("Error: El dia ingresado no coincide con el del entrenador\n");
				printf("Dia ingresado(numero): %i\n", Dia);
				pause();
				color(30);
			}
		}
		else
		{
			color(46);
			printf("Error: Opcion ingresada no valida\n");
			printf("Opcion: %i\n", Dia);
			pause();
			color(30);
		}
	}
	fclose(SociosArch);
	color(02);
	FILE *TurnosArch = fopen("./Turnos.dat", "ab");
	fwrite(&Turno, sizeof(Turno), 1, TurnosArch);
	fclose(TurnosArch);
	printf("\nSe registro exitosamente la rutina\n");
	pause();
	color(30);
}

bool VerificadorUserUser(char Usuario[50], FILE *Archivo)
{ 	

	//Verificar si el dato ingresado es correcto
	printf("Su usuario se esta verificando.");
	if(!(strlen(Usuario) >= 6))
	{
		color(46);
		printf("\nError: El usuario ingresado tiene un tamano menor a 6 caracteres\n");
		printf("Cantidad de caracteres ingresado: %i\n", strlen(Usuario));
		pause();
		color(30);
		return false;
	}
	else if(!(strlen(Usuario) <= 10))
	{
		color(46);
		printf("\nError: El usuario ingresado tiene un tamano menor a 6 caracteres\n");
		printf("Cantidad de caracteres ingresado: %i\n", strlen(Usuario));
		pause();
		color(30);

		return false;
	}


	/*Comprueba si la primera letra es minuscula*/
	if(!iswlower(Usuario[0]))
	{
		color(46);
		printf("\nError: El nombre ingresado no empieza con minuscula\n");

		pause();
		color(30);
		return false;
	}

	printf(".");
	int i;
	int May; //Cantidad de mayusculas
	int digitos; //Cantidad de digitos
	for(i = 0, May = 0, digitos = 0; i < strlen(Usuario); i++)
	{
		May += (iswupper(Usuario[i]))? 1: 0; //Si es mayuscula se le agrega uno
		digitos += (isdigit(Usuario[i]))? 1: 0; //Si es un digito se agrega uno
	}
	if(!(digitos <= 3))
	{ 
		//Si el nombre tiene mas de 3 digitos aparece un error
		color(46);
		printf("\nError: El nombre tiene mas digitos de lo que se permite(3)\n");
		printf("Cantidad de digitos: %i\n", digitos);

		pause();
		color(30);
		return false;
	}

	if(!(May >= 2))
	{ 
		//Si el nombre tiene menos de 2 mayusculas aparece un error
		color(46);
		printf("\nError: El nombre tiene menos mayusculas que las que permiten(2)\n");
		printf("\nCantidad de mayusculas: %i\n", May);

		pause();
		color(30); 
		return false;
	}
	
	FILE *UserArch;
	struct Usuario NewUser;
	rewind(UserArch);
	//Comprobar si existe el archivos Usuarios.dat
	fread(&NewUser, sizeof(NewUser), 1, UserArch); 
	//Comprueba si el usuario ya existe dentro del archivo
	printf(".");
	while(!feof(Archivo))
	{
			
		if(strcmp(NewUser.usuario, Usuario) == 0)
		{
			//Aparece un error si el usuario ya existe en el archivo "Usuarios.dat"
			color(46);
			printf("\nError: El usuario ingresado ya existe\n");

			pause();
			color(30);
			return false;
		}
			fread(&NewUser, sizeof(NewUser), 1, Archivo);
	}
	//Si ha pasado todas las condiciones la contrasena es apta para uso
	
	color(02);
	printf("\nEl usuario cumple no tuvo ningun error!!!\n");
	pause();
	color(30);
	return true;
}

bool VerificadorPass(char contra[50])
{
	printf("Su contrasena se esta verificando.");
	int i;
	bool minuscula, mayuscula, numero; 
	//Comprobar si tiene minuscula, mayuscula y numero respectivamente

	int contador = 0;
	for(i = 0, mayuscula = 0, minuscula = 0, numero = 0;i < strlen(contra); i++)
	{
		if(!(iswalnum(contra[i])))
		{
		//comprueba si no hay espacion ni signos de puntuacion

		color(46);

		printf("\nError: Uno/s de los caracteres ingresados no es caracter alfanumerico\n");
		printf("Caracter no alfanumerico encontrado: %c\n", contra[i]);
		pause();

		color(30);
		return false;
		}
		
		if(isdigit(contra[i]))
		{
			numero = true;

			/* Comprueba si el siguiente numero es seguido o no
			Antes comprueba que elemento i+1 exista para no
			generar ningun error */
			if(i+1 < strlen(contra) && contra[i] == contra[i+1] - 1)
			{
				contador++;
			}
			else
			{
				contador = 0;
			}
			
			if(contador > 2)
			{
				color(46);

				printf("\nError: La contrasena tiene 3 o mas numeros consecutivos\n");
				printf("Sucesion numerica encontrada: \"%c%c%c%c\"\n", contra[i-2], contra[i-1], contra[i], contra[i+1]);
				pause();

				color(30);
				return false;
			}
			
		}
		else
		{
			minuscula = (minuscula || iswlower(contra[i]))? true: false;
			mayuscula = (mayuscula || iswupper(contra[i]))? true: false;
			if(i+1 < strlen(contra) && toupper(contra[i]) == toupper(contra[i+1]-1)){
				color(46);

				printf("\nError: La contrasena tiene 2 letras consecutivas\n");
				printf("Sucesion alfabetica encontrada: \"%c%c\"\n", contra[i], contra[i+1]);
				pause();

				color(30);
				return false;
			}
		}
		/* Comprueba si la caracter es minuscula mayuscula o un numero
		Si ya tiene uno de esto ya la condicion es verdadera
		asi que no se necesita volver a verificar */
		
	printf(".");
	}

	printf("%s", contra);
	if(!minuscula)
	{
		//Si no hay minusculas
		color(46);

		printf("\nError: Su contrasena no contiene ninguna minuscula\n");
		pause();
		color(30);
		return false;
	}
	else if(!mayuscula)
	{
		//Si no hay mayusculas
		color(46);

		printf("\nError: Su contrasena no contiene ninguna mayuscula\n");
		pause();
		color(30);
		return false;
	}

	else if(!numero)
	{
		//Si no hay numeros
		color(46);

		printf("\nError: Su contrasena no contiene ningun numero\n");
		pause();
		color(30);
		return false;
	}

	printf(".");

	if(strlen(contra) < 6)
	{
		//Si es menor a 6 caracteres
		color(46);

		printf("\nError: Su contrasena es contiene menos de los caracteres indicados(6)\n");
		printf("Cantidad de caracteres: %i\n", strlen(contra));
		pause();
		color(30);

		return false;
	}
	else if(strlen(contra) > 32)
	{
		//Si es mas de 32 caracteres
		color(46);

		printf("\nError: Su contrasena es contiene mas de los caracteres indicados(32)\n");
		printf("Cantidad de caracteres: %i\n", strlen(contra));
		pause();
		color(30);

		return false;
	}

	//Si ha pasado todas las condiciones la contrasena es apta para uso
	color(02);
	printf("\nLa contrasena cumple no tuvo ningun error!!!\n")
	pause();
	color(30);
	return true;

}

#endif
