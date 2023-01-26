#ifndef listado_h
#define lsitado_h
#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#define color(c); system("COLOR " #c);
#define pause(); system("PAUSE"); system("CLS");

//El listado de los socios y que actividades que desarrolla
void ListadoSocios(){
	color(30);
	struct Socio Socios;
	FILE *SocioArch = fopen("./Socios.dat", "rb");
	if(SocioArch == NULL){
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Socios.dat\"\n");
		pause();
		color(07);
		fclose(SocioArch);
		exit(EXIT_FAILURE);
	}
	else{
		int i;
		fread(&Socios, sizeof(Socios), 1, SocioArch);
		while(!feof(SocioArch)){
			printf("\nNombre Completo: %s\n", Socios.ApelYNom);
			printf("Celular:%i\n", Socios.Celular);
			printf("DNI: %i\nActividades: %s\n Altura: %.2f\n", Socios.DNI, Socios.Actividades, Socios.Altura);
			printf("Peso: %.2f\nNumero de Socio: %i\n", Socios.Peso, Socios.NroSocio);
			printf("Indicaciones medicas: %s\n", Socios.IndMedicas);
			printf("Fecha de ingreso: %02i/%02i/%04i\n", Socios.FechaIng.Dia, Socios.FechaIng.Mes, Socios.FechaIng.Anual);
			printf("Activadad: %s\n", (strcmp(Socios.Actividades, ""))? Socios.Actividades: "Ninguna");
			
			//Para ver que dia tiene las actividades
			if(Socios.FechaRutina[0].Dia != 0){
			
				printf("La fecha que tiene actividades es: \n");
				for(i = 0; Socios.FechaRutina[i].Dia != 0 && i < 10; i++)
				printf("%02i/%02i/%04i\n", Socios.FechaRutina[i].Dia, Socios.FechaRutina[i].Mes, Socios.FechaRutina[i].Anual);
			}
			pause();
			fread(&Socios, sizeof(Socios), 1, SocioArch);
		}
		fclose(SocioArch);
	}
}

void ListadoUsuariosAdmin(){
	color(30);
	struct Usuario User;
	FILE *UserArch = fopen("./Usuarios.dat", "rb");
	if(UserArch == NULL){
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Usuarios.dat\"\n");
		pause();
		fclose(UserArch);
		color(07);
		exit(EXIT_FAILURE);
	}
	else{
		fread(&User, sizeof(User), 1, UserArch);
		while(!feof(UserArch)){
			printf("\nNombre Completo: %s\n", User.ApelYNom);
			printf("Usuario: %s\nContrasena:%i\n", User.usuario, User.contrasena);
			pause();
			fread(&User, sizeof(User), 1, UserArch);
		}
	}
}

#endif
