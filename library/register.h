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
#define IngresarNumero(TipoDato, Dato, Quien); \
system("CLS"); printf("Ingresar %s del nuevo %s\n",TipoDato , Quien); \
if(sizeof(Dato) == sizeof(int)){ \
	scanf("%i", &Dato); \
} \
else{ \
	scanf("%f", &Dato);\
}

#define IngresarChar(TipoDato, Texto, Quien); \
system("CLS"); printf("Ingresar %s del nuevo %s\n",TipoDato , Quien); \
_flushall(); gets(Texto); _flushall();

bool VerificadorPass(char contra[50]);
bool VerificadorUserUser(char Usuario[50]);

void CreationSocio();
bool registerUser();

//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02
bool registerUser()
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
		
		
		if(VerificadorUserUser(NewUser.usuario))
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
		printf("* Sólo caracteres alfanumericos.\n");
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
			if(toupper(Intento) != 'S')
			{
				pause();
				return false; //Para salir de la funcion
			}
			else
			{
				printf("Vuelva a ingresar una contrasena: ");
				pause();
			}
		}
	}
	
	char nombre[60];
	IngresarChar("nombre y apellido", NewUser.ApelYNom, "usuario");

	FILE *UserArch;
	UserArch = fopen("Usuarios.dat", "ab"); //Agregar datos al Usuarios.dat ubicado en la carpeta data	
	fwrite(&NewUser, sizeof(NewUser), 1, UserArch);
	fclose(UserArch);
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
	
	printf("El numero de socio asignado es %i\n", NewSocio.NroSocio);
	
	while(true)
	{
		printf("Ingrese la fecha de ingreso XX/XX/XXXX\n");
		scanf("%i/%i/%i", &NewSocio.FechaIng.Dia, &NewSocio.FechaIng.Mes, &NewSocio.FechaIng.Anual);
		if((1 <= NewSocio.FechaIng.Dia && NewSocio.FechaIng.Dia <= 31) && (1 <= NewSocio.FechaIng.Mes && NewSocio.FechaIng.Mes <= 12) && (1000 <= NewSocio.FechaIng.Anual && NewSocio.FechaIng.Anual <= 9999)){
			color(46);
			printf("Error: La fecha ingresa es invalida\n");
			printf("Fecha ingresada: %02i/%02i/%04i\n", NewSocio.FechaIng.Dia, NewSocio.FechaIng.Mes, NewSocio.FechaIng.Anual);
			pause();
			color(30);
		}
		else
			break;
	}
	do{
		scanf("%i/%i/%i", &NewSocio.FechaIng.Dia, &NewSocio.FechaIng.Mes, &NewSocio.FechaIng.Anual);
	}while((NewSocio.FechaIng.Dia >= 1 && NewSocio.FechaIng.Dia <= 31) && (1 <= NewSocio.FechaIng.Mes && NewSocio.FechaIng.Mes <= 12) && (1000 <= NewSocio.FechaIng.Anual && NewSocio.FechaIng.Anual <= 9999));
	
	//SE fija los dias de rutina para no provocar errores a futuro
	for(i = 0; i < 10; i++){
		NewSocio.FechaRutina[i].Dia = 0;
		NewSocio.FechaRutina[i].Mes = 0;
		NewSocio.FechaRutina[i].Anual = 0;
	}
	
	SociosArch = fopen("Socios.dat", "ab");
	fwrite(&NewSocio, sizeof(NewSocio), 1, SociosArch);
	printf("El socio fue registrado correctamente\n");
	pause();
	
}

//Se registra las rutinas de gimnasia
void RegistrarTurnos()
{
	struct Turnos Turno;

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
		struct Entrenador Entrenadores;
		while(true)
		{
			printf("Ingresar el legajo del entrenador\n");
			scanf("%i", &Turno.legajoEntranador);
			rewind(EntrenadorArch);
			fread(&Entrenadores, sizeof(Entrenadores), 1, EntrenadorArch);
			while(!feof(EntrenadorArch))
			{
				if(Entrenadores.Legajo == legajo)
				{
					Valido = true;
					break;
				}
				else
					fread(&Entrenadores, sizeof(Entrenadores), 1, EntrenadorArch);
			}
			if(!Valido)
			{
				color(46);
				printf("Error: No existe un entrenador con el legajo ingresado\n");
				printf("Legajo: %i", legajo);
				pause();
				color(30);
			}
			else
				break;
		}
	}
	//Reestablecemos valido
	Valido = 0;
	fclose(EntrenadorArch);
	pause();
	//Ahora verificamos si el socio es valido
	int NroSocio;
	
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
		struct Socio Socios;
		while(true)
		{
			printf("Ingresar el numero de socio\n");
			scanf("%i", &NroSocio);
			rewind(SociosArch);
			fread(&Socios, sizeof(Socios), 1, SociosArch);
			while(!feof(SociosArch))
			{
				if(Socios.NroSocio == NroSocio)
				{
					Valido = true;
					break;
				}
				fread(&Socios, sizeof(Socios), 1, SociosArch);
			}
			if(!Valido)
			{
				color(46);
				printf("Error: No existe un entrenador con el nuemero de socio ingresado\n");
				printf("Numero de socio: %i\n", NroSocio);
				pause();
				color(30);
			}
			else
				break;
		}
	
	}
	fclose(SociosArch);
	color(02);
	FILE *TurnosArch = fopen("Turnos.dat", "ab");
	fwrite(&Turno, sizeof(Turno), 1, TurnosArch);
	printf("\nSe registro exitosamente la rutina\n");
	pause();
	color(30);
}

bool VerificadorUserUser(char Usuario[50])
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
	else if(!(strlen(Usuario) <= 10)){
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
	UserArch = fopen("./Usuarios.dat", "rb");
	rewind(UserArch);
	//Comprobar si existe el archivos Usuarios.dat
	if(UserArch == NULL)
	{
		fclose(UserArch);
		UserArch = fopen("Usuarios.dat", "wb");
		printf("\nSe acaba de crear la carpeta \"Usuarios.dat\n");
		fclose(UserArch);
	}
	else{
		fread(&NewUser, sizeof(NewUser), 1, UserArch); 
		//Comprueba si el usuario ya existe dentro del archivo
		printf(".");
		while(!feof(UserArch))
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
			fread(&NewUser, sizeof(NewUser), 1, UserArch);
		}
		fclose(UserArch); //Se cierra el archivo
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
