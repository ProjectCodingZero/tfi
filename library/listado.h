#ifndef listado_h
#define lsitado_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "library.h"
#define color(c); system("COLOR " #c);
#define pause(); system("PAUSE"); system("CLS");

//El listado de los socios y que actividades que desarrolla
void ListadoSocios()
{
	color(30);
	struct Socio Socios;
	FILE *SocioArch = fopen("./Socios.dat", "rb");
	
	if(SocioArch == NULL)
	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Socios.dat\"\n");
		pause();
		color(07);
		fclose(SocioArch);
		exit(EXIT_FAILURE);
	}
	else
	{
		bool Verificar = false;
		int i;
		fread(&Socios, sizeof(Socios), 1, SocioArch);
		while(!feof(SocioArch))
		{
			printf("\nNombre Completo: %s\n", Socios.ApelYNom);
			printf("Celular:%i\n", Socios.Celular);
			printf("DNI: %i\nActividades: %s\n Altura: %.2f\n", Socios.DNI, Socios.Actividades, Socios.Altura);
			printf("Peso: %.2f\nNumero de Socio: %i\n", Socios.Peso, Socios.NroSocio);
			printf("Indicaciones medicas: %s\n", Socios.IndMedicas);
			printf("Fecha de ingreso: %02i/%02i/%04i\n", Socios.FechaIng.Dia, Socios.FechaIng.Mes, Socios.FechaIng.Anual);
			printf("Actividad: %s\n", (strcmp(Socios.Actividades, ""))? Socios.Actividades: "Ninguna");
			
			//Para ver que dia tiene las actividades
			
			
			pause();
			fread(&Socios, sizeof(Socios), 1, SocioArch);
		}
		fclose(SocioArch);
		printf("Esos son todos los socios registrados\n");
		pause();
	}
}

void ListadoUsuariosAdmin(FILE *UserArch){
	rewind(UserArch);
	color(30);
	struct Usuario User;
	fread(&User, sizeof(User), 1, UserArch);
	while(!feof(UserArch))
	{
		printf("\nNombre Completo: %s\n", User.ApelYNom);
		printf("Usuario: %s\nContrasena:%i\n", User.usuario, User.contrasena);
		pause();
		fread(&User, sizeof(User), 1, UserArch);
	}
		printf("Esos son todos los usuarios registrados en el archivo\n");
		pause();
	
}

void ListadoEntrenadorAdmin(){
	color(30);
	struct Entrenador Entrenadores;
	FILE *EntrenadoresArch = fopen("./Entrenadores.dat", "rb");
	int Dia;
	if(EntrenadoresArch == NULL)
	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Entrenadores.dat\"\n");
		pause();
		fclose(EntrenadoresArch);
		color(07);
		exit(EXIT_FAILURE);
	}
	else
	{
		fread(&Entrenadores, sizeof(Entrenadores), 1, EntrenadoresArch);
		while(!feof(EntrenadoresArch)){
			printf("\nNombre Completo: %s\n", Entrenadores.ApelYNom);
			printf("Legajo: %i\n", Entrenadores.Legajo);
			printf("Los dias que trabaja:\n");
			for(Dia = 0; Dia < 7; Dia++)
			{
				switch(Dia)
				{
					case 1:
						if(Entrenadores.Dias[Dia] == 1)
							printf("Lunes\n");
						break;
					case 2:
						if(Entrenadores.Dias[Dia] == 2)
							printf("Martes\n");
						break;
					case 3:
						if(Entrenadores.Dias[Dia] == 3)
							printf("Miercoles\n");
						break;
					case 4:
						if(Entrenadores.Dias[Dia] == 4)
							printf("Jueves\n");
						break;
					case 5:
						if(Entrenadores.Dias[Dia] == 5)
							printf("Viernes\n");
						break;
					case 6:
						if(Entrenadores.Dias[Dia] == 6)
							printf("Sabado\n");
						break;
					case 7:
						if(Entrenadores.Dias[Dia] == 7)
							printf("Domingo\n");
						break;
					default:
						break;
				}
			}
			
			pause();
			fread(&Entrenadores, sizeof(Entrenadores), 1, EntrenadoresArch);
		}
		fclose(EntrenadoresArch);
		printf("Esos son todos los entrenadores registrados\n");
		pause();
	}
}
void ListadoTurnos() //Modificar
{
	color(30);
	struct Turnos Turno;
	FILE *TurnosArch = fopen("./Turnos.dat", "rn");
	int Dia;
	if(TurnosArch == NULL)
	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Turnos.dat\"\n");
		pause();
		fclose(TurnosArch);
		color(07);
		exit(EXIT_FAILURE);
	}
	else
	{
		fread(&Turno, sizeof(Turno), 1, TurnosArch);
		while(!feof(TurnosArch))
		{
			printf("Legajo Entrenador: %i\nNumero de socio:%i\n", Turno.legajoEntrenador, Turno.nroSocio);
			printf("Dia: ");
			switch(Turno.Dia)
			{
					case 1:
						printf("Lunes\n");
						break;
					case 2:
						printf("Martes\n");
						break;
					case 3:
						printf("Miercoles\n");
						break;
					case 4:
						printf("Jueves\n");
						break;
					case 5:
						printf("Viernes\n");
						break;
					case 6:
						printf("Sabado\n");
						break;
					case 7:
						printf("Domingo\n");
						break;
					default:
						break;
			}
		pause();
		fread(&Turno, sizeof(Turno), 1, TurnosArch);
		}
	}
	fclose(TurnosArch);
	printf("Esos son todos los turnos registrados\n");
	pause();
}

#endif
