/*
 * File: appointments.c
 * Description: This file contains functions related to scheduling appointments.
 *              It includes a function to schedule an appointment for a patient.
 *              Input validation is performed for patient ID, date of birth, and appointment time.
 *  after entering the details it will print in the .txt file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void scheduleAppointment(struct Appointment appointments[], int *appointmentCount) {
    // Declare a local variable of type Appointment to store information for the new appointment
    struct Appointment appointment;

    // Prompt the user to enter appointment details
    printf("Enter appointment details:\n");

    // Prompt the user to enter the patient ID for the appointment
    printf("Enter patient ID: ");
    scanf("%d", &appointment.patientId);

    // Open the file "patients.txt" for reading
    FILE *patientsFile = fopen("patients.txt", "r");
    if (patientsFile == NULL) {
        printf("Error opening patients file.\n");
        return;
    }

    // Check if the patient ID is present in the patients file
    int patientFound = 0;
    int id;
    char name[100], dob[20], gender;
    while (fscanf(patientsFile, "%d %s %s %c", &id, name, dob, &gender) != EOF) {
        if (id == appointment.patientId) {
            patientFound = 1;
            break;
        }
    }

    // Close the patients file
    fclose(patientsFile);

    // If patient ID not found, display an error message and return
    if (!patientFound) {
        printf("Patient ID not found. Please enter a valid patient ID.\n");
        return;
    }

    // Assign a unique ID to the appointment
    appointment.id = *appointmentCount + 1;
    // Prompt the user to choose the type of appointment
    printf("Choose the type of appointment:\n");
    printf("1. Optician\n");
    printf("2. Ophthalmologist\n");
    printf("3. Optometrist\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    // Set the type of appointment based on the user's choice
    switch (choice) {
        case 1:
            strcpy(appointment.type, "Optician");
            break;
        case 2:
            strcpy(appointment.type, "Ophthalmologist");
            break;
        case 3:
            strcpy(appointment.type, "Optometrist");
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    // Prompt the user to enter the appointment time
    printf("Time(9:00 to 5:00): ");
    scanf("%s", appointment.time);

    // Open the file "appointments.txt" for appending
    FILE *file = fopen("appointments.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Write appointment details to the file
    fprintf(file, "%d %s %s\n", appointment.patientId, appointment.time, appointment.type);

    // Close the file
    fclose(file);


    // Display a success message
    printf("Appointment scheduled successfully.\n");
}
