#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoesSemaforoMadia.h"

int main(){
int carro, *carros;
int  id_mem_comum;

if ((id_mem_comum=shmget(300, 3*sizeof(int),0666)) ==-1) {
        perror("Erro no shmget") ;
        exit(0);
}

int sem = alocaSem(100);

carros = shmat(id_mem_comum, 0, 0);




printf("\nDigite o número do carro para treinar:");
scanf("%d", &carro);

P(sem);
if (carro == 1){
        carros[0] = carros[0] +1;
        printf("\nCarro 1 entrou na pista: %d", carros[0]);
        printf("\n\nPressione uma tecla para sair da pista.");
        //limpar buffer do teclado e espera user digitar tecla
        __fpurge(stdin); getchar();
        V(sem);
        exit(0);
}
if (carro == 2){
        carros[1] = carros[1] +1;
        printf("\nCarro 2 entrou na pista: %d", carros[1]);
        printf("\n\nPressione uma tecla para sair da pista.");
        //limpar buffer do teclado e espera user digitar tecla
        __fpurge(stdin); getchar();
        V(sem);
        exit(0);
}
if (carro == 3){
        carros[2] = carros[2] +1;
        printf("\nCarro 3 entrou na pista: %d", carros[2]);
        printf("\n\nPressione uma tecla para sair da pista.");
        //limpar buffer do teclado e espera user digitar tecla
        __fpurge(stdin); getchar();
        V(sem);
    exit(0);
}

}


