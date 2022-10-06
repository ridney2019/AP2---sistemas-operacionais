#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoesSemaforoMadia.h"

int main(){
    	/* identificador dos carros na memória comum */
        int id_mem_comum;

        /* identificador da inicialização do semáforo com valor 100*/
        int sem = alocaSem(100);

       if (iniciaSem(sem, 1) == -1) {
        perror("Erro ao inicializar semáforo - ");
        exit(0);
        }

    	/* */
        if ((id_mem_comum=shmget(300, 3*sizeof(int), IPC_CREAT|IPC_EXCL|0666)) ==-1) {
            perror("Erro no shmget");
            exit(0);
        }
    }