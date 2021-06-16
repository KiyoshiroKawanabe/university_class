#include <stdio.h>
#include <stdlib.h>

#define N 200

int main(void){

    FILE *fp;
    int i=9;
    char str[N];
    char filename[100];
    sprintf(filename, "city011/city011_%03d.txt", i);
    fp=fopen(filename, "r");
    if(fp == NULL) {
		printf("%s file not open!\n", filename);
		return -1;
	}

	while(fgets(str, N, fp) != NULL) {
		printf("%s", str);
	}

    fclose(fp);
    return 0;
}