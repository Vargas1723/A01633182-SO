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
    printf("My student is: %d, %d, %s, %s",myStudent1->id,myStudent1->semester,myStudent1->firstName,myStudent1->lastName);
    close(src);
    free(myStudent1);
    return 0;
}