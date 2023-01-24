#ifndef ModuloGym_h
#define ModuloGym_h

#include <stdio.h>
#include <stdlib.h>
#
#define pause(); system("PAUSE"); system("CLS");
#define color(c); system("COLOR " #c);
//El color normal de la pantalla es 30
//El color error es 46
//El color de salida por error es 07
//El color de function exitosa es 02
void menu()
{
   struct Usuario TheUser;
   char Intento;
   system("CLS");
   color(30);
   int Rta;
   while(true)
   {
      printf('Bienvenido al Modulo Gym\n');
      printf('Las opciones son:\n');
      printf('1.- Iniciar Sesión.\n');
      printf('2.- Visualizar listado de Socios y actividad que desarrolla.\n');
      printf('3.- Registrar rutinas de gimnasia.\n')
      printf('4.- Cerrar la aplicación.\n\n');
      printf('Ingresar una opcion: ');
      scanf("%i", &Rta);
      switch(Rta)
      {
         case 1:
            printf('\nBienvenido la inicio de seccion\n');
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
            else
            {
               printf('\nSi quiere volver a intentar, vuelva a elejir la opcion 1\n');
               pause();
            }
            break;
         case 2:
            
      }
   }
}

#endif
