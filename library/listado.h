#ifndef listado_h
#define lsitado_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "library.h"
#define color(c); system("COLOR " #c);
#define pause(); system("PAUSE"); system("CLS");

//El listado de los socios y que actividades que desarrolla
void ListadoSocios()
{
	system("CLS");
	color(30);
	struct Socio Socios;
	FILE *SocioArch = fopen("./Socios.dat", "rb");
	struct Turnos ElTurno;
	FILE *TurnosArch = fopen("./Turnos.dat", "rb");
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
			printf("DNI: %i\n Altura: %.2f\n", Socios.DNI, Socios.Altura);
			printf("Peso: %.2f\nNumero de Socio: %i\n", Socios.Peso, Socios.NroSocio);
			printf("Indicaciones medicas: %s\n", Socios.IndMedicas);
			printf("Fecha de ingreso: %02i/%02i/%04i\n", Socios.FechaIng.Dia, Socios.FechaIng.Mes, Socios.FechaIng.Anual);
			//Para ver que dia tiene las actividades
			if(TurnosArch != NULL)
			{
				//Si el archivo existe diga los horarios del entrenador
				printf("Dia/s: \n");
				rewind(TurnosArch);
				fread(&ElTurno, sizeof(ElTurno), 1, TurnosArch);
				while(!feof(TurnosArch))
				{
					if(ElTurno.nroSocio == Socios.NroSocio)
					{
						switch(ElTurno.Dia)
						{
							case 1:
								printf("Lunes: ");
								break;
							case 2:
								printf("Martes: ");
								break;
							case 3:
								printf("Miercoles: ");
								break;
							case 4:
								printf("Jueves: ");
								break;
							case 5:
								printf("Viernes: ");
								break;
							case 6:
								printf("Sabado: ");
								break;
							case 7:
								printf("Domingo: ");
								break;
							default:
								break;
						}
						if(1 <= ElTurno.Dia && ElTurno.Dia <= 7)
						{
							printf("%02i:00 ~ %02i:00\n", ElTurno.HoraInicial, ElTurno.HoraInicial+2);
							printf("Actividad: ");
							switch(ElTurno.Actividad)
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
						}
					}
					fread(&ElTurno, sizeof(ElTurno), 1, TurnosArch);
				}
			}
			pause();
			fread(&Socios, sizeof(Socios), 1, SocioArch);
		}
		fclose(SocioArch);
		fclose(TurnosArch);
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
	system("CLS");
	color(30);
	struct Entrenador Entrenadores;
	struct Turnos ElTurno;
	FILE *EntrenadoresArch = fopen("./Entrenadores.dat", "rb");
	FILE *TurnosArch = fopen("./Turnos.dat", "rb");
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
			printf("Carga Horaria: %i\n", Entrenadores.cargaHoraria);
			if(TurnosArch != NULL)
			{
				//Si el archivo existe diga los horarios del entrenador
				printf("Dia/s: \n");
				rewind(TurnosArch);
				fread(&ElTurno, sizeof(ElTurno), 1, TurnosArch);
				while(!feof(TurnosArch))
				{
					if(ElTurno.legajoEntrenador == Entrenadores.Legajo)
					{
						switch(ElTurno.Dia)
						{
							case 1:
								printf("Lunes: ");
								break;
							case 2:
								printf("Martes: ");
								break;
							case 3:
								printf("Miercoles: ");
								break;
							case 4:
								printf("Jueves: ");
								break;
							case 5:
								printf("Viernes: ");
								break;
							case 6:
								printf("Sabado: ");
								break;
							case 7:
								printf("Domingo: ");
								break;
							default:
								break;
						}
						if(1 <= ElTurno.Dia && ElTurno.Dia <= 7)
						{
							printf("%02i:00 ~ %02i:00\n", ElTurno.HoraInicial, ElTurno.HoraInicial+2);
							printf("Actividad: ");
							switch(ElTurno.Actividad)
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
						}
					}
					fread(&ElTurno, sizeof(ElTurno), 1, TurnosArch);
				}
			}
			pause();
			fread(&Entrenadores, sizeof(Entrenadores), 1, EntrenadoresArch);
		}
		fclose(EntrenadoresArch);
		fclose(TurnosArch);
		printf("Esos son todos los entrenadores registrados\n");
		pause();
	}
}
void ListadoTurnos(FILE *Arch)
{
	system("CLS");
	color(30);
	struct Turnos Turno;
	FILE *TurnosArch = fopen("./Turnos.dat", "rb");
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
			printf("Actividad: ");
			switch(Turno.Actividad)
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
			printf("Horario: %02i:00 ~ %02i:00\n", Turno.HoraInicial, Turno.HoraInicial+2)
			pause();
			fread(&Turno, sizeof(Turno), 1, TurnosArch);
		}
	}
	fclose(TurnosArch);
	printf("Esos son todos los turnos registrados\n");
	pause();
}

void ListadoPorAct(int Actividad)
{	
	int horarios[] = {8, 10, 13, 15, 17, 19, 21};
	int horario;
	int legajoEntrenador;
	color(30);
	struct Turnos Turno;
	FILE *TurnosArch = fopen("./Turnos.dat", "rb");
	int dia;
	
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
		//Se ve cual es la actividad
		system("CLS");
		printf("Listado de actividad de: ");
		switch(Actividad)
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
		for(dia = 1; dia <= 7; dia++)
		{
			printf("Dia: ");
			switch(dia)
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
			for(horario = 0; horario < 7; horario++)
			{
				printf("Horario: %02i:00 ~ %02i:00\n", horarios[horario], horarios[horario]+2);
				fread(&Turno, sizeof(Turno), 1, TurnosArch);
				while(!feof(TurnosArch))
				{
					//Se comprueba que comprueba que la actividad sea correcta
					//Dia va desde lunes a domingo
					//El horario va desde AM a PM
					if(Turno.Dia == dia && Turno.Actividad == Actividad && Turno.HoraInicial == horarios[horario])
					{
						printf("Numero de socio: %i\n", Turno.nroSocio);
						legajoEntrenador = Turno.legajoEntrenador;
					}
					fread(&Turno, sizeof(Turno), 1, TurnosArch);
				}
				printf("Legajo del Entrenador: %i\n", legajoEntrenador);
				pause();
				rewind(TurnosArch);
			}
		}
	}
}
#endif
