#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int inter1 = 0, inter2 = 0;
void handlerUsr1(int signalno)
{
	inter1++;
}
void handlerUsr2(int signalno)
{
	inter2++;
}

void handlerTerm(int signalno)
{
	printf("%d %d\n",inter1,inter2);
	exit(0);
}


int main()
{
	signal(SIGUSR1,handlerUsr1);
	signal(SIGUSR2,handlerUsr2);
	signal(SIGTERM,handlerTerm);
	while(1){
		usleep(50000);
	}

  return 0;
}
