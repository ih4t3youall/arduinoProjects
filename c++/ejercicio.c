#include <stdio.h>

int calcularValidos(int mat[5][5]);

int mat[5][5]={
				{6,0,0,0,4},
				{0,5,0,0,2},
				{2,0,0,0,0},
				{0,0,7,0,0},
				{0,0,0,8,0},
};


main(){

int validos = calcularValidos(mat);

int array[validos*3];
int contador;

				for (int i=0 ; i<5 ;i++){

								for (int j=0 ;j<5;j++){

											if(mat[i][j] != 0){

													array[contador++]=i;
													array[contador++]=j;
													array[contador++]=mat[i][j];
															
											}
								}

				}
for(int r ; r< (validos*3);r++){

printf("%d",array[r]);

}



}

int calcularValidos(int matr[5][5]){

int cont=0;

				for (int i=0 ; i<5 ;i++){

								for (int j=0 ;j<5;j++){

											if(mat[i][j] != 0){
													cont++;		
											}
								}

				}
return cont;


}