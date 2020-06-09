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
int aleatorio_en_rango(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
int main(){
    int destination;
    int n;
    Student *myStudent1;
    myStudent1 = (Student *)malloc(sizeof(Student));
    char ch_arrNames[10][10] = {
                             "Braulio",
                             "Jhonatan",
                             "Alberto",
                             "Santiago",
                             "Rodrigo",
                             "Joaquin",
                             "Eduardo",
                             "Ernesto",
                             "Alfredo",
                             "Juan Pedro",
                         };
    char ch_arrLastName[10][10] = {
                             "Perez",
                             "Vargas",
                             "Arellano",
                             "Atilano",
                             "Gonzales",
                             "Estrada",
                             "Minakata",
                             "Velasco",
                             "Preciado",
                             "Serratos",
                         };


    if ((destination=creat("class.bin", 0600)) < 0) {
        perror("Error creating destination file");
        exit(2);
    } 
    for(int i = 0 ; i < 10; i++){
        myStudent1->id = aleatorio_en_rango(1,10);
        myStudent1->semester = aleatorio_en_rango(1,10);
    
        sprintf(myStudent1->firstName,"%s",*(ch_arrNames+aleatorio_en_rango(0,9)));
        sprintf(myStudent1->lastName,"%s",*(ch_arrLastName+aleatorio_en_rango(0,9)));
        if ((n=write(destination, myStudent1, sizeof(Student)) < 0)) {
            perror("Error writing destination file");
            exit(4);
        }
    }    
    close(destination);
    free(myStudent1);
    return 0;
}