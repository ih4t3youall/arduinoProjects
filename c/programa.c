#include <stdio.h>
#include "funciones.h";

typedef unsigned long ulong;

typedef struct
{
char nombre[40];
char direccion[40];
long telefono[20];
} persona;


enum colores
{
				rojo,verde,amarillo

};

main(){

persona per;
puts("ingrese nombre");
gets(per.nombre);
puts("ingrese direccion");
gets(per.direccion);

puts("imprimiendo");

puts(per.nombre);
puts(per.direccion);
/*
				char texto[80];
				ulong numero;
				numero = 123;
				ulong numero2;
				numero2 = dameNumero();
				printf("%d,nose pero , %d\n",numero,numero2);
				gets(texto);
				puts("************");
				puts(texto);
				goto migraciones;

migraciones:
				printf("no anduvo tu wea");

				printf("si anduvo tu wea fascista");
*/

}
