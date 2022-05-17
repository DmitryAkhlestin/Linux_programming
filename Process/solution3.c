#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void get_ppid(pid_t pid){
      char tmp[255] = {0};
      sprintf(tmp, "/proc/%d/stat",pid);
      
      FILE* file = fopen (tmp,"r");
      if(file != NULL)
      {   
      	    
            int ppid;
            fscanf(file, "%*d %*s %*c %d", &ppid);
	    printf("%d\n",ppid);
	    if(ppid != 1) get_ppid(ppid);
    
            fclose (file);
      }

}

int main (int argc,char **argv)
{	
      pid_t pid = atoi(argv[1]);
      printf("%d\n",pid);
      get_ppid(pid);
      return 0;
}

