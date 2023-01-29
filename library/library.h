//Esta libreria contiene todo lo que se comparte entre los archivos, estructuras y funciones
#ifndef library_h
#define library_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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


//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02
struct Fecha
{
	int Dia;
	int Mes;
	int Anual;
};

struct Usuario
{
	char ApelYNom[60];
	char usuario[50];
	char contrasena[50];
	
};

struct Entrenador
{
	char ApelYNom[60];
	int Dias[6];
	int Legajo;
	int cargaHoraria;
};

struct Socio
{
	char ApelYNom[60];
	int Celular;
	int DNI;
	char Actividades[380];
	char IndMedicas[300];
	float Altura;
	float Peso;
	int NroSocio;
	int Dias[6];
	struct Fecha FechaIng;
};

struct Turnos
{
	int legajoEntrenador;
	int nroSocio;
	int Dia;
	int HoraInicial;
};

bool RegistrarActiviades()
{
	int Si;
	bool Valido = false;
	struct Socio ElSocio;
	struct Socio OldSocio;
	FILE *SociosArch = fopen("Socios.dat", "rb");
	int NroSocio;
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
		while(true)
		{
			printf("* El numero del socio tiene que estar registrado\n");
			printf("Ingresar el numero de socio: ");
			scanf("%i", &NroSocio);
			rewind(SociosArch);
			fread(&ElSocio, sizeof(ElSocio), 1, SociosArch);
			while(!feof(SociosArch))
			{
				if(ElSocio.NroSocio == NroSocio)
				{
					printf("El numero de socio corresponde a %s\n", ElSocio.ApelYNom);
					pause();
					Valido = true;
					break;
				}
				fread(&ElSocio, sizeof(ElSocio), 1, SociosArch);
			}
			if(!Valido)
			{
				color(46);
				printf("Error: No se encontre el numero de socio ingresado\n");
				printf("Numero de socio: %i\n", NroSocio);
				pause();
				color(30);
				printf("Quiere continuar? Si = 1// No != 1\n");
				pause();
				scanf("%i", &Si);
				if(Si == 1)
					printf("");
				else
					return false;
			}
			else
				break;
		}
	}
	printf("Ingresar las actividades del socio %s\n", ElSocio.ApelYNom);
	_flushall();
	gets(ElSocio.Actividades);
	_flushall();
	FILE *SociosArchTemp = fopen("SociosTemp.dat", "wb");
	rewind(SociosArch);
	fread(&OldSocio, sizeof(OldSocio), 1, SociosArch);
	while(!feof(SociosArch))
	{
		if(OldSocio.NroSocio != ElSocio.NroSocio)
			fwrite(&OldSocio, sizeof(OldSocio), 1, SociosArchTemp);
		else
			fwrite(&ElSocio, sizeof(ElSocio), 1, SociosArchTemp);
		fread(&OldSocio, sizeof(OldSocio), 1, SociosArch);
	}
	remove("Socios.dat");
	rename("Socios.dat", "SociosTemp.dat");
	printf("La actividad fue registrada exitosamente\n");
	pause();
	return true;
}

//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02

#endif
