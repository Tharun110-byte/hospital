/*
* File: add.c
* The code is about adding the patient details
* In this we are adding the patient details which uses a function.
* In this code we are adding patient name,Date of Birth,gender.
* And this details will be printed in the .txt file,with the help of files concept.

*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
// Function to get the maximum ID from existing patient data in the file
int getMaxID() {
    FILE *file = fopen("patients.txt", "r");
    int maxID = 0;
    if (file != NULL) {
        int id;
        char name[100], dob[12], gender;
        while (fscanf(file, "%d %s %s %c", &id, name, dob, &gender) != EOF) {
            if (id > maxID) {
                maxID = id;
            }
        }
        fclose(file);
    } else {
        printf("Unable to open file for reading patient data.\n");
    }
    return maxID;
}

void addPatient(struct Patient patients[], int *patientCount) {
    // Declare a local variable of type Patient to store information for the new patient
    struct Patient patient;
     // Get the maximum ID from existing patient data
    int maxID = getMaxID();

    // Assign a unique ID to the patient
    patient.id = maxID + 1;

    // Prompt the user to enter patient details
    printf("Enter patient details:\n");

    // Use a label to allow for re-entering the name in case of invalid characters

    while (1) {
            label1:
        // Prompt the user to enter the patient's name
        printf("Name: ");
        scanf(" %[^\n]", patient.name);

        // Validate the characters in the name
        int i = 0;
        while (patient.name[i] != '\0') {
            if ((patient.name[i] >= 97 && patient.name[i] <= 122) || (patient.name[i] >= 65 && patient.name[i] <= 90) || patient.name[i] == '.') {
                i++;
            } else {
                printf("Enter valid characters for the name.\n");
                break;
            }

        }

        // If invalid characters are found, re-enter the name
        if (patient.name[i] != '\0')
            goto label1;

        // Break out of the loop if the name is valid
        break;
    }

    // Use a loop to prompt the user for a valid date of birth format
    while (1) {
        // Prompt the user to enter the date of birth
        printf("Date of Birth (YYYY-MM-DD): ");
        scanf("%s", patient.dob);

        // Validate the format of the date of birth
        if (strlen(patient.dob) == 10 &&
            patient.dob[4] == '-' && patient.dob[7] == '-' &&
            isdigit(patient.dob[0]) && isdigit(patient.dob[1]) &&
            isdigit(patient.dob[2]) && isdigit(patient.dob[3]) &&
            isdigit(patient.dob[5]) && isdigit(patient.dob[6]) &&
            isdigit(patient.dob[8]) && isdigit(patient.dob[9]) &&
            (patient.dob[5] == '0' || patient.dob[5] == '1') && // Check for valid month
            ((patient.dob[5] == '0' && patient.dob[6] >= '1' && patient.dob[6] <= '9') ||
             (patient.dob[5] == '1' && patient.dob[6] >= '0' && patient.dob[6] <= '2')) && // Check for valid day
            (patient.dob[8] >= '0' && patient.dob[8] <= '3') && // Check for valid year (decade)
            (patient.dob[9] >= '0' && patient.dob[9] <= '9')) { // Check for valid year (unit)
            break; // Exit the loop if the input is valid
        } else {
            printf("Invalid date of birth format or values. Please enter in YYYY-MM-DD format with valid month and day.\n");
        }
    }

    // Use a loop to prompt the user for a valid gender
    while (1) {
        // Prompt the user to enter the gender
        printf("Gender: Please enter 'm' or 'f'\n");
        scanf(" %c", &patient.gender); // Use %c for a single character

        // Validate the gender input
        if (patient.gender == 'm' || patient.gender == 'f') {
            break; // Exit the loop if input is valid
        } else {
            printf("Invalid gender. Please enter 'm' or 'f'.\n");
        }
    }

    // Display the entered patient details
    printf("Entered patient details\n");
    printf("ID    : %d\nName  : %s\nDOB   : %s\nGender: %c\n", patient.id, patient.name, patient.dob, patient.gender);

    // Open the file "patients.txt" for appending
    FILE *file = fopen("patients.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write patient details to the file
    fprintf(file, "%d %s %s %c\n", patient.id, patient.name, patient.dob, patient.gender);

    // Close the file
    fclose(file);

    // Display a success message
    printf("Patient added successfully.\n");
}

