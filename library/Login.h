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



bool loginUser(char usuario[50], char contrasena[50], char Nombre[60], FILE *UserArch)
{
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

#endif
