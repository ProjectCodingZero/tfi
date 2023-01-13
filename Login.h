#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "library.h"


#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);

//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02



bool loginUser(char usuario[50], char contrasena[50])
{
	//El inicio de sesion
	struct Usuario User; //El usuario que va a ingresar
	FILE *ArchivoUser;
	ArchivoUser = fopen("Usuarios.dat", "r"); // Se abre el archivo para comprobar si ya existe el usuario
	if(ArchivoUser == NULL)
	{ 
		//Se comprueba que el archivo exista
		color(46);
		printf("Error al abrir el archivo");
		color(07);
		exit(EXIT_FAILURE);
	}
	else
	{ 
		//Si el archivo existe procede a verificar si el usuario existe
		rewind(ArchivoUser);
		fread(&User, sizeof(User), 1, ArchivoUser);
		while(!feof(ArchivoUser))
		{
			if( (strcmp(User.usuario, usuario) == 0) && (strcmp(User.contrasena, contrasena) == 0) )
			{
				printf("El usuario a ingresado con exito\n");
				return true;
			}
			else
			{
				fread(&User, sizeof(User), 1, ArchivoUser);
			}
		}
		printf("El nombre y contrasena indicados no pertenecen a ningun usuario\n");
		pause();
	}
	fclose(ArchivoUser);
}

