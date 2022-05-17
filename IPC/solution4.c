#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>
#include <signal.h>
void h1(int signalno)
{
	exit(0);
}
int main(void)
{
	pid_t pid;
	int i;
	/* creating new process */
	pid = fork ();
	if (pid == -1)
		return -1;
	else if (pid != 0)
		exit (EXIT_SUCCESS);
		
	/*creating new session and process groups*/
        int sid = setsid();
        if(sid < 0)
             return 1;
		
	/* setting working directory - root folder / */
	if (chdir ("/") == -1)
		return -1;
		
	printf("%d\n",sid);	
	/* closing all open files */
	/* NR_OPEN is more than needed */
	for(i = getdtablesize() - 1; i >= 0; i--)
                close(i);
		
            open("/dev/null", O_RDONLY); //stdin
            open("/dev/null", O_WRONLY); //stdout
            dup(1); //stderr
	signal(SIGURG,h1);
	sleep(60);
	return 0;
}
