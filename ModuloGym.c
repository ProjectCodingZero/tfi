#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./library/login.h"
#include "./library/listado.h"
#include "./library/register.h"
#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);
//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02
void main()
{
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
   		printf("Bienvenido al Modulo Gym Anonimo\n");
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
		printf("Bienvenido al Modulo Gym %s", ElEntrenador.ApelYNom);
      	printf("Las opciones son:\n\n");
     	printf("1.- Cambiar de usuario.\n");
     	printf("2.- Visualizar listado de Socios y actividad que desarrolla.\n");
      	printf("3.- Registrar rutinas de gimnasia.\n");
      	printf("4.- Cerrar la aplicacion.\n\n\n");
      	printf("Ingresar una opcion: ");
		scanf("%i", &Rta);
      	switch(Rta)
      	{
        case 1:
            printf("\nBienvenido al cambio de usuario\n");
            pause();
            printf("Ingrese la contrasena: ");
            _flushall();
            gets(ElEntrenador.contrasena);
            InicioSesion = false;
            InicioSesion = loginEntrenador(ElEntrenador.contrasena, ElEntrenador.ApelYNom);
            
            if(InicioSesion){
               printf("\nBienvenido %s\n", ElEntrenador.ApelYNom);
               pause();
            }
            break;
         case 2:
         	printf("\nHa ingresado al listado al listado de socios\n");
         	pause();
         	ListadoSocios();
         	break;
         case 3:
         	printf("\nA ingresado a al registrar rutinas\n");
         	pause();
         	RegistrarTurnos();
         	break;
         case 4:
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

