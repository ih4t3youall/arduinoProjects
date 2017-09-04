#include <stdio.h>

int main(){

				int i,j;
				int a[5][5];
				int *p[5];
				int **q;

				for(i=0;i<5;i++){
								p[i]=a[i];
				}
				q=p;

				for (i = 0 ; i <5 ; i++)
								for(j=0;j<5;j++)
												scanf("%d",&q[i][j]);

				for (i=0;i<5;i++){
								for (j=0;j<5;j++)
												printf("%7d",q[i][j]);

				}
				printf("\n");
}