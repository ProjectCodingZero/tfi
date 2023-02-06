#include <stdio.h>
#include <stdlib.h>
#include "./library/verificar.h"
#include "./library/Register.h"
#include "./library/library.h"
#include "./library/listado.h"
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
   	FILE *Arch = fopen("./UsuariosAdm.dat", "rb");
   	if(Arch == NULL)
   	{
		color(46);
		printf("\nERROR :: NO EXISTE EL ARCHIVO \"UsuariosAdm.dat\"\n");
		pause();
		fclose(Arch);
		color(07);
		exit(EXIT_FAILURE);
    }
   	//Para que inicie la seccion se hizo un menu especial
   	while(!InicioSesion)
   	{
   		printf("Bienvenido al Modulo Administracion Anonimo\n");
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
   while(true)
   {
      printf("Bienvenido al Modulo Administracion %s\n", TheUser.ApelYNom);
      printf("Las opciones son:\n");
      printf("1.- Registrar usuario de Recepcion.\n");
      printf("2.- Calcular pago al entrenador.\n");
      printf("3.- Entrenador con mayor carga horaria.\n");
      printf("4.- Cerrar la aplicacion.\n\n\n");
      printf("Ingresar una opcion: ");
      scanf("%i", &Rta);
      system("CLS");
      switch(Rta)
      {
         case 1:
         	printf("Ha ingresado a la creacion de un socio\n")
         	pause();
            CreationSocio();
            break;
         case 2:
         	printf("Ha ingresado al calculo del pago de un entrenador\n");
         	pause();
         	calcularPago();
            break;
         case 3:
         	printf("Ha ingresado a quien es el entrenador con mayor carga\n")
         	pause()
         	EntMayorCarga();
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
