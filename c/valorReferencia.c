#include <stdio.h>

void miFuncion(int * );

int main(){
				int a=2,b=4;
				miFuncion(&a);
				printf("el numero modificado es: %d/n",a);
}


void miFuncion(int *numero){
				*numero = 100;
}