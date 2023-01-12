#include <stdio.h>
#include <stdlib.h>
#define pause(); system("PAUSE"); system("CLS"); ;
#define color(c); system("COLOR " #c);

#include <stdbool.h>
#include <string.h>
#include <wctype.h>
#include <ctype.h>

bool VerificadorUserUser(char Usuario[10]);


struct Usuario{
	char usuario[50];
	char contrasena[50];
	char ApelYNom[60];
};

struct Entrenador{
	char ApelYNom[60];
	int Dias[6];
	int Legajo;
	char contrasena[10];
};


bool loginUser(char usuario[10], char contrasena[10])
{ 
	//El inicio de sesion
	struct Usuario User; //El usuario que va a ingresar
	FILE *Users;
	Users = fopen("Usuarios.dat", "r"); // Se abre el archivo para comprobar si ya existe el usuario
	if(Users == NULL)
	{ //Se comprueba que el archivo exista
		printf("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	else
	{ 
		//Si el archivo existe procede a verificar si el usuario existe
		rewind(Users);
		fread(&User, sizeof(User), 1, Users);
		while(!feof(Users))
		{
			if( (strcmp(User.usuario, usuario) == 0) && (strcmp(User.contrasena, contrasena) == 0) )
			{
				printf("El usuario a ingresado con exito\n");
				return true;
			}
			else
			{
				fread(&User, sizeof(User), 1, Users);
			}
		}
		printf("El nombre y contrasena indicados no pertenecen a ningun usuario\n");
		pause();
	}
	
}

void registerUser()
{
	system("CLS");
	printf("Bienvenido a la creacion de usuario\n");
	system("PAUSE");
	struct Usuario NewUser;
	char User[10];
	while(true)
	{
		printf("Ingresar nuevo usuario: ");
		_flushall();
		gets(User);
		_flushall();
		printf("A continuacion se comprobora si el usuario cumple con los requisitos de usuario");
		pause();
		VerificadorUserUser(User);
	}
	FILE *Users;
	Users = fopen("Usuarios.dat", "a"); //Agregar datos al Usuarios.dat
	
}

bool VerificadorUserUser(char Usuario[50])
{ 
	//Verificar si el dato ingresado es correcto
	printf("Su usuario se esta verificando.");
	if(!(strlen(Usuario) >= 6))
	{
		color(46); //Color de error
		printf("\nError: El usuario ingresado tiene un tamano menor a 6 caracteres\n");
		printf("Cantidad de caracteres ingresado: %i\n", strlen(Usuario));
		pause();
		return false;
	}
	if else(!(strlen(Usuario) <= 10)){
		color(46); //Color de error
		printf("\nError: El usuario ingresado tiene un tamano menor a 6 caracteres\n");
		printf("Cantidad de caracteres ingresado: %i\n", strlen(Usuario));
		pause();
		return false;
	}


	/*Comprueba si la primera letra es minuscula*/
	if(!iswlower(Usuario[0]))
	{
		color(46); //Color de error
		printf("\nError: El nombre ingresado no empieza con minuscula\n");

		pause();
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
		color(46); //Color de error
		printf("\nError: El nombre tiene mas de 3 digitos\n");
		printf("Cantidad de digitos: %i\n", digitos);

		pause();
		color(30); //Color normal
		return false;
	}

	if(!(May >= 2))
	{ 
		//Si el nombre tiene menos de 2 mayusculas aparece un error
		color(46); //Color de error
		printf("\nError: El nombre tiene menos de 2 mayusculas\n");
		printf("\nCantidad de mayusculas: %i\n", May);

		pause();
		color(30); //Color normal
		return false;
	}
	
	FILE *Users;
	struct Usuario NewUser;
	Users = fopen("Usuarios.dat", "r");
	rewind(Users);
	fread(&NewUser, sizeof(NewUser), 1, Users); 
	//Comprueba si el usuario ya existe dentro del archivo

	printf(".")
	while(!feof(Users))
	{
		if(strcmp(NewUser.usuario, Usuario) == 0)
		{
			//Aparece un error si el usuario ya existe en el archivo "Usuarios.dat"
			color(46); //Color de error
			printf("\nError: El usuario ingresado ya existe intento con otro nombre de usuario\n");

			pause();
			color(30); //Color normal
			return false;
		}
		fread(&NewUser, sizeof(NewUser), 1, Users);
	}
	fclose(Users); //Se cierra el archivo
	
	//Si ha pasado todas las condiciones la contrasena es apta para uso
	color(02)
	printf("\nEl usuario cumple no tuvo ningun error!!!\n")
	pause();
	color(30);
	return true;
}

bool VerificadorContra(char contra[50])
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

		color(46); //Color de error

		printf("\nError: Uno/s de los caracteres ingresados no es caracter alfanumerico\n");
		printf("Caracter no alfanumerico encontrado: %c\n", contra[i]);
		pause();

		color(30); //Color normal
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
				color(46); //Color de error

				printf("\nError: La contrasena tiene 3 o mas numeros consecutivos\n");
				printf("Sucesion numerica encontrada: \"%c%c%c\"\n", contra[i-1], contra[i], contra[i+1]);
				pause();

				color(30); //Color normal
				return false;
			}
			
		}
		else
		{
			minuscula = (minuscula || iswlower(contra[i]))? true: false;
			mayuscula = (mayuscula || iswupper(contra[i]))? true: false;
			if(i+1 < strlen(contra) && toupper(contra[i]) == toupper(contra[i+1]-1)){
				color(46); //Color de error

				printf("\nError: La contrasena tiene 2 letras consecutivas\n");
				printf("Sucesion alfabetica encontrada: \"%c%c\"\n", contra[i], contra[i+1]);
				pause();

				color(30); //Color normal
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
		color(46); //Color de error

		printf("\nError: Su contrasena no contiene ninguna minuscula\n");
		pause();
		color(30); //Color normal
		return false;
	}
	else if(!mayuscula)
	{
		//Si no hay mayusculas
		color(46); //Color de error

		printf("\nError: Su contrasena no contiene ninguna mayuscula\n");
		pause();
		color(30); //Color normal
		return false;
	}

	else if(!numero)
	{
		//Si no hay numeros
		color(46); //Color de error

		printf("\nError: Su contrasena no contiene ningun numero\n");
		pause();
		color(30); //Color normal
		return false;
	}

	printf(".");

	if(strlen(contra) < 6)
	{
		//Si es menor a 6 caracteres
		color(46); //Color de error

		printf("\nError: Su contrasena es contiene menos de los caracteres indicados(6)\n");
		printf("Cantidad de caracteres: %i\n", strlen(contra));
		pause();
		color(30); //Color normal

		return false;
	}
	else if(strlen(contra) > 32)
	{
		//Si es mas de 32 caracteres
		color(46); //Color de error

		printf("\nError: Su contrasena es contiene mas de los caracteres indicados(32)\n");
		printf("Cantidad de caracteres: %i\n", strlen(contra));
		pause();
		color(30); //Color normal

		return false;
	}

	//Si ha pasado todas las condiciones la contrasena es apta para uso
	color(02)
	printf("\nLa contrasena cumple no tuvo ningun error!!!\n")
	pause();
	color(30);
	return true;

}
