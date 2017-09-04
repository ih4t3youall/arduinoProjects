#include <stdio.h>

#define N_ELEMENTOS 'z' - 'a' +1

int main(){
				int c[N_ELEMENTOS];
				char car;

				for (car = 'a'; car <= 'z';car++){
								c[car - 'a'];
				}
				printf("introducir texto\n");
				printf("para temrminar eof\n");

				while ( (car = getchar()) != 'P'){

								if(car >= 'a'&& car <='z'){

												c[car - 'a']++;
								}

				}

				for (car = 'a'; car <='z';car++){
												printf("%3d",c[car - 'a']);
												putchar('\n');
												}
}