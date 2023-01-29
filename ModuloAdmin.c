#include <stdio.h>
#include <stdbool.h>
#include "./library/Login.h"
#include "./library/Register.h"
#include "./library/library.h"
#include "./library/listado.h"
#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);

void main()
{
	FILE *Arch;
   	system("CLS");
   	int Rta;
   	color(73);
   	printf("PRECACUCION: Este modulo solo debera ser utilizado para ver el listado y/o creacion los siguientes\n");
   	printf("USUARIOS, SOCIOS, ENTRENADORES Y/O TURNOS\n");
   	pause();
   	color(30);
   	while(true)
   	{
      printf("Bienvenido al Modulo Admin\n");

      printf("Las opciones son:\n");
      printf("1.- Registrar un usuario(Recepcion).\n");
      printf("2.- Registrar un usuario(Administracion).\n");
      printf("3.- Registrar un usuario(Gym).\n");
      printf("4.- Registrar un socio.\n");
      printf("5.- Registrar un entrenador.\n");
      printf("6.- Registrar un turno.\n");
      printf("7.- Listar usuarios(Recepcion) registrados.\n");
      printf("8.- Listar usuarios(Administracion) registrados.\n");
      printf("9.- Listar usuarios(Gym) registrados.\n");
      printf("10.- Listar socios registrados.\n");
      printf("11.- Listar entrenadores registrados.\n");
      printf("12.- Listar turnos registrados.\n");
      printf("13.- Cerrar la aplicación.\n\n\n");
      printf("Ingresar una opcion: ");
      scanf("%i", &Rta);
      switch(Rta)
      {
        case 1:
			printf("Bienvenido al registro de usuario nuevo(Recepcion)\n");
			pause();
			Arch = fopen("./UsuariosRec.dat", "a+b");
			registerUser(Arch);
			fclose(Arch);
			break;
		case 2:
			printf("Bienvenido al registro de usuario nuevo(Administracion)\n");
			pause();
			Arch = fopen("./UsuariosAdm.dat", "a+b");
			registerUser(Arch);
			fclose(Arch);
			break;
		case 3:
			printf("Bienvenido al registro de usuario nuevo(Gym)\n");
			pause();
			Arch = fopen("./UsuariosGym.dat", "a+b");
			registerUser(Arch);
			fclose(Arch);
			break;
        case 4:
         	printf("Bienvenido al registro de socio nuevo\n");
         	pause();
         	CreationSocio();
         	break;
        case 5:
         	printf("Bienvenido al registro de entrenador nuevo\n");
         	pause();
         	RegistrarEntrenador();
         	break;
         case 6:
         	printf("Bienvenido al registro de entrenador nuevo\n");
         	pause();
         	Arch = fopen("Turnos.dat", "a+b");
         	RegistrarTurnos();
         	fclose(Arch);
         	break;
         case 7: 
         	printf("Bienvenido al listado de los usuarios(Recepcion)\n");
         	Arch = fopen("./UsuariosRec.dat", "rb");
         	pause();
         	if(Arch == NULL)
         	{
         		color(46);
				printf("\nERROR :: NO EXISTE EL ARCHIVO \"UsuariosRec.dat\"\n");
				//ss
				pause();
				fclose(Arch);
				color(07);
				exit(EXIT_FAILURE);
         	}
         	else
         	{
         		ListadoUsuariosAdmin(Arch);
         	}
         	break;
         case 8:
         	printf("Bienvenido al listado de los usuarios(Administracion)\n");
         	Arch = fopen("./UsuariosAdm.dat", "rb");
         	pause();
         	if(Arch == NULL)
         	{
         		color(46);
				printf("\nERROR :: NO EXISTE EL ARCHIVO \"UsuariosAdm.dat\"\n");
				pause();
				fclose(Arch);
				color(07);
				exit(EXIT_FAILURE);
         	}
         	else
         	{
         		ListadoUsuariosAdmin(Arch);
         	}
         case 9:
         	printf("Bienvenido al listado de los usuarios(Gym)\n");
         	Arch = fopen("./UsuariosGym.dat", "rb");
         	pause();
         	if(Arch == NULL)
         	{
         		color(46);
				printf("\nERROR :: NO EXISTE EL ARCHIVO \"UsuariosGym.dat\"\n");
				pause();
				fclose(Arch);
				color(07);
				exit(EXIT_FAILURE);
         	}
         	else
         	{
         		ListadoUsuariosAdmin(Arch);
         	}
         case 10:
            printf("Bienvenido al listado de los socios\n");
         	pause();
         	ListadoSocios();
         	break;
         case 11:
         	printf("Bienvenido al listado de los entrenadores\n");
         	ListadoEntrenadorAdmin();
         	break;
         case 12:
          	printf("Bienvenido al listado de los turnos\n");
         	ListadoTurnos();
         	break;
         case 13:
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
