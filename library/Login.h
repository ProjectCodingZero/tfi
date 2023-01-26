#ifndef Login_h
#define Login_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "library.h"
#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);

//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02



bool loginUser(char usuario[50], char contrasena[50], char Nombre[60])
{
	//El inicio de sesion
	struct Usuario User; //El usuario que va a ingresar
	FILE *UserArch;
	UserArch = fopen("Usuarios.dat", "rb"); // Se abre el archivo para comprobar si ya existe el usuario
	if(UserArch == NULL)
	{ 
		//Se comprueba que el archivo exista
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Usuarios.dat\"");
		color(07);
		exit(EXIT_FAILURE);
	}
	else
	{ 
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
	}
	fclose(UserArch);
	return false;
}
bool loginEntrenador(char contrasena[50], char Nombre[60]){
	//El inicio de sesion
	struct Entrenador ElEntrenador; //El usuario que va a ingresar
	FILE *EntrenadoresArch;
	EntrenadoresArch = fopen("Entrenadores.dat", "rb"); // Se abre el archivo para comprobar si ya existe el usuario
	if(EntrenadoresArch == NULL)
	{ 
		//Se comprueba que el archivo exista
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Entrenadores.dat\"");
		color(07);
		exit(EXIT_FAILURE);
	}
	else
	{ 
		//Si el archivo existe procede a verificar si el usuario existe
		rewind(EntrenadoresArch);
		fread(&ElEntrenador, sizeof(ElEntrenador), 1, EntrenadoresArch);
		while(!feof(EntrenadoresArch))
		{
			if(strcmp(ElEntrenador.contrasena, contrasena) == 0)
			{
				printf("El usuario a ingresado con exito\n");
				Nombre = ElEntrenador.ApelYNom;
				fclose(EntrenadoresArch);
				return true;
			}
			else
			{
				fread(&ElEntrenador, sizeof(ElEntrenador), 1, EntrenadoresArch);
			}
		}
		color(46);
		printf("\nError: Contrasena ingresa no pertenecen a ningun entrenador\n");
		pause();
		color(30);
	}
	fclose(EntrenadoresArch);
	return false;
}

#endif
