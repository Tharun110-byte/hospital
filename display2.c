#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
void display2(){
    FILE *file = fopen("patients.txt", "r");
    if (file == NULL) {
        perror("Error opening file");

    }

    // Read and print each line of the file
    int Id;
  char name[100], dob[12], gender;

    printf("Appointments:\n");
    printf("patient ID    name   dob      gender\n");
    while (fscanf(file, "%d %s %s %c", &Id, name, dob, &gender) != EOF) {

        printf("%d,   %s,  %s,   %c\n", Id, name, dob, gender);
    }

    // Close the file
    fclose(file);

}
