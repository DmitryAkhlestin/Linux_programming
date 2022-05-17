#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
int main(int argc, char **argv)
{	
	int i =0;
	key_t key1 = atoi(argv[1]);
	int id1 = shmget(key1, 1000, 0666);
	int* reg1 = shmat(id1, NULL, 0);
	
	key_t key2 = atoi(argv[2]);
	int id2 = shmget(key2, 1000, 0666);
	int* reg2 = shmat(id2, NULL, 0);
	
	
	key_t key_res = ftok(argv[0], 0);
	int id_res = shmget(key_res, 1000, 0666|IPC_CREAT);
	int* reg_res = shmat(id_res, NULL, 0);
	
	for(i =0;i <100;i++){reg_res[i] = reg1[i]+reg2[i];}
	printf("%d\n",key_res);
return 0;
}
