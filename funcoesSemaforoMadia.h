#include <sys/sem.h>

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

int alocaSem(key_t chave){
        return semget(chave, 1, IPC_CREAT|0666);
} 

int iniciaSem(int sem, int valor){
	return semctl(sem, 0, SETVAL, valor);
}

int verValorSem(int sem){
	return semctl(sem, 0, GETVAL, 0);
} 

int P(int sem){
        struct sembuf operacao;

        operacao.sem_num=0;  
        operacao.sem_op= -1;
        operacao.sem_flg=0;

	return semop(sem, &operacao, 1);
}

int V(int sem){
        struct sembuf operacao;

        operacao.sem_num=0;  
        operacao.sem_op= 1;
        operacao.sem_flg=0;

	return semop(sem, &operacao, 1);
}

int removeSem(int sem){
	semctl(sem, 0, IPC_RMID, 0);
}

#endif
