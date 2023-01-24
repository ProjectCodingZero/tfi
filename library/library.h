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
	char Direccion[60];
	int Celular;
	int DNI;
	char Actividades[100];
	float Altura;
	float Peso;
	int NroSocio;
	struct Fecha FechaNacimiento;
};

struct Turnos{
	int legajoEntranador;
	struct Fecha fecha;
	int nroSocio;
};
//El listado de los socios y que actividades que desarrolla
void ListadoSocios(){
	color(30);
	struct Socio Socios;
	FILE *SocioArch = fopen("../data/Socios.dat", "rb");
	if(SocioArch == NULL){
		color(46);
		printf("\nError: El archivo \"Socios.dat\" no existe\n");
		pause();
		color(07);
		exit(EXIT_FAILURE);
	}
	else{
		fread(&Socios, sizeof(Socios), 1, SocioArch);
		while(!feof(SocioArch)){
			printf("\nNombre Completo: %s\n", Socios.ApelYNom);
			printf("Direccion: %s\nCelular:%i\n", Socios.Direccion, Socios.Celular);
			printf("DNI: %i\nActividades: %s\n Altura: %.2f\n", Socios.DNI, Socios.Actividades, Socios.Altura);
			printf("Peso: %.2f\nNumero de Socio: %i\n", Socios.Peso, Socios.NroSocio);
			printf("Fecha: %02i\\%02i\\%04i\n", Socios.FechaNacimiento.Dia, Socios.FechaNacimiento.Mes, Socios.FechaNacimiento.Anual);
			pause();
		}
	}
}
//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02

#endif
