#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcoesSemaforoMadia.h"

int main(){
int carro, *carro1,*carro2, *carro3;
int id_mem_comum;

if ((id_mem_comum=shmget(300, 3* sizeof(int),0666)) ==-1) {
        perror("Erro no shmget") ;
        exit(0);
}

carro1 = shmat(id_mem_comum, 0, 0);
carro2 = shmat(id_mem_comum, 0, 0);
carro3 = shmat(id_mem_comum, 0, 0);

int sem = alocaSem(100);

printf("\nDigite o número do carro para treinar:");
scanf("%d", &carro);

P(sem);
if (carro== 1){
    if(*carro1 <=3){
        *carro1 = *carro1 +1;
        printf("\nCarro 1 entrou na pista: %d", carro1[0]);
        printf("\n\nPressione uma tecla para sair da pista.");
        //limpar buffer do teclado e espera user digitar tecla
        __fpurge(stdin); getchar();
        V(sem);
    }
    else{
        printf("\nCarro 1 entrou na pista mais de 3 vezes: ");
    }
    exit(0);
}
if (carro== 2){
    if(*carro2 <=3){
        *carro2 = *carro2 +1;
        printf("\nCarro 2 entrou na pista: %d", carro2[1]);
        printf("\n\nPressione uma tecla para sair da pista.");
        //limpar buffer do teclado e espera user digitar tecla
        __fpurge(stdin); getchar();
        V(sem);
    }
    else{
        printf("\nCarro 2 entrou na pista mais de 3 vezes: ");
    }
    exit(0);
}
if (carro== 3){
    if(*carro3 <=3){
        *carro3 = *carro1 +1;
        printf("\nCarro 3 entrou na pista: %d", carro3[2]);
        printf("\n\nPressione uma tecla para sair da pista.");
        //limpar buffer do teclado e espera user digitar tecla
        __fpurge(stdin); getchar();
        V(sem);
    }
    else{
        printf("\nCarro 3 entrou na pista mais de 3 vezes: ");
    }
    exit(0);
}

}


