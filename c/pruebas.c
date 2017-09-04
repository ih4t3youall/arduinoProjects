#include <stdio.h>


int main(){
int *px, x=7, y=0;
px = &x;
y = *px;
printf("direccion de memoria = %d, dato = %d\n",&x,x);
printf("direccion de memoria = %d, dato = %d\n",px,*px);
printf("lo que yo quiero probar : impresion de px %d impresion de &px %d\n",px,&px);
}