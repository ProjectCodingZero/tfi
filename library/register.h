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

void IngresarDatoChar(char Nombre[50], char Dato[300], char Quien[20]);
bool VerificadorPass(char contra[50]);
bool VerificadorUserUser(char Usuario[50]);

bool CreationSocio();
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
	char User[50], Contra[50];
	printf("Ingresar nuevo usuario: ");
	while(true)
	{
		_flushall();
		gets(User);
		_flushall();
		printf("A continuacion se comprobora si el usuario cumple con los requisitos:\n");
		
		
		if(VerificadorUserUser(User))
		{
			//Si el usuario el aceptado saldra del while
			break;
		}
		else{
			printf("Quiere volver a intentar? (S)i o (N)o");
			scanf("%c", &Intento);
			if(toupper(Intento) != 'S')
			{
				return false; //Para salir de la funcion
			}
			else
			{
			printf("Vuelva a ingresar un usuario: ");
			}
		}
	}

	printf("Ingrese la contrasena del nuevo usuario: ");
	while(true)
	{
		_flushall();
		gets(Contra);
		_flushall();
		printf("A continuacion se comprobora si la contrasena cumple con los requisitos:\n");
		
		
		if(VerificadorPass(Contra))
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
				return false; //Para salir de la funcion
			}
			else
			{
				printf("Vuelva a ingresar una contrasena: ");
			}
		}
	}
	
	char nombre[60];
	IngresarChar("nombre y apellido", nombre, "usuario");
	strcpy(NewUser.usuario, User);
	strcpy(NewUser.contrasena, Contra);
	strcpy(NewUser.ApelYNom, nombre);

	FILE *ArchivoUser;
	ArchivoUser = fopen("../data/Usuarios.dat", "ab"); //Agregar datos al Usuarios.dat ubicado en la carpeta data
	if(ArchivoUser == NULL)
	{
		color(46);
		printf("\nError el archivo no se pudo crear\\escribir\n");
		color(07);
	}
	
	fwrite(&NewUser, sizeof(NewUser), 1, ArchivoUser);
	fclose(ArchivoUser);
}

bool CreationSocio()
{	
	system("CLS");
	struct Socio NewSocio; 
	color(30);
	printf("Bienvenido a la creacion de socio\n");
	pause();
	
	//Se ingresa el nombre y apellido
	IngresarChar("Nombre", NewSocio.ApelYNom, "socio");
	//Se ingresa la direccion
	IngresarChar("Direccion", NewSocio.Direccion, "socio");
	//Se ingresa el celular
	IngresarNumero("Celular", NewSocio.Celular, "socio");
	//Se ingresa el dni
	IngresarNumero("DNI", NewSocio.DNI, "socio");
	//Se ingresa las indicaciones medicas
	int i, rta = 15;
	IngresarChar("Actividaes", NewSocio.Actividades, "socio");
	//Se ingresa la altura
	IngresarNumero("Altura", NewSocio.Altura, "socio");
	//Se ingresa el peso
	IngresarNumero("Peso", NewSocio.Altura, "socio");
	srand(time(NULL));
	NewSocio.NroSocio = rand() % 2147483647;
	printf("El numero de socio asignado es %i\n", NewSocio.NroSocio);
	printf("Ingrese la fecha XX/XXXX/XX\n");
	do{
		scanf("%i/%i/%i", NewSocio.FechaNacimiento.Dia, NewSocio.FechaNacimiento.Mes, NewSocio.FechaNacimiento.Anual);
	}while((NewSocio.FechaNacimiento.Dia >= 1 && NewSocio.FechaNacimiento.Dia <= 31) && (1 <= NewSocio.FechaNacimiento.Mes && NewSocio.FechaNacimiento.Mes <= 12) && (1000 <= NewSocio.FechaNacimiento.Anual && NewSocio.FechaNacimiento.Anual <= 9999));
	FILE *SocioArch = fopen("../data/Socios.dat", "ab");
	fwrite(&NewSocio, sizeof(NewSocio), 1, SocioArch);
	printf("El socio fue registrado correctamente\n");
	pause();
	
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
	
	FILE *Users;
	struct Usuario NewUser;
	Users = fopen("../data/Usuarios.dat", "r");
	rewind(Users);
	//Comprobar si existe el archivos Usuarios.dat
	if(Users == NULL)
	{
		color(46);
		printf("\nError: El archivo \"Usuarios.dat\" no se encuentra disponible\n");
		pause();
		color(07);
		exit(EXIT_FAILURE);
	}
	fread(&NewUser, sizeof(NewUser), 1, Users); 
	//Comprueba si el usuario ya existe dentro del archivo
	printf(".");
	while(!feof(Users))
	{
		if(strcmp(NewUser.usuario, Usuario) == 0)
		{
			//Aparece un error si el usuario ya existe en el archivo "Usuarios.dat"
			color(46);
			printf("\nError: El usuario ingresado ya existe intento con otro nombre de usuario\n");

			pause();
			color(30);
			return false;
		}
		fread(&NewUser, sizeof(NewUser), 1, Users);
	}
	fclose(Users); //Se cierra el archivo
	//Si ha pasado todas las condiciones la contrasena es apta para uso
	color(02);
	printf("\nEl usuario cumple no tuvo ningun error!!!\n")
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
void RegistrarTurnos(){
	
}
#endif
