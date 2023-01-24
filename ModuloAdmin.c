#include <stdio.h>
#include <stdbool.h>
#include "./library/login.h"
#include "./library/listado.h"
#include "./library/register.h"
#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);

void main()
{
   system("CLS");
   color(30);
   int Rta;
   printf("PRECACUION:: Este modulo solo debera ser utilizado para ver el listado y/o creacion los siguientes\n");
   printf("USUARIOS, SOCIOS, ENTRENADORES Y/O TURNOS\n");
   pause();
   while(true)
   {
      printf("Bienvenido al Modulo Admin\n");

      printf("Las opciones son:\n");
      printf("1.- Registrar un usuario.\n");
      printf("2.- Registrar un socio.\n");
      printf("3.- Registrar un entrenador.\n");
      printf("4.- Registrar un turno.\n");
      printf("5.- Listar usuarios registrados\n");
      printf("6.- Listar socios registrados\n");
      printf("7.- Listar entrenadores registrados\n");
      printf("8.- Listar turnos\n");
      printf("9.- Cerrar la aplicación.\n\n\n");
      printf("Ingresar una opcion: ");
      scanf("%i", &Rta);
      switch(Rta)
      {
         case 1:
			printf("Bienvenido al registro de usuario nuevo\n");
			pause();
			registerUser();
			break;
         case 2:
         	printf("Bienvenido al registro de socio nuevo\n");
         	pause();
         	CreationSocio();
         	break;
         case 3:
         	printf("Bienvenido al registro de entrenador nuevo\n");
         	pause();
         	//---
         	break;
         case 4:
         	printf("Bienvenido al registro de entrenador nuevo\n");
         	pause();
         	RegistrarTurnos();
         	break;
         case 5: 
         	printf("Bienvenido al listado de los usuarios\n");
         	pause();
         	ListadoUsuariosAdmin();
         	break;
         case 6:
            printf("Bienvenido al listado de los socios\n");
         	pause();
         	ListadoSocios();
         	break;
         case 7:
         	//---
         	break;
         	
      }
   }
}
