#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s{
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main(int argn,char **argv){
    int src;
    char *p;
    long conv = strtol(argv[1], &p, 10) - 1;
;
    
    Student *myStudent1;
    myStudent1 = (Student *)malloc(sizeof(Student));

    src = open("class.bin", O_RDWR);
    lseek(src, conv*sizeof(Student),SEEK_CUR);
    read(src, myStudent1, sizeof(Student));
    lseek(src, -sizeof(Student),SEEK_CUR);
    sprintf(myStudent1->lastName,"%s",argv[2]);
    write(src,myStudent1,sizeof(Student));
    close(src);
    free(myStudent1);
    return 0;
}