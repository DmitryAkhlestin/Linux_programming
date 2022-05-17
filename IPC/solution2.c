#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int read_and_report(int fd)
{
  char buf[2];
  int bytes = read(fd, buf, 2);
  if (bytes == 0) return -1;
  return atoi(buf);
}

int main()
{
  fd_set read_set;
  int sum = 0;
  int open_flags = O_NONBLOCK | O_RDONLY;
  int f1 = open ("./in1", open_flags);
  int f2 = open ("./in2", open_flags);

  if (!(f1 && f2) ) 
  {
    printf ("Error with opening pipes\n");
    return 0;
  }

  while(1)
  {
    FD_ZERO(&read_set);
    FD_SET(f1, &read_set);
    FD_SET(f2, &read_set);
    int result = select(f2+1, &read_set, NULL, NULL, NULL);
    int digit = 0;
    if(result)
    {
      if( FD_ISSET(f1, &read_set) ){
	if ((digit = read_and_report(f1)) != -1) sum+=digit; else break;}
      if( FD_ISSET(f2, &read_set) ){
	if ((digit = read_and_report(f2)) != -1) sum+=digit; else break;}
    }
  }
  
  printf("%d\n",sum);
  return 0;
}
