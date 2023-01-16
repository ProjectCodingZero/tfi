#include <stdio.h>
#include <stdlib.h>

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
      printf('2.- Registrar usuario de Recepción.\n');
      printf('3.- Calcular pago al entrenador.\n')
      printf('4.- Entrenador con mayor carga horaria.\n');
      printf('5.- Cerrar la aplicación.\n\n');
      printf('Ingresar una opcion: ');
      scanf("%i", &Rta);
      switch(Rta)
      {
         case 1:
            
         case 2:
            
      }
   }
}