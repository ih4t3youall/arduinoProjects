#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];

int cont=0;

void* doSomeThing(void *arg)
{
				unsigned long i = 0;
				pthread_t id = pthread_self();
				printf("entre a doSomething\n");
				while(cont < 10){
								printf("entre al while de something");
								printf("thread id:  %d\n",id);
//
								cont++;
								sleep(10);
				}
				return NULL;
}
void* doSomeThing2(){
				printf("entre a doSomething2\n");
				while(cont < 10){
								printf("entre al while de something2");
								printf("contador esta en %d\n",cont);
								sleep(5);
				}
}

int main(void)
{
				int i = 0;
				int err;

				err = pthread_create(&(tid[0]), NULL, &doSomeThing, NULL);
				err = pthread_create(&(tid[1]), NULL, &doSomeThing2, NULL);

				sleep(100);
				return 0;
}