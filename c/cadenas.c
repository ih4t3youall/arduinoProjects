#include <stdio.h>


void hacerAlgoConUnaCadena(char []);

int main(){

				char cadena[]="cadena1";
				hacerAlgoConUnaCadena(cadena);
}

void hacerAlgoConUnaCadena(char cadena[]){

				char *puntero =cadena; 
				/*	while(*puntero){
						printf("%c\n",*puntero+1);
						puntero++;
						}
				 */
				for(int i=0;i<100;i++){
								printf("%c\n",*puntero);
								puntero++;
				}

}