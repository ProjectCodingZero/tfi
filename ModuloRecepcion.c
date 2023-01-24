#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);
//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02
void menu()
{
   struct Usuario TheUser;
   system("CLS");
   color(30);
   int Rta;
      	struct Entrenador ElEntrenador;
   	bool InicioSesion = false;
   	char Intento;
   	system("CLS");
   	color(30);
   	int Rta;
   	//Para que inicie la seccion se hizo un menu especial
   	if(!InicioSesion)
   	{
   		while(!InicioSesion)
   		{
   		printf("Bienvenido al Modulo Recepción Anonimo\n");
   		printf("Ingresar una opcion: \n\n");
   		printf("Las opciones son:\n");
     	printf("1.- Cambiar de seccion.\n");
     	printf("2.- Cerrar la aplicacion.\n\n\n");
      	scanf("%i", &Rta);
      	printf("Ingresar una opcion: ");
      	switch(Rta)
      		{
        		case 1:
            		printf("\nBienvenido la inicio de seccion\n");
            		pause();
            		printf("Ingrese la contrasena: ");
            		gets(ElEntrenador.contrasena);
            		InicioSesion = loginEntrenador(ElEntrenador.contrasena, ElEntrenador.ApelYNom);
            		if(InicioSesion)
            		{
               			printf("Bienvenido %s\n", ElEntrenador.ApelYNom);
               			pause();
					}
            		break;
            	case 2:
         			printf("\nA continuacion se cerrara la aplicacion\n");
         			pause();
         			exit(0);
         			break;
        		default:
         			color(46);
					printf("\nError: La opcion ingresada no existe\n");
					pause();
					color(30);
					break;
        	}
   		}
   	}
	//Si ha iniciado seccion
   while(true)
   {
      printf("Bienvenido al Recepción Gym\n");
      printf("Las opciones son:\n");
      printf("1.- Iniciar Sesión.\n");
      printf("2.- Registrar Socios.\n");
      printf("3.- Registrar Actividades de Socios.\n")
      printf("4.- Listados de Socios.\n");
      printf("5.- Listado de fechas de pagos.\n");
      printf("6.- Cerrar la aplicación.\n\n");
      printf("Ingresar una opcion: ");
      scanf("%i", &Rta);
      switch(Rta)
      {
         case 1:
            
         case 2:
            
      }
   }
}
