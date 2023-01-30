#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./library/Register.h"
#include "./library/library.h"
#include "./library/listado.h"
#include "./library/verificar.h"
#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);
//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02
void main()
{
   	struct Usuario Usuario;
   	bool InicioSesion = false;
   	system("CLS");
   	color(30);
   	int Rta;
   	FILE *Arch = fopen("./UsuariosGym.dat", "rb");
   	if(Arch == NULL)
   	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"UsuariosGym.dat\"\n");
		pause();
		fclose(Arch);
		color(07);
		exit(EXIT_FAILURE);
    }
   	//Para que inicie la seccion se hizo un menu especial
   	while(!InicioSesion)
   	{
   		printf("Bienvenido al Modulo Gym Anonimo\n");
   		printf("Ingresar una opcion: \n\n");
   		printf("Las opciones son:\n");
     	printf("1.- Iniciar Seccion.\n");
     	printf("2.- Cerrar la aplicacion.\n\n\n");
      	
      	printf("Ingresar una opcion: ");
      	scanf("%i", &Rta);
      	switch(Rta)
      	{
        	case 1:
            	printf("\nBienvenido la inicio de seccion\n");
            	pause();
            	printf("Ingrese el nombre: ");
            	_flushall();
            	gets(Usuario.usuario);
            	_flushall();
            	printf("Ingrese la contrasena: ");
            	_flushall();
            	gets(Usuario.contrasena);
            	_flushall();
            	InicioSesion = loginUser(Usuario.usuario, Usuario.contrasena, Usuario.ApelYNom, Arch);
            	if(InicioSesion)
            	{
               		printf("Bienvenido %s\n", Usuario.ApelYNom);
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
   	fclose(Arch);
	//Si ha iniciado seccion
   	while(true)
   	{
		printf("Bienvenido al Modulo Gym %s", Usuario.ApelYNom);
      	printf("Las opciones son:\n\n");
     	printf("1.- Visualizar listado de Socios y actividad que desarrolla.\n");
      	printf("2.- Registrar rutinas de gimnasia.\n");
      	printf("3.- Leer las rutinas de gimnasia")
      	printf("4.- Cerrar la aplicacion.\n\n\n");
      	printf("Ingresar una opcion: ");
		scanf("%i", &Rta);
      	switch(Rta)
      	{
         case 1:
         	printf("\nHa ingresado al listado al listado de socios\n");
         	pause();
         	ListadoSocios();
         	break;
         case 2:
         	printf("\nHa ingresado a al registrar rutinas\n");
         	RegistrarGimnasia();
         	break;
         case 3:
         	printf("\nHa ingresa a leer la rutina de gimnasia");
         	leerRutina();
         	break;
         case 4:
         	printf("\nHa continuacion se cerrara la aplicacion\n");
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

