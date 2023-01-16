//Esta libreria contiene todo lo que se comparte entre los archivos, estructuras y funciones
#ifndef library_h
#define library_h
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
	char contrasena[10];
};

struct Socio{
	char ApelYNom[60];
	char Direccion[60];
	int Celular;
	int DNI;
	char IndicacionesMedicas[60];
	float Altura;
	float Peso;
	int NroSocio;
	struct Fecha FechaNacimiento;
	struct Fecha FechaIngreso;
	int Dia[6];
};

#endif