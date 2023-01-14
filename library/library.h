//Esta libreria contiene todo lo que se comparte entre los archivos, estructuras y funciones
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

struct Calendario{
	int Dia[6]; 
};
