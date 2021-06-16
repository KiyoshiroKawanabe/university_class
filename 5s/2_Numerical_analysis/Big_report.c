#include <stdio.h>
//#include <stdlib.h>
#include <dirent.h>
//#include <errno.h>
#include <string.h>

int main(int argc, char *city011[])
{
    DIR *dp;
    struct dirent *dirp;

/*    if (argc != 2) {
        fprintf(stderr, "Usage: ./program directory_name\n");
        exit(EXIT_FAILURE);
    }
*/
    dp = opendir(city011[1]);

    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);
    return 0;
}