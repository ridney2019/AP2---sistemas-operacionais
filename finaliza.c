#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoesSemaforoMadia.h"

int main(){
 
 int id_mem;

  if ((id_mem = shmget(456, 3*sizeof(int), 0666)) == -1) {
		  perror("Erro no shmget") ;
		  exit(0) ;
	 }

    int sem = alocaSem(100);
    removeSem(sem);
   	shmctl(id_mem, IPC_RMID, NULL);
}