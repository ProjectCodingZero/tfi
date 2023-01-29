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
   	struct Usuario TheUser;
   	bool InicioSesion = false;
   	system("CLS");
   	color(30);
   	int Rta;
   	int actividad;
   	FILE *Arch = fopen("./UsuariosRec.dat", "rb");
   	if(Arch == NULL)
   	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"UsuariosRec.dat\"\n");
		pause();
		fclose(Arch);
		color(07);
		exit(EXIT_FAILURE);
    }
   	//Para que inicie la seccion se hizo un menu especial
   	if(!InicioSesion)
   	{
   		while(!InicioSesion)
   		{
   		printf("Bienvenido al Modulo Recepcion Anonimo\n");
   		printf("Ingresar una opcion: \n\n");
   		printf("Las opciones son:\n");
     	printf("1.- Iniciar Seccion.\n");
     	printf("2.- Cerrar la aplicacion.\n\n\n");
      	scanf("%i", &Rta);
      	printf("Ingresar una opcion: ");
      	switch(Rta)
      		{
        		case 1:
            		printf("\nBienvenido la inicio de seccion\n");
            		pause();
            		printf("Ingrese el nombre: ");
            		_flushall();
            		gets(TheUser.usuario);
            		_flushall();
            		printf("Ingrese la contrasena: ");
            		_flushall();
            		gets(TheUser.contrasena);
            		_flushall();
            		InicioSesion = loginUser(TheUser.usuario, TheUser.contrasena, TheUser.ApelYNom, Arch);
            		if(InicioSesion)
            		{
               			printf("Bienvenido %s\n", TheUser.ApelYNom);
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
   	fclose(Arch);
	//Si ha iniciado seccion
   while(true)
   {
		system("CLS");
    	printf("Bienvenido al Modulo Recepción %s\n", TheUser.ApelYNom);
      	printf("Las opciones son:\n");
      	printf("1.- Registrar Socios.\n");
      	printf("2.- Registrar Actividades de Socios.\n");
      	printf("3.- Listados de Socios.\n");
      	printf("4.- Listado de fechas de pagos.\n");
      	printf("5.- Listado de turnos por actividad\n");
      	printf("5.- Cerrar la aplicación.\n\n");
      	printf("Ingresar una opcion: ");
      	scanf("%i", &Rta);
      	switch(Rta)
      	{
         case 1:
         	printf("Ha ingresado a la creacion de socio\n");
         	pause();
            CreationSocio();
            break;
         case 2:
            printf("Ha ingresado al registro de actividades de un socio\n");
         	pause();
         	Arch = fopen("Turnos.dat", "a+b");
         	RegistrarTurnos(Arch);
         	fclose(Arch);
         	break;
         case 3:
         	printf("Ha ingresado al listado de socios\n");
         	pause();
         	ListadoSocios();
         	break;
         case 4:
        	printf("Ha ingresado a fechas de pago\n");
         	pause();
         	FechaPago();
         	break;
         case 5:
         	printf("Ha ingresado al listado por actividad\n");
         	printf("Ingrese la actividad que desea buscar\n");
         	printf("1 = Zumba\n2 = Spining\n3 = Pilate\n");
         	scanf("%i", &actividad);
         	if(1 <= actividad && actividad <= 3)
         		ListadoPorAct(actividad);
         	else
         	{
         		color(46);
				printf("\nError: La opcion ingresada no existe\n");
				pause();
				color(30);
           	 	break;
         	}
         case 6:
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
