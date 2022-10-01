#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoesSemaforoMadia.h"

int main(){
    	/* identificador dos carros na memória comum */
        int *carro1,*carro2, *carro3, id_mem_comum;

        /* identificador da inicialização do semáforo com valor 100*/
        int sem = alocaSem(100);

    	/* */
        if ((id_mem_comum=shmget(300, 3* sizeof(int), IPC_CREAT|IPC_EXCL|0666)) ==-1) {
            perror("Erro no shmget") ;
            exit(0);
        }
    
    	/* identificador dos carros na memória comum */
        carro1 = shmat(id_mem_comum, 0, 0);
        carro2 = shmat(id_mem_comum, 0, 0);
        carro3 = shmat(id_mem_comum, 0, 0);

}

