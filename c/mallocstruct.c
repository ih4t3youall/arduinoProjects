#include <stdio.h>
#include <stdlib.h>


struct martin{

int numero;
int numero2;

};

struct martin *mor;


int main(){

struct martin *mar = malloc(sizeof(struct martin));
mor = malloc(sizeof(struct martin));
mar->numero =4;
mor->numero=5;
printf("%d\n",mar->numero);
printf("%d\n",mor->numero);
}
