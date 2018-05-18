#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define HILOSM 15

void *funcion(void*);

int main(int argc, char *argv[]) {
	pthread_t arregloHilos[HILOSM];

	for (int i = 0; i < HILOSM; i++) {
		pthread_create(&arregloHilos[i], NULL, funcion, NULL);
	}

	for(int i=0; i< HILOSM; i++){
		pthread_join(arregloHilos[i], NULL);
	}
}

void *funcion(void *arg) {
	printf("Hola %u\n", pthread_self());
	return NULL;
}
