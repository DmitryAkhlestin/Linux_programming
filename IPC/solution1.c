#include <stdio.h>


int main (int argc, char **argv)
{
	char cmd[255];
	sprintf(cmd, "%s %s", argv[1],argv[2]); 
	FILE* command = popen(cmd,"r");
	int num = 0;
	char symb = 0;
	while((symb = (char)fgetc(command))!= EOF) if(symb == '0')++num;
	
	printf("%d\n",num);
	pclose(command);
	return 0;
}
