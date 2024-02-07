#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
void display(){
    FILE *file = fopen("appointments.txt", "r");
    if (file == NULL) {
        perror("Error opening file");

    }

    // Read and print each line of the file
    int patientId;
    char time[20], type[20];

    printf("Appointments:\n");
    while (fscanf(file, "%d %s %s", &patientId, time, type) != EOF) {
        printf("\nPatient ID: %d, Time: %s, Type: %s", patientId, time, type);
    }

    // Close the file
    fclose(file);

}
