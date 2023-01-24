#include <stdio.h>
#include <stdlib.h>
#include "./library/login.h"
#include "./library/library.h"
#include "./library/register.h"
#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);
//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02
void main()
{
   struct Usuario TheUser;
   char Intento;
   system("CLS");
   color(30);
   int Rta;
   while(true)
   {
      printf("Bienvenido al Modulo Gym\n");
      printf("Las opciones son:\n");
      printf("1.- Iniciar Sesión.\n");
      printf("2.- Visualizar listado de Socios y actividad que desarrolla.\n");
      printf("3.- Registrar rutinas de gimnasia.\n");
      printf("4.- Cerrar la aplicacion.\n\n\n");
      printf("Ingresar una opcion: ");
      scanf("%i", &Rta);
      switch(Rta)
      {
         case 1:
            printf("\nBienvenido la inicio de seccion\n");
            pause();
            printf("Ingrese el usuario: ");
            _flushall();
            gets(TheUser.usuario);
            _flushall();
            gets(TheUser.contrasena);
            if(loginUser(TheUser.usuario, TheUser.contrasena, TheUser.ApelYNom)){
               printf("Bienvenido %s", TheUser.ApelYNom);
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
         	RegistrarRutinas();
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

