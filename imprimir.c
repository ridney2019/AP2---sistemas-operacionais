#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoesSemaforoMadia.h"
int main(){
	int *num, id_mem;  /* identificador da memória comum */

	 //Se liga a uma área de memória compartilhada existente
	 if ((id_mem = shmget(456, 3*sizeof(int), 0666)) == -1) {
		  perror("Erro no shmget") ;
		  exit(0) ;
	 }
	 // acoplamento do processo a zona de memória 
	 num = shmat(id_mem, 0, 0);
	 int sem = alocaSem(100);

	P(sem); 
    printf("Treinos Carro 1: %d\n",*(num)); //p[1]
    printf("Treinos Carro 2: %d\n",*(num + 1)); //p[1]
    printf("Treinos Carro 3: %d\n",*(num + 2)); //p[1]
    V(sem);
}