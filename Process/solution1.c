#include <stdio.h>

int main ()
{
      FILE* file = fopen ("/proc/self/stat","r");
      if(file != NULL)
      {   
            int ppid;
            fscanf(file, "%*d %*s %*c %d", &ppid);
            printf("%d\n", ppid);
            fclose (file);
      }   
      return 0;
}
