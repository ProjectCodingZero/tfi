//Esta libreria contiene todo lo que se comparte entre los archivos, estructuras y funciones
#ifndef library_h
#define library_h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
	int Legajo;
	int cargaHoraria;
};

struct Socio
{
	char ApelYNom[60];
	int Celular;
	int DNI;
	char IndMedicas[300];
	float Altura;
	float Peso;
	int NroSocio;
	struct Fecha FechaIng;
};

struct Turnos
{
	int legajoEntrenador;
	int nroSocio;
	int Dia;
	int HoraInicial;
	int Actividad;
};


void EntMayorCarga()
{
	struct Entrenador ElEntrenador;
	int MayorCargaHorario;
	int legajo;
	char ApelYNom[60];
	FILE *EntrenadoresArch = fopen("./Entrenadores.dat", "rb");
	
	if(EntrenadoresArch == NULL)
	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"Entrenadores.dat\"\n");
		pause();
		color(07);
		exit(EXIT_FAILURE);
	}
	else
	{
		//Si existe se verifica que el legajo no sea repetido
		//Se hace un ciclo para ingresar un numero de socio no repetido
		
		fread(&ElEntrenador, sizeof(ElEntrenador), 1, EntrenadoresArch);
		while(!feof(EntrenadoresArch))
		{
			if(ElEntrenador.cargaHoraria > MayorCargaHorario)
			{
				MayorCargaHorario = ElEntrenador.cargaHoraria;
				legajo = ElEntrenador.Legajo;
				strcpy(ApelYNom, ElEntrenador.ApelYNom);
				fread(&ElEntrenador, sizeof(ElEntrenador), 1, EntrenadoresArch);
			}
		}
	}
	printf("El entrenador con mayor carga horaria es:\n");
	printf("Nombre: %s\n Legajo: %i\n", ApelYNom, legajo);
	printf("Carga Horaria: %i\n", MayorCargaHorario);
}

void FechaPago()
{
	system("CLS");
	bool verificar = false;
	color(30);
	int NumeroSocio;
	struct Socio Socios;
	FILE *SocioArch = fopen("./Socios.dat", "rb");
	struct Turnos ElTurno;
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
		printf("Ingresar el numero de socio que desea buscar\n");
		scanf("%i", &NumeroSocio);
		fread(&Socios, sizeof(Socios), 1, SocioArch);
		while(!feof(SocioArch))
		{
			if(NumeroSocio == Socios.NroSocio)
			{
				printf("Nombre de socio: %s", Socios.ApelYNom);
				printf("Su fecha de pago es %02i/%02i\n", Socios.FechaIng.Dia, Socios.FechaIng.Mes);
				verificar = true;
			}
			
		}
		if(!verificar)
		{
			color(46);
			printf("\nERROR: Numero de socio no encontrado\n");
			pause();
			color(30);
		}
		fclose(SocioArch);
	}
	
}

void calcularPago()
{
	system("CLS");
	color(30);
	struct Turnos Turno;
	int Pago = 0;
	int LegajoEntrenador;
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
		
		printf("Ingrese el legajo del entrenador\n");
		scanf("%i", &LegajoEntrenador);
		fread(&Turno, sizeof(Turno), 1, TurnosArch);
		while(!feof(TurnosArch))
		{
			if(LegajoEntrenador == Turno.legajoEntrenador)
			{
				Pago += 500;
			}
			fread(&Turno, sizeof(Turno), 1, TurnosArch);
		}
		system("CLS");
		if(Pago == 0)
		{
			printf("El entrenador no realiza ninguna actividad\n");
		}
		else
		{
			printf("Legajo: %i", LegajoEntrenador);
			printf("Su pago: %i.00$", Pago);
		}
		pause();
	}
}

//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02

#endif
