//Esta libreria contiene todo lo que se comparte entre los archivos, estructuras y funciones
#ifndef library_h
#define library_h
#include <stdio.h>
#include <stdlib.h>
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
struct Fecha{
	int Dia;
	int Mes;
	int Anual;
};

struct Usuario{
	char usuario[50];
	char contrasena[50];
	char ApelYNom[60];
};

struct Entrenador{
	char ApelYNom[60];
	int Dias[6];
	int Legajo;
	char contrasena[50];
};

struct Socio{
	char ApelYNom[60];
	int Celular;
	int DNI;
	char Actividades[380];
	char IndMedicas[300];
	float Altura;
	float Peso;
	int NroSocio;
	struct Fecha FechaRutina[10];
	struct Fecha FechaIng;
};

struct Turnos{
	int legajoEntranador;
	struct Fecha fecha;
	int nroSocio;
};


//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02

#endif
