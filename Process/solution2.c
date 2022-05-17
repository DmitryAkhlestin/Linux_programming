#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

int main() {
	char *buff;
	DIR *dir = opendir("/proc/");
	struct dirent *entry;
	int cnt = 0;

	while (entry = readdir(dir))
		if (isdigit(*entry->d_name)) {
			sprintf(buff, "/proc/%s/comm", entry->d_name);
			
			FILE *fp = fopen(buff, "r");
			fscanf(fp, "%s", buff);

			cnt += !(strcmp(buff, "genenv"));
			
			fclose(fp);
		}
	
	printf("%d\n", cnt);

	return closedir(dir) & 0;
}
