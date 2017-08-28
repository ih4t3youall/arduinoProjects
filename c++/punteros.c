#include <stdio.h>

int main (){
				/*
					 int a,*p;
					 a =10;
					 p=&a;
					 printf("%d",*p);
				 */
				/*				int *p,*q;
									int x[100];

									for (int i =0 ; i<100;i++){

									x[i]=i;

									}

									p=&x[3];
									p++;
									printf("%d",*p);
				 */

				int n = 10, *p=NULL, *q =NULL,x[100];

				for (int i =0 ; i<100;i++){

								x[i]=i*2;

				}
				p=&x[11];
				q=&x[0];
/*
				if(q +n >  p){
								q+=n;
								printf("pase el primer if\n");
								printf("el valor de q es: %d el valor de p es: %d\n",*q,*p);
								printf("el vlaor memoria de q es : %d el valor memoria de p es: %d\n",q,p);
				}
*/
				q++;
				q++;
	
				if(q +n >  p){
								q+=n;
								printf("pase el segundo  if\n");
								printf("el valor de q es: %d el valor de p es: %d\n",*q,*p);
								printf("el vlaor memoria de q es : %d el valor memoria de p es: %d\n",q,p);
				}



}