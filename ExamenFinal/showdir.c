#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>


//DIR *opendir(const char *name);
//struct dirent *readdir(DIR *dirp);

int main(int argc, char *argv[]) {
    struct stat mystat, *sp = &mystat; 
    int r; 
    char *filename, path[1024], cwd[256]; 

    DIR *dir;
    struct dirent *dp;

    filename = "./"; 
    if (argc > 1) filename = argv[1]; 
    if ((r = lstat(filename, sp)) < 0){
        printf("no such file %s\n", filename); 
        exit(1);
    } 
    strcpy(path, filename);
    if (path[0] != '/'){ 
        getcwd(cwd, 256); 
        strcpy(path, cwd); 
        strcat(path, "/"); 
        strcat(path,filename); 
    } 
    if (S_ISDIR(sp->st_mode)){
        dir = opendir(path);
    
        printf("%s contiene:\n",path);
        while ((dp = readdir (dir)) != NULL) {
            printf("%s\n",dp->d_name);
        }
    }
}
