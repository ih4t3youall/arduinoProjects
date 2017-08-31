#include <stdio.h>
#define FILAS 2
#define COLS 3
void copiarMatriz(void *dest,void*origin,int);

int main (){

				int m1[FILAS][COLS]={24,30,15,45,34,7};
				int m2[FILAS][COLS],f,c;
				copiarMatriz(m2,m1,sizeof(m1));

				for(f =0 ;f<FILAS;f++){
								for(c=0;c<COLS;c++){
												printf("%d ",m2[f][c]);
								}
								printf("\n");
				}
				printf("imprimo las posiciones de memoria de los punteros\n");
				m2[1][1]=0;
				for(f =0 ;f<FILAS;f++){
								for(c=0;c<COLS;c++){
												printf("%d ",m1[f][c]);
								}
								printf("\n");
				}
/*
				for(int i = 0 ; i < sizeof(m1);i++){
								printf("imprimo posiciones de m1: %d \n",&m1[i]);
				}
				for(int i = 0 ; i < sizeof(m2);i++){
								printf("imprimo posiciones de m2: %d \n",&m2[i]);
				}
*/


}

void copiarMatriz(void *dest,void*origin,int n){

				char * destino = dest;
				char * origen =origin;
				for(int i =0; i<n;i++){
								destino[i] =origen[i];
								printf("copiando %d a %d \n",&origen,&destino);

				} 

				printf("iprimo lo que tengo que imporimir\n");
				for(int i = 0 ; i< 5 ; i++){
				printf("%d\n",origen[i]);
				printf("%d\n",destino[i]);
				printf("%d\n",*(origen+i));
				printf("%d\n",*(destino+i));
}
				printf("fin iprimo lo que tengo que imporimir\n");

}
