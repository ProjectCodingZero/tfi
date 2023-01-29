#ifndef verificar_h
#define verificar_h
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <wctype.h>
#include <ctype.h>
#include <string.h>
#define color(c); system("COLOR " #c);
#define pause(); system("PAUSE"); system("CLS");


bool loginUser(char usuario[50], char contrasena[50], char Nombre[60], FILE *UserArch)
{
	system("CLS");
	//El inicio de sesion
	struct Usuario User; //El usuario que va a ingresar

	//Si el archivo existe procede a verificar si el usuario existe
	rewind(UserArch);
	fread(&User, sizeof(User), 1, UserArch);
	while(!feof(UserArch))
	{
		if( (strcmp(User.usuario, usuario) == 0) && (strcmp(User.contrasena, contrasena) == 0) )
		{
			printf("El usuario a ingresado con exito\n");
			Nombre = User.ApelYNom;
			fclose(UserArch);
			return true;
		}
		else
		{
			fread(&User, sizeof(User), 1, UserArch);
		}
	}
	printf("\nEl nombre y contrasena ingresados no pertenecen a ningun usuario\n");
	pause();
	return false;
}


bool VerificadorUserUser(char Usuario[50], FILE *Archivo)
{ 	
	system("CLS");
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
	
	struct Usuario NewUser;
	rewind(Archivo);
	//Comprobar si existe el archivos Usuarios.dat
	fread(&NewUser, sizeof(NewUser), 1, Archivo); 
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
	system("CLS");
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

bool VerficiarRutina(FILE *arch, int Dia, int horario, int legajoEntrenador, int actividad)
{
	struct Turnos ElTurno;
	rewind(arch);
	fread(&ElTurno, sizeof(ElTurno), 1, arch);
	while(!feof(arch))
	{
		if((ElTurno.Dia == Dia && ElTurno.HoraInicial == horario && actividad == ElTurno.Actividad) && ElTurno.legajoEntrenador == legajoEntrenador)
			return true;
		else if((ElTurno.Dia == Dia && ElTurno.HoraInicial && actividad == ElTurno.Actividad) && ElTurno.legajoEntrenador != legajoEntrenador)
		{
			color(46);
			printf("Error: Un entrenador diferente ya tiene ocupado ese horario\n");
			
			printf("Legajo Ingresado: %i\n", legajoEntrenador);
			printf("Actividad: ");
			switch(actividad)
			{
				case 1:
					printf("Zumba\n");
					break;
				case 2:
					printf("Spining\n");
					break;
				case 3:
					printf("Pilate\n");
					break;
				default: 
					break;
			}
			printf("Dia: %s\n", Dia);
			printf("Horario Ingresado: %02i:00 - %02i:00\n", horario, horario+2);
			
			pause();
			color(30);
			return false;
		}
		fread(&ElTurno, sizeof(ElTurno), 1, arch);
	}
	//Si no hay entrenador registrado en ese horario se sigue
	//Se le agrega la carga horario al archivo de los entrenadores
	system("CLS");
	struct Entrenador Entrenador; //El entrenador que se le agrega la carga horaria
	FILE *EntrenadorArch = fopen("Entrenadores.dat", "rb");
	fread(&Entrenador, sizeof(Entrenador), 1, EntrenadorArch);
	FILE *EntrenadorArchAux =  fopen("EntrenadoresAux.dat", "wb");
	while(!feof(EntrenadorArch))
	{
		if(Entrenador.Legajo == legajoEntrenador)
		{
			Entrenador.cargaHoraria += 2;
			fwrite(&Entrenador, sizeof(Entrenador), 1, EntrenadorArch);
		}
		else
			fwrite(&Entrenador, sizeof(Entrenador), 1, EntrenadorArch);
		fread(&Entrenador, sizeof(Entrenador), 1, EntrenadorArch);
	}
	remove("Entrenadores.dat");
	rename("Entrenadores.dat", "EntrenadoresAux.dat");
	printf("Se registro la rutina al entrenador %s\n", Entrenador.ApelYNom);
	return true;
}

#endif
